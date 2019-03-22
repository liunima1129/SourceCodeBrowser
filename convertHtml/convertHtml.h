#pragma once
////////////////////////////////////////////////////////////////////////////
// convertHtml.h - class used to convert selected files into HTML files   //
// ver 1.1                                                                //
// Language:    C++, Visual Studio 2017                                   //
// Application: Most Projects, CSE687 - Object Oriented Design            //
// Author:      Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019   //
////////////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* This package provides functions:
* - replaceAll(std::string str, std::string from, std::string to)    Replace all the specific substring of a given string
* - convertH(std::string content, std::string filename)			     Convert given content into the form of Html file
*
* Build Process:
* --------------
* Required Files:
*   convertHtml.h
*
* Maintenance History:
* --------------------
* ver 1.1 : 30 jan 2019
* - added replaceAll function
* ver 1.0 : 29 Jan 2019
* - first release
*
*/
#include <fstream>
#include <string>
#include <sstream>

std::string convertH(std::string content, std::string filename);
std::string replaceAll(std::string str, std::string from, std::string to);

//----< Replace all the specific substring of a given string >-----
std::string replaceAll(std::string str, std::string from, std::string to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
	}
	return str;
}

//----< Convert given content into the form of Html file >-----
std::string convertH(std::string content, std::string filename)
{
	content = replaceAll(content, "<", "&lt");
	content = replaceAll(content, ">", "&gt");
	content = "<h3>" + filename + "</h3>" + content;
	content = "<pre>" + content + "</pre>";
	std::ifstream fin;
	fin.open("../HtmlHeader.txt");
	std::stringstream buffer1;
	buffer1 << fin.rdbuf();
	content = buffer1.str() + content;
	fin.close();
	fin.open("../HtmlEnd.txt");
	std::stringstream buffer2;
	buffer2 << fin.rdbuf();
	content = content + buffer2.str();
	fin.close();
	return content;
}
