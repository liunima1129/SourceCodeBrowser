#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "../FileSystem/FileSystem.h"
#include "../fileDisplay/process.h"

void fileOpen(std::vector<std::string> files, std::string outpath);
void endDisplay();

//----< Display the converted html file in the explorer >-----
void fileOpen(std::vector<std::string> files, std::string outpath)
{
	Process p;
	std::string appPath = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe";
	p.application(appPath);
	std::cout << "\n Press key to start";
	_getche();
	for (auto f : files)
	{
		std::string repath = outpath + "\\" + f + ".html";
		std::string abpath = FileSystem::Path::getFullFileSpec(repath);
		std::string cmdLine = "/A " + abpath;
		p.commandLine(cmdLine);
		std::cout << "\n  starting process: \"" << appPath << "\"";
		std::cout << "\n  with this cmdlne: \"" << cmdLine << "\"";
		p.create();
		CBP callback = []() { std::cout << "\n  --- child process exited with this message ---"; };
		p.setCallBackProcessing(callback);
		p.registerCallback();
		WaitForSingleObject(p.getProcessHandle(), INFINITE);
	}
}

//----< End display process >-----
void endDisplay()
{
	std::cout << "\n  after OnExit";
	std::cout.flush();
	char ch;
	std::cin.read(&ch, 1);
}