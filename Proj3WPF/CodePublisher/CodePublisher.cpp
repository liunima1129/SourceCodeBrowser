/////////////////////////////////////////////////////////////////////////////
// CodePublisher.cpp - Interface for the code publisher					   //
// ver 1.0																   //
// ----------------------------------------------------------------------- //
// copyright Yuhan Liu, 2019	                                           //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017                             //
// Platform:    Alienware m15, Core i7, Windows 10	                       //
// Application: CSE 687 Spring Projects, 2019                              //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////

#define IN_DLL

#include "../CodePublisher/ICodePublisher.h"
#include "../Tokenizer/Toker.h"
#include "../Utilities/codeUtilities.h"
#include "../DirExplorer/DirExplorer.h"
#include "../dependency/dependency.h"
#include "../fileDisplay/fileDisplay.h"
#include "../Parser/Parser.h"
#include "../Project2Starter/requirements.h"
#include "../SemiExpression/Semi.h"
#include "../FileSystem/FileSystem.h"

using namespace CodeAnalysis;

class CodePublisher : public ICodePublisher
{
public:
	//Initialize cmd line
	void Init_(int argc, char *argv[]);
	//Get file path
	std::vector<std::string> getfilepath_();
	//Get file name
	std::vector<std::string> getfilename_();
	//Traverse and convert files
	void treeSet_(std::string outpath_);
	//Automatically display
	void publisher(std::string outpath_);
	//Show requirements on the console
	void requires_();
	//Destructor
	~CodePublisher() override { delete pcl_; };
private:
	FileSystem::DirExplorerN* pcl_;
};

void CodePublisher::Init_(int argc, char *argv[])
{
	Utilities::ProcessCmdLine pcl(argc, argv);
	std::cout << "Command Line: " << std::endl;
	pcl_ = new FileSystem::DirExplorerN(pcl.path());
	for (auto p : pcl.getPatts())
		pcl_->addPattern(p);
	for (auto r : pcl.getRegxs())
		pcl_->addRegex(r);
	if(pcl.hasOption('s'))
		pcl_->recurse(true);
	pcl_->findfile(pcl.path(), pcl.regexes(), pcl.patterns());
}

std::vector<std::string> CodePublisher::getfilepath_()
{
	return pcl_->getfilepath_();
}

std::vector<std::string> CodePublisher::getfilename_()
{
	return pcl_->getfilename_();
}

void CodePublisher::treeSet_(std::string outpath_)
{
	Dependency output_navi;
	std::vector<std::string> filepaths = pcl_->getfilepath_();
	output_navi.setTree(filepaths, outpath_);
}

void CodePublisher::publisher(std::string outpath_)
{
	std::vector<std::string> filenames = pcl_->getfilename_();
	fileOpen(filenames, outpath_);
	endDisplay();
}

void CodePublisher::requires_()
{
	showRequirements_1_4();
	showRequirements_5();
	showRequirements_6_7();
}

ICodePublisher* ObjectFactory::createClient()
{
	return new CodePublisher;
}

#ifdef TEST_CODEPUBLISHER
int main(int argc, char *argv[])
{
	CodePublisher test;
	test.Init_(argc, argv);
	test.treeSet_();
	test.publisher();
	return 0;
}
#endif // TEST_CODEPUBLISHER
