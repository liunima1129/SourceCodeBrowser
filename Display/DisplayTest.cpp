/////////////////////////////////////////////////////////////////////////////
// DisPlayTest.cpp - Test stub for Display.h		                       //
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
#ifdef TEST_DISPLAY
#include "../Display/Display.h"
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<std::string> files;
	files.push_back("displayPackageTest1.h.html");
	files.push_back("displayPackageTest2.h.html");
	display(files);
	endDisplay();
	return 0;
}
#endif // TEST_DISPLAY
