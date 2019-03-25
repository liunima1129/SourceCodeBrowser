///////////////////////////////////////////////////////////////////////
////  Executive.cpp - Starter code for Project #2                    //
////  ver 1.0                                                        //
////  Language:      Visual C++, Visual Studio 2015                  //
////  Platform:      Dell XPS 8920, Windows 10                       //
////  Application:   Prototype for CSE687 - OOD Projects             //
////  Author:        Jim Fawcett, CST 4-187, Syracuse University     //
////                 (315) 443-3948, jfawcett@twcny.rr.com           //
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "../Tokenizer/Toker.h"
#include "../SemiExpression/Semi.h"
#include "../Utilities/codeUtilities.h"
#include "../Parser/Parser.h"
#include "../DirExplorer/DirExplorer.h"
#include "../dependency/dependency.h"
#include "../fileDisplay/fileDisplay.h"
#include "../Project2Starter/requirements.h"

using Demo = Logging::StaticLogger<1>;

#include "../FileSystem/FileSystem.h"
#include <queue>
#include <string>
#define Util Utilities::StringHelper

using namespace CodeAnalysis;

int main(int argc, char* argv[])
{
	showRequirements_1_4();
	Utilities::ProcessCmdLine pcl(argc, argv);
	FileSystem::DirExplorerN de(pcl.path());
	de.recurse(true);
	de.findfile(pcl.path(), pcl.regexes());
	Dependency output;
	std::vector<std::string> files = de.getfilepath_();
	std::vector<std::string> regex_files = de.getfilename_();
	showRequirements_5(regex_files);
	showRequirements_6_8();
	output.setTree(files);
	fileOpen(regex_files);
	endDisplay();
	return 0;
}