#pragma once
////////////////////////////////////////////////////////////////////////////
// dependency.h - class used to find dependencies of found files		  //
// ver 1.1                                                                //
// Language:    C++, Visual Studio 2017                                   //
// Application: Most Projects, CSE687 - Object Oriented Design            //
// Author:      Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019   //
////////////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package provides functions:
* - findDenpendency(const std::string& files)				Replace all the specific substring of a given string
* - NodeTraverse(element* pItem, std::string filename)		Convert given content into the form of Html file
* - setTree(std::vector<std::string> fileTree)				Set a tree of whole dependency files
* - treeTraverse(const std::string& root)					Traverse a file and its dependency files
* - getTable()												Return the value of countTable
*
* Build Process:
* --------------
* Required Files:
*  AbstrSynTree.h
*  Parser.h
*  FileSystem.h
*  Utilities.h
*  ITokenCollection.h
*  ConfigureParser.h
*  display.h
*  countTable.h
* Maintenance History:
* --------------------
* ver 1.1 : 6 Mar 2019
* - add countTable operation 
* ver 1.0 : 28 Feb 2019
* - first release
*
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "../AbstractSyntaxTree/AbstrSynTree.h"
#include "../Parser/Parser.h"
#include "../FileSystem/FileSystem.h"
#include "../Utilities/Utilities.h"
#include "../SemiExpression/ITokenCollection.h"
#include "../Parser/ConfigureParser.h"
#include "../Display/display.h"
#include "../countTable/countTable.h"

std::vector<std::string> includeFiles(std::string rootpath, std::vector<std::string> statement);

class Dependency
{
public:
	std::pair<std::vector<std::string>, countTable> findDenpendency(const std::string& files);
	template<typename element>
	countTable NodeTraverse(element* pItem, std::string filename);
	void setTree(std::vector<std::string> fileTree, std::string outpath_);
	void treeTraverse(const std::string& root, std::string outpath_);
	countTable getTable();
private:
	std::vector<std::string> _dependencyTree;
	countTable tb_;
};

