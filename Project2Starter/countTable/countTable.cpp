/////////////////////////////////////////////////////////////////////////////
// countTable.cpp - Support file and directory operations                  //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright Yuhan Liu, 2019	                                           //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017                             //
// Platform:    Lenovo Y50-70, Core i7, Windows 10	                       //
// Application: CSE 687 Spring Projects, 2019                              //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////
#include "../countTable/countTable.h"

countTable::_table countTable::getclassTable()
{
	return classTable;
}

countTable::_table countTable::getfuncTable()
{
	return funcTable;
}

void countTable::setclassTable(_table input_)
{
	classTable = input_;
}

void countTable::setfuncTable(_table input_)
{
	funcTable = input_;
}

void countTable::insertclassTable(std::string filename, std::pair<size_t, size_t> pair_)
{
	if (classTable.count(filename) != 0)
	{
		classTable[filename].push_back(pair_);
		return;
	}
	std::vector<std::pair<size_t, size_t>> initial_;
	initial_.push_back(pair_);
	classTable.insert(std::make_pair(filename, initial_));
}

void countTable::insertfuncTable(std::string filename, std::pair<size_t, size_t> pair_)
{
	if (funcTable.count(filename) != 0)
	{
		funcTable[filename].push_back(pair_);
		return;
	}
	std::vector<std::pair<size_t, size_t>> initial_;
	initial_.push_back(pair_);
	funcTable.insert(std::make_pair(filename, initial_));
}
