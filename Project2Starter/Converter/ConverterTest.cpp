//////////////////////////////////////////////////////////////////////////
//  ConverterTest.cpp - Test stub of htmlConverter.h					//
//  ver 1.1																//
//  Language:      Visual C++ 2017									    //
//  Platform:      Lenovo Y50-70, Windows 10							//
//  Application:   Used to test whether htmlConverter.h is available    //
//  Author:        Yuhan Liu, Syracuse University						//
//////////////////////////////////////////////////////////////////////////
#ifdef TEST_CONVERTER
#include "../Converter/htmlConverter.h"

int main(int argc, char *argv[])
{
	convert handle;
	std::vector<std::string> content;
	content.push_back("<iostream>");
	content.push_back("using namespace std;");
	content = handle.convertH(content, "TEST_CONVERTER.h");
	for (auto line : content)
		std::cout << line << std::endl;

	return 0;
}
#endif