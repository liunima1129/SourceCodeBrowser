#pragma once
////////////////////////////////////////////////////////////////////////////
// Display.h - display converted html files in the default browser		  //
// ver 1.1                                                                //
// Language:    C++, Visual Studio 2017                                   //
// Application: Most Projects, CSE687 - Object Oriented Design            //
// Author:      Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019   //
////////////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package provides functions:
* - display(std::vector<std::string> regexfiles)    Display the converted html file in the browser
* - endDisplay()								    End display process
*
* Build Process:
* --------------
* Required Files:
*   Display.h, process.h, FileSystem.h
*
* Maintenance History:
* --------------------
* ver 1.1 : 30 Jan 2019
* - added endDisplay() function
* ver 1.0 : 29 Jan 2019
* - first release
*
*/
#include <iostream>
#include <conio.h>
#include "../Test/process.h"
#include <string>
#include "../Test/FileSystem.h"


void display(std::vector<std::string> regexfiles);
void endDisplay();

//----< Display the converted html file in the explorer >-----
void display(std::vector<std::string> regexfiles)
{
	Process p;
	std::string appPath = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe";
	p.application(appPath);
	std::cout << "\n Press key to start";
	_getche();
	for (auto f : regexfiles)
	{
		std::string repath = "../convertedPages/" + f + ".html";
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

//for (auto f : files)
//{
//    std::cout << f << std::endl;
//}
//Process p;
//std::string appPath = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe";
//p.application(appPath);
//std::cout << "\n Press key to start";
//_getche();
//for (auto f : regexFiles)
//{
//    std::string repath = "../convertedPages/" + f + ".html";
//    std::string abpath = FileSystem::Path::getFullFileSpec(repath);
//    std::string cmdLine = "/A " + abpath;
//    p.commandLine(cmdLine);
//    std::cout << "\n  starting process: \"" << appPath << "\"";
//    std::cout << "\n  with this cmdlne: \"" << cmdLine << "\"";
//    p.create();
//    CBP callback = []() { std::cout << "\n  --- child process exited with this message ---"; };
//    p.setCallBackProcessing(callback);
//    p.registerCallback();
//    WaitForSingleObject(p.getProcessHandle(), INFINITE);
//}

//for (auto r : pcl.regexes())
//{
//	if (std::regex_match(f, std::regex(r)))
//	{
//    std::ofstream fout;
//    fout.open("../convertedPages/" + f);
//    fout << convertH(content) << std::endl;
//    fout.close();
//	}
//}