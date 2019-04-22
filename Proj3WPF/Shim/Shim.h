#pragma once
//////////////////////////////////////////////////////////////////////////
// Shim.h															    //
// ver 1.0															    //
// Language:    C++, Visual Studio 2017                                 //
// Application: Most Projects, CSE687 - Object Oriented Design          //
// Author:      Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019 //
//////////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * --------------------------------------------------------------------
 * This package defines Shim class which can be used by .NET applications.
 * In this demo, Shim is used in WPF project to allow WPF calling functions
 * of C++ class CodePublisher. The Shim is a translator to translate C#
 * input to C++ format and send the input to CodePublisher.
 *
 * Required Files:
 * --------------------------------------------------------------------
 * Shim.h  
 * Shim.cpp
 * ICodePublisher.h
 *
 * Maintenance History:
 * ver 1.0 : 10 Apr 2019
 * - first release
 * 
 */

#include "../CodePublisher/ICodePublisher.h"
#include <string>
#include <vector>

using namespace System;
using namespace System::Collections::Generic;

public ref class Shim
{
public:
	Shim();
	//destructor
	~Shim();
	
	//Initialize cmd line
	void Init(List<System::String^> ^args);
	//Find Dependencies and convert
	void treeSet(String^ outpath);
	//Get file name
	List<String^>^ getname();
	//Get file path
	List<String^>^ getpath();
	//Automatically display
	void publisher(String^ outpath);
	//Show Requirements on the console
	void requires();

private:
	//Convert standard string to system string
	String^ stdStrtoSysStr(const std::string& str_);
	//Convert system string to standard string
	std::string sysStrtoStdStr(String^ str_);
	ICodePublisher* client;
	List<String^>^ Filenames;
	List<String^>^ Filepaths;
};