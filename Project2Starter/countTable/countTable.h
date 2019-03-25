#pragma once
////////////////////////////////////////////////////////////////////////////
// countTable.h - class used to store numbers of lines of functions,	  //
//				  classes, and comments									  //
// ver 1.0                                                                //
// Language:    C++, Visual Studio 2017                                   //
// Application: Most Projects, CSE687 - Object Oriented Design            //
// Author:      Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019   //
////////////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package provides functions:
* - getclassTable()																Return the value of classTable
* - getfuncTable()																Return the value of funcTable
* - insertclassTable(std::string filename, std::pair<size_t, size_t> pair_)		Insert a new value in classTable
* - insertfuncTable(std::string filename, std::pair<size_t, size_t> pair_)		Insert a new value in funcTable
* - setclassTable(_table input_)												Set the value of classTable
* - setfuncTable(_table input_)													Set the value of funcTable
*
* Build Process:
* --------------
* Required Files:
*  countTable.h
*
* Maintenance History:
* --------------------
* ver 1.0 : 5 Mar 2019
* - first release
*
*/
#include <iostream>
#include <unordered_map>

class countTable {
public:
	using _table = std::unordered_map<std::string, std::vector<std::pair<size_t, size_t>>>;
	_table getclassTable();
	_table getfuncTable();
	void insertclassTable(std::string filename, std::pair<size_t, size_t> pair_);
	void insertfuncTable(std::string filename, std::pair<size_t, size_t> pair_);
	void setclassTable(_table input_);
	void setfuncTable(_table input_);
private:
	_table classTable;
	_table funcTable;
};