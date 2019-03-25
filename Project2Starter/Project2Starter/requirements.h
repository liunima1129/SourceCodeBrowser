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
* - showRequirements_1_4()    Display the requirement 1-4 demonstrations on the console
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
* ver 1.0 : 10 Mar 2019
* - first release
*
*/

#include <iostream>
#include <string>
#include <vector>

//	<----  Display the requirement 1-4 demonstrations on the console  ---->
void showRequirements_1_4()
{
	std::cout << "\n ======================================" << "\n Requirement 1 demonstration: \n" << "Using Visual Studio 2017 to finish this project." << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 2 demonstration: \n" << "This project uses standard streams libraries for all I/O and operators new and delete for memory management." << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 3 demonstration: \n" << "This project uses an Executive package, Project2Starter, that accepts, from its command line, a path containing files to be converted. \n";
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 4 demonstration: \n" << "This project provides Loader, Converter, Dependencies, and Display packages." << std::endl;
	std::cout << "	-- Loader(DirExplorer): DirExplorer.h, dirExplorerTest.cpp" << std::endl;
	std::cout << "	-- Converter: htmlConverter.h, ConverterTest.cpp" << std::endl;
	std::cout << "	-- Utilities: codeUtilities.h, StringUtilitis.cpp" << std::endl;
	std::cout << "	-- Dependency: dependency.h, dependency.cpp, dependenciesTest.cpp";
}

//	<----  Display the requirement 5 demonstrations on the console  ---->
void showRequirements_5(std::vector<std::string> regex_files)
{
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 5 and requirement 6 demonstration: \n";
	for (auto f : regex_files) {
		std::cout << f << std::endl;
	}
}

//	<----  Display the requirement 6 demonstrations on the console  ---->
void showRequirements_6_8()
{
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 6 demonstration: \n" << "Package Converter provides functions to add html file headers and character transform: \n";
	std::cout << "  -- replaceAll(std::string str, std::string from, std::string to)    Replace all the specific substring of a given string" << std::endl;
	std::cout << "	-- convertH(std::string content, std::string filename)			    Convert given content into the form of Html file" << std::endl;
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 7 demonstration: \n" << "Package Dependency provides functions to support insertion, in each analyzed file, links to all the files in the directory tree, on which it depends:" << std::endl;
	std::cout << "  -- findDenpendency(const std::string& files)				        Replace all the specific substring of a given string" << std::endl;
	std::cout << "	-- setTree(std::vector<std::string> fileTree)				        Set a tree of whole dependency files" << std::endl;
	std::cout << "  -- treeTraverse(const std::string& root)				        	Traverse a file and its dependency files" << std::endl;
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 8 demonstration: \n" << "Package Display provides functions to support wrapping selected parts of the web page in <div> blocks that can be displayed or hidden:" << std::endl;
	std::cout << "  -- addComm_(std::vector<std::string> _file)				        	                                Add comment part show/hide button" << std::endl;
	std::cout << "  -- addFunc_2_(std::vector<std::string> _fileF, std::vector<std::pair<size_t, size_t>> _funcL)		Add function part show/hide button" << std::endl;
	std::cout << "  -- addClass_2_(std::vector<std::string> _fileC, std::vector<std::pair<size_t, size_t>> _classL)	    Add class part show/hide button" << std::endl;
	std::cout << "\n ======================================" << std::endl;
}