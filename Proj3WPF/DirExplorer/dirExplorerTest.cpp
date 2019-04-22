/////////////////////////////////////////////////////////////////////////////
// DirExplorerTest.cpp - Test stub for DirExplorer.h                       //
// ver 1.1                                                                 //
// ----------------------------------------------------------------------- //
// copyright    Yuhan Liu, 2019                                            //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017 Community                   //
// Platform:    Lenovo Y50-70, Core i7, Windows 10                         //
// Application: CSE687 Project, Spring 2019                                //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////

#ifdef TEST_DIREXPLORER  // only compile the following when defined

#include "../DirExplorer/DirExplorer.h"
#include "../Utilities/Utilities.h"
#include "../Utilities/CodeUtilities.h"

using namespace Utilities;
using namespace FileSystem;

ProcessCmdLine::Usage customUsage()
{
	std::string usage;
	usage += "\n  Command Line: path [/option]* [/pattern]*";
	usage += "\n    path is relative or absolute path where processing begins";
	usage += "\n    [/option]* are one or more options of the form:";
	usage += "\n      /s - walk directory recursively";
	//usage += "\n      /h - hide empty directories";
	//usage += "\n      /a - on stopping, show all files in current directory";
	usage += "\n    [pattern]* are one or more pattern strings of the form:";
	usage += "\n      *.h *.cpp *.cs *.txt or *.*";
	usage += "\n";
	return usage;
}

int main(int argc, char *argv[])
{
	Title("Demonstrate DirExplorer, " + DirExplorerN::version());

	ProcessCmdLine pcl(argc, argv);
	pcl.usage(customUsage());

	preface("Command Line: ");
	pcl.showCmdLine();
	putline();

	if (pcl.parseError())
	{
		pcl.usage();
		std::cout << "\n\n";
		return 1;
	}

	DirExplorerN de(pcl.path());
	for (auto patt : pcl.patterns())
	{
		de.addPattern(patt);
	}

	if (pcl.hasOption('s'))
	{
		de.recurse();
	}

	de.search();
	de.showStats();

	std::cout << "\n\n";
	return 0;
}

#endif