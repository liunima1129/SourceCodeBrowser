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
* - showRequirements_5()	  Display the requirement 5 demonstrations on the console
* - showRequirements_6_7()	  Display the requirement 6-7 demonstration on the console
*
* Build Process:
* --------------
* Required Files:
*   requirements.h
*   MainWindow.xaml.cs
*   Shim.h, Shim.cpp
*
* Maintenance History:
* --------------------
* ver 1.0 : 18 Apr 2019
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
	std::cout << "\n Requirement 2 demonstration: \n" << "This project uses Windows Presentation Foundation (WPF) and C# to implement the Client GUI." << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 3 demonstration: \n" << "This project provides an interface for the Code Publisher developed in Project #2, that declares methods to access all of the Publisher's facilities, and provides an object factory that returns a pointer to the interface. \n";
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 4 demonstration: \n" << "This project builds the Publisher as a dynamic link library that exposes its interface and object factory." << std::endl;
	std::cout << "	-- Shim: Shim.h, Shim.cpp";
}

//	<----  Display the requirement 5 demonstrations on the console  ---->
void showRequirements_5()
{
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 5 demonstration: \n";
	std::cout << "This project provides a C++\\CLI translater that delegates calls from the Client GUI into the publisher's methods, as declared in its interface." << std::endl;
	std::cout << "	-- CodePublisher: ICodePublisher.h, CodePublisher.cpp";
}

//	<----  Display the requirement 6-7 demonstrations on the console  ---->
void showRequirements_6_7()
{
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 6 demonstration: \n" << "This project provides a Client package that implements a WPF GUI with a least two views, one for navigation, and one to display file conversion results, as described in the purpose section. \n";
	std::cout << "\n ======================================" << std::endl;
	std::cout << "\n Requirement 7 demonstration: \n" << " This project include an automated test that accepts the path to your project directory" << std::endl;
	std::cout << " on its command line, invokes the Code Publisher, through its interface, to convert all the" << std::endl;
	std::cout << " project files matching a pattern that accepts *.h and *.cpp files, and then opens the Client" << std::endl;
	std::cout << " GUI's Display view." << std::endl;
	std::cout << "  -- To Start the automated test, click \"Publish\" button;" << std::endl;
	std::cout << "  -- To Open the converted files, click \"Converted Files\" tab and double click items in the Listbox." << std::endl;
	std::cout << "\n ======================================" << std::endl;
}