#pragma once
//////////////////////////////////////////////////////////////////////////
// CodePublisher.h														//
// ver 1.0																//
// Language:    C++, Visual Studio 2017                                 //
// Application: Most Projects, CSE687 - Object Oriented Design          //
// Author:      Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019 //
//////////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * --------------------------------------------------------------------
 * This package act as an interface of code publisher. It wrap all the
 * functions of code publisher in a class drived from a virtual base
 * class.
 *
 * Required Files:
 * --------------------------------------------------------------------
 * ICodePublisher.h		interface for shim
 *
 * Maintenance History:
 * --------------------------------------------------------------------
 * ver 1.0 : 09 April 2019
 * - First Release
 */

#ifdef IN_DLL
#define DLL_DECL __declspec(dllexport)
#else
#define DLL_DECL __declspec(dllimport)
#endif

#include <iostream>
#include <string>
#include <vector>
#include <queue>

class ICodePublisher
{
public:
	//Initialize cmd line
	virtual void Init_(int argc, char *argv[]) = 0;
	//Get file path
	virtual std::vector<std::string> getfilepath_() = 0;
	//Get file name
	virtual std::vector<std::string> getfilename_() = 0;
	//Traverse and convert files
	virtual void treeSet_(std::string outpath_) = 0;
	//Automatically display
	virtual void publisher(std::string outpath_) = 0;
	//Show requirements on the console
	virtual void requires_() = 0;
	//Destructor
	virtual ~ICodePublisher() {};
};

 // you can remove the | extern "C" | wrapper if you wish
extern "C" {
	// Instantiates CppClass* as ICppClass*
	struct ObjectFactory {
		// See CppLibrary.cpp for implementation
		DLL_DECL ICodePublisher* createClient();
	};
}