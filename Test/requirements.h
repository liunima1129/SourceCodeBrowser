#pragma once
////////////////////////////////////////////////////////////////////////////
// requirements.h - print requirement demonstrations on the console       //
// ver 1.0                                                                //
// Language:    C++, Visual Studio 2017                                   //
// Application: Most Projects, CSE687 - Object Oriented Design            //
// Author:      Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019   //
////////////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package provides functions:
* - showRequirements_1_4(std::vector<std::string> regexfile)    Display the requirement 1-4 demonstrations on the console
* - showRequirements_5_6()										Display the requirement 5, 6 demonstrations on the console
* - showRequirements_7()										Display the requirement 7 demonstration on the console
*
* Build Process:
* --------------
* Required Files:
*   requirements.h
*   execution.cpp
*
* Maintenance History:
* --------------------
* ver 1.0 : 6 Feb 2019
* - first release
*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void showRequirements_1_4(std::vector<std::string> regexfile);
void showRequirements_5_6();
void showRequirements_7();

//	<----  Display the requirement 1-4 demonstrations on the console  ---->
void showRequirements_1_4(std::vector<std::string> regexfile)
{
	std::cout << "\n ======================================" << "\n Requirement 1 demonstration: \n" << "Using Visual Studio 2017 to finish this project." << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 2 demonstration: \n" << "This project uses standard streams libraries for all I/O and operators new and delete for memory management." << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 3 demonstration: \n" << "This project includes 5 packages:convertHtml, DirExplorer, Display, Utilities, Test. \n";
	std::cout << "	-- convertHtml: convertHtml.h, convertHtmlTest.cpp" << std::endl;
	std::cout << "	-- DirExplorer: DirExplorer.h, DirExplorerTest.cpp, FileSystem.cpp" << std::endl;
	std::cout << "	-- Display: Display.h, DisplayTest.cpp" << std::endl;
	std::cout << "	-- Utilities: codeUtilities.h, StringUtilitis.cpp" << std::endl;
	std::cout << "	-- Test: FileSystem.h, process.h, requirements.h, execution.cpp, FileSystem.cpp";
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 4 demonstration: \n" << "Accept, from the command line, a path that specifies where file(s) to be analyzed are found, and a regular expression used to select filenames to process." << std::endl;
	std::cout << "	-- Command line: " << "..\\Test\\ [HELLOWORLD2019]" << std::endl;
	std::cout << "			 ..\\Test\\ [a-tA-Z]*\\.[h]" << std::endl;
	std::cout << "	-- Files selected by regexes:" << std::endl;
	for (auto f : regexfile) {
		std::cout << "		++ " << f << std::endl;
	}
}
//	<----  Display the requirement 5, 6 demonstrations on the console  ---->
void showRequirements_5_6()
{
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 5 and requirement 6 demonstration: \n";
	std::cout << "\n The program will automatically run twice. First time will not find any file which meets the regexes, and second time will find some files which meets the regex conditions. \n";
}

//	<----  Display the requirement 7 demonstration on the console  ---->
void showRequirements_7()
{
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 7 demonstration: \n" << "Display, in a child process using the default browser, each converted file, waiting for the child to exit before displaying the next file. \n";
}