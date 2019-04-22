#pragma once
////////////////////////////////////////////////////////////////////////////////
// display.h - class used to add show/hide buttons in the converted webpages  //
// ver 1.1                                                                    //
// Language:    C++, Visual Studio 2017										  //
// Application: Most Projects, CSE687 - Object Oriented Design				  //
// Author:      Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019		  //
////////////////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package provides functions:
* - htmlGenerate(const std::string& filename, std::vector<std::string> _de, countTable _tables)		Generate the html webpages
* - addFunc_2_(std::vector<std::string> _fileF, std::vector<std::pair<size_t, size_t>> _funcL)		Add function part show/hide button
* - addClass_2_(std::vector<std::string> _fileC, std::vector<std::pair<size_t, size_t>> _classL)	Add class part show/hide button
* - getTable()																						Return the value of countTable
*
* Build Process:
* --------------
* Required Files:
*  htmlConverter.h
*  countTable.h
* Maintenance History:
* --------------------
* ver 1.1 : 6 Mar 2019
* - add countTable operations
* ver 1.0 : 28 Feb 2019
* - first release
*
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../Converter/htmlConverter.h"
#include "../countTable/countTable.h"

std::vector<std::string> addFunc_2_(std::vector<std::string> _fileF, std::vector<std::pair<size_t, size_t>> _funcL);
std::vector<std::string> addClass_2_(std::vector<std::string> _fileC, std::vector<std::pair<size_t, size_t>> _classL);

class toggleDisplay
{
public:
	void htmlGenerate(const std::string& filename, std::vector<std::string> _de, countTable _tables, std::string outpath_);
	countTable getTable();
	
private:
	countTable _tb;
};

inline std::vector<std::string> addClass_2_(std::vector<std::string> _fileC, std::vector<std::pair<size_t, size_t>> _classL)
{
	for (auto pairLine : _classL)
	{
		size_t startL = pairLine.first + 95;
		size_t endL = pairLine.second + 94;
		if (startL == 0 && endL == 0)
			return _fileC;
		_fileC[startL].insert(_fileC[startL].find("{"), "<span class = \"toggleClassDisplay\">");
		_fileC[endL] = _fileC[endL] + "</span>";
	}
	return _fileC;
}

inline std::vector<std::string> addFunc_2_(std::vector<std::string> _fileF, std::vector<std::pair<size_t, size_t>> _funcL)
{
	for (auto pairLine : _funcL)
	{
		size_t startL = pairLine.first + 95;
		size_t endL = pairLine.second + 95;
		if (startL == 0 && endL == 0)
			return _fileF;
		_fileF[startL].insert(_fileF[startL].find("{"), "<span class = \"toggleMethodDisplay\">");
		_fileF[endL] = _fileF[endL] + "</span>";
	}
	return _fileF;
}