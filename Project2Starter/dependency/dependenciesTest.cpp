/////////////////////////////////////////////////////////////////////////////
// dependenciesTest.cpp - Test stub for package dependency                 //
// ver 1.1                                                                 //
// Language:    Visual C++, Visual Studio 2017                             //
// Platform:    Lenovo Y50-70, Core i7, Windows 10	                       //
// Application: Used to test whether dependency.h is available		       //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////
#ifdef TEST_DEPENDENCIES
#include "../dependency/dependency.h"

int main(int argc, char* argv[])
{
	std::string paths;
	paths = "../AbstractSyntaxTree/AbstrSynTree.h";
	Dependency output;
	//std::vector<std::string> showState = output.findDenpendency(paths);
	//std::vector<std::string> showDependency = includeFiles(showState);
	//std::cout << paths << " " << "dependencies:" << std::endl;
	//for (auto f : showDependency)
	//{
	//	std::cout << f << std::endl;
	//}
	std::vector<std::string> sample;
	sample.push_back("../AbstractSyntaxTree/AbstrSynTree.h");
	output.setTree(sample);
	return 0;
}
#endif // TEST_DEPENDENCIES
