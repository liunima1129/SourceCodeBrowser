/////////////////////////////////////////////////////////////////////////////
// dependency.cpp - Support file and directory operations                  //
// ver 1.3                                                                 //
// ----------------------------------------------------------------------- //
// copyright Yuhan Liu, 2019	                                           //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017                             //
// Platform:    Lenovo Y50-70, Core i7, Windows 10	                       //
// Application: CSE 687 Spring Projects, 2019                              //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////
#include <queue>
#include <string>
#include"../dependency/dependency.h"
#include "../Converter/htmlConverter.h"
#include "../Parser/ActionsAndRules.h"
#include "../Parser/ConfigureParser.h"
#include "../Display/display.h"
#include "../AbstractSyntaxTree/AbstrSynTree.h"
#include "../countTable/countTable.h"

template<typename element>
countTable Dependency::NodeTraverse(element* pItem, std::string filename)
{
	static std::string path;
	if (pItem->type_ == "class"){
		tb_.insertclassTable(filename, std::make_pair(pItem->startLineCount_, pItem->endLineCount_));
		//classline.push_back(std::make_pair(pItem->startLineCount_, pItem->endLineCount_));
	}
	if (pItem->type_ == "function"){
		tb_.insertfuncTable(filename, std::make_pair(pItem->startLineCount_, pItem->endLineCount_));
		//functionline.push_back(std::make_pair(pItem->startLineCount_, pItem->endLineCount_));
	}
	auto iter = pItem->children_.begin();
	while (iter != pItem->children_.end())
	{
		NodeTraverse(*iter, filename);
		++iter;
	}
	return tb_;
}

std::pair<std::vector<std::string>, countTable> Dependency::findDenpendency(const std::string& files)
{
	std::string fileSpec;
	std::vector<std::string> dependencyFiles;
	fileSpec = FileSystem::Path::getFullFileSpec(files);
	CodeAnalysis::ConfigParseForCodeAnal configure;
	CodeAnalysis::Parser* pParser = configure.Build();
	std::string name;
	countTable warning__;
	try {
		if (pParser) {
			name = FileSystem::Path::getName(files);
			if (!configure.Attach(fileSpec)) {
				std::cout << "\n  could not open file " << name << std::endl;
				return std::make_pair(dependencyFiles, warning__);
			}
		}
		else {
			std::cout << "\n\n  Parser not built\n\n";
			return std::make_pair(dependencyFiles, warning__);
		}
		CodeAnalysis::Repository* pRepo = CodeAnalysis::Repository::getInstance();
		pRepo->package() = name;
		while (pParser->next())
			pParser->parse();
		std::cout << "\n";
		// final AST operations
		CodeAnalysis::ASTNode* pGlobalScope = pRepo->getGlobalScope();
		countTable temp = NodeTraverse(pGlobalScope, files);
		auto iter2 = pGlobalScope->statements_.begin();
		while (iter2 != pGlobalScope->statements_.end()) {
			dependencyFiles.push_back((*iter2)->ToString());
			iter2++;
		}
		return std::make_pair(dependencyFiles, temp);
	}
	catch (...) {
		std::cout << "\n  exception caught at line " << __LINE__ << " " << "\n  in package \"" << name << "\"";
		exit(0);
	}
}

void Dependency::setTree(std::vector<std::string> fileTree)
{
	for (auto files : fileTree)
		treeTraverse(files);
}

void Dependency::treeTraverse(const std::string& root)
{
	std::pair<std::vector<std::string>, countTable> temp__ = findDenpendency(root);
	std::vector<std::string> _DependFiles = temp__.first;
	countTable tables = temp__.second;
	_DependFiles = includeFiles(_DependFiles);
	_dependencyTree.push_back(root);
	toggleDisplay _generate;
	_generate.htmlGenerate(root, _DependFiles, tables);
	if (_DependFiles.empty())
		return;
	for (auto files : _DependFiles)
	{
		if (std::find(_dependencyTree.begin(), _dependencyTree.end(), files) == _dependencyTree.end())
		{
			treeTraverse(files);
		}
	}
}

std::vector<std::string> includeFiles(std::vector<std::string> statement)
{
	std::vector<std::string> includedFiles;
	for (auto s : statement)
	{
		s = replaceAll(s, " ", "");
		if ((s.find("include\"") != std::string::npos) && (s.find("/") != std::string::npos))
		{
			size_t start = s.find("include\"") + 8;
			size_t end = s.rfind("\"");
			size_t len = end - start;
			s = s.substr(start, len);
			includedFiles.push_back(s);
		}
	}
	return includedFiles;
}

countTable Dependency::getTable()
{
	return tb_;
}
