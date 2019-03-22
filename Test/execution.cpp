/////////////////////////////////////////////////////////////////////////////
// execution.cpp - Execute and run the whole solution                      //
// ver 1.5                                                                 //
// ----------------------------------------------------------------------- //
// copyright    Yuhan Liu, 2019                                            //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017 Community                   //
// Platform:    Lenovo Y50-70, Core i7, Windows 10                         //
// Application: CSE687 Project, Spring 2019                                //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../Display/Display.h"
#include "../convertHtml/convertHtml.h"
#include "../Utilities/codeUtilities.h"
#include "../DirExplorer/DirExplorer.h"
#include "FileSystem.h"
#include "../Test/process.h"
#include "../Test/requirements.h"

int main(int argc, char *argv[])
{
    Utilities::ProcessCmdLine pcl(argc, argv);
    FileSystem::DirExplorerN fileNames(pcl.path());
    std::vector<std::string> files = fileNames.findfile();
    int fileNumCount = 0;
    std::vector<std::string> regexFiles;
    for (auto f : files)
    {
        std::ifstream fin;
        fin.open("../Test/" + f);
        std::stringstream buffer;
        buffer << fin.rdbuf();
        std::string content(buffer.str());
        for (auto r : pcl.regexes())
        {
            if (std::regex_match(f, std::regex(r)))
            {
                std::cout << f << std::endl;
                fileNumCount++;
                regexFiles.push_back(f);
                std::ofstream fout;
                fout.open("../convertedPages/" + f + ".html");
                fout << convertH(content, f) << std::endl;
                fout.close();
            }
        }
        fin.close();
    }
	showRequirements_1_4(regexFiles);
	showRequirements_5_6();
    if (fileNumCount == 0)
    {
        std::cout << "no such file exists" << std::endl;
		system("pause");
		exit(1);

    }
	showRequirements_7();
	display(regexFiles);
	endDisplay();
	system("pause");
    return 0;
}
