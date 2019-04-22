#pragma once
////////////////////////////////////////////////////////////////////////////
// htmlConverter.h - class used to convert selected files into HTML files //
// ver 1.2                                                                //
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
*   htmlConverter.h
*
* Maintenance History:
* --------------------
* ver 1.2 : 28 Feb 2019
* - changed the way reading code from .cpp/.h files
* ver 1.1 : 30 Jan 2019
* - added replaceAll function
* ver 1.0 : 29 Jan 2019
* - first release
*
*/
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "../FileSystem/FileSystem.h"
#include "../dependency/dependency.h"

//----< Function Declarations >-----
std::vector<std::string> convertH(std::vector<std::string> content, std::string filename);
std::string addLink(std::string _link);
std::string realName(std::string filename);
std::string replaceAll(std::string str, std::string from, std::string to);
std::vector<std::string> addC_omment(std::vector<std::string> content);

//----< Replace all the specific substring of a given string >-----
inline std::string replaceAll(std::string str, std::string from, std::string to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
	}
	return str;
}

inline std::string addLink(std::string _link)
{
	std::string newLink;
	_link = realName(_link);
	std::string _path = "../../../convertedPages/" + _link;
	newLink = "<a href=\"" + _path + ".html" + "\">" + _link + "</a>";
	return newLink;
}

inline std::string realName(std::string filename)
{
	filename = filename.substr(filename.rfind("/") + 1);
	return filename;
}

//----< Convert given content into the form of Html file >-----
inline std::vector<std::string> convertH(std::vector<std::string> content, std::string filename)
{
	std::vector<std::string> htmlContent;
	std::string line;
	std::ifstream fin;
	fin.open("../HtmlHeader.txt");
	while (!fin.eof()){
		std::getline(fin, line);
		htmlContent.push_back(line);
		htmlContent.push_back("\n");

	}
	fin.close();
	htmlContent.push_back("<h3>" + filename + "</h3>" + "\n");
	htmlContent.push_back("<pre>\n");
	for (auto line : content){
		line = replaceAll(line, "<", "&lt");
		line = replaceAll(line, ">", "&gt") + "\n";
		htmlContent.push_back(line);
	}
	htmlContent.push_back("</pre>");
	fin.open("../HtmlEnd.txt");
	while (!fin.eof()){
		std::getline(fin, line);
		htmlContent.push_back(line);
		htmlContent.push_back("\n");
	}
	fin.close();
	htmlContent = addC_omment(htmlContent);
	return htmlContent;
}

inline std::vector<std::string> addC_omment(std::vector<std::string> content)
{
	for (size_t count = 0; count < content.size(); count++) {
		if (content[count].find("//") != std::string::npos) {
			size_t position;
			position =content[count].find("//") - 1;
			content[count].insert((position + 1), "<span class = \"toggleCommentDisplay\">");
			content[count] = content[count] + "</span>";
		}
		if (content[count].find("/*") != std::string::npos)
			content[count].insert(content[count].find("/*"), "<span class = \"toggleCommentDisplay\">");
		if (content[count].find("*/") != std::string::npos)
			content[count].insert(content[count].find("*/") + 2, "</span>");
	}
	return content;
}