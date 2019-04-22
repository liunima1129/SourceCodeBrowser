/////////////////////////////////////////////////////////////////////////////
// Shim.cpp - C++/CLI Translator										   //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright Yuhan Liu, 2019	                                           //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017                             //
// Platform:    Alienware m15, Core i7, Windows 10	                       //
// Application: CSE 687 Spring Projects, 2019                              //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////

#include "../Shim/Shim.h"

Shim::Shim()
{
	Console::Write("\n Shim created");
	ObjectFactory factory;
	client = factory.createClient();
	Console::Write("\n Shim instantiated CodePublisher as ICodePublisher*");
}

//destructor
Shim::~Shim()
{
	delete client;
	Console::Write("\n Shim destroyed\n\n");
}

//Initialize cmd line
void Shim::Init(List<System::String^> ^args)
{
	int argc = args->Count + 1;
	char ** argv = new char*[argc];
	argv[0] = NULL;
	for (int i = 1; i < argc; i++)
	{
		std::string temp = sysStrtoStdStr(args[i - 1]);
		argv[i] = new char[args[i - 1]->Length];
		strcpy_s(argv[i], args[i - 1]->Length + 1, temp.c_str());
	}
	client->Init_(argc, argv);
}

//Find Dependencies and convert
void Shim::treeSet(String^ outpath)
{
	std::string outPth = sysStrtoStdStr(outpath);
	client->treeSet_(outPth);
}

//Get file name
List<String^>^ Shim::getname()
{
	std::vector<std::string> temp_n = client->getfilename_();
	List<String^>^ temp_name = gcnew List<String^>();
	for (auto n : temp_n)
		temp_name->Add(stdStrtoSysStr(n));
	Filenames = temp_name;
	return Filenames;
}

//Get file path
List<String^>^ Shim::getpath()
{
	std::vector<std::string> temp_p = client->getfilepath_();
	List<String^>^ temp_path = gcnew List<String^>();
	for (auto p : temp_p)
		temp_path->Add(stdStrtoSysStr(p));
	Filepaths = temp_path;
	return Filepaths;
}

//Automatically display
void Shim::publisher(String^ outpath)
{
	std::string outpath_ = sysStrtoStdStr(outpath);
	client->publisher(outpath_);
}

//Show Requirements on the console
void Shim::requires()
{
	client->requires_();
}

//Convert standard string to system string
String^ Shim::stdStrtoSysStr(const std::string& str_)
{
	return gcnew String(str_.c_str());
}

//Convert system string to standard string
std::string Shim::sysStrtoStdStr(String^ str_)
{
	std::string temp;
	for (int i = 0; i < str_->Length; i++)
		temp += char(str_[i]);
	return temp;
}

#ifdef TEST_SHIM
int main(array<System::String^> ^args)
{
	List<String^> ^ temp = gcnew List<String^>;
	for (int i = 0; i < args->Length; i++)
		temp->Add(args[i]);
	Shim test;
	test.Init(temp);
	test.treeSet();
	test.publisher("..\\convertedPages");
	return 0;
}
#endif // TEST_SHIM
