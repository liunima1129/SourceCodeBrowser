/////////////////////////////////////////////////////////////////////////////
// convertHtmlTest.cpp - Test stub for convertHtml.h                       //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright    Yuhan Liu, 2019                                            //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017 Community                   //
// Platform:    Lenovo Y50-70, Core i7, Windows 10                         //
// Application: CSE687 Project, Spring 2019                                //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////
#ifdef TEST_CONVERTHTML
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../convertHtml/convertHtml.h"

int main(int argc, char *argv[])
{
	std::ifstream fin;
	fin.open("../Test/execution.cpp");
	std::stringstream buffer;
	buffer << fin.rdbuf();
	std::string content(buffer.str());
	std::ofstream fout;
	fout.open("../TestStubFiles/execution.cpp.html");
	fout << convertH(content, "execution.cpp") << std::endl;
	fout.close();
	fin.close();
	return 0;
}
#endif // TEST_CONVERTHTML
