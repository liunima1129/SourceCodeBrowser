/////////////////////////////////////////////////////////////////////////////
// display.cpp - Support file and directory operations					   //
// ver 1.2                                                                 //
// ----------------------------------------------------------------------- //
// copyright Yuhan Liu, 2019	                                           //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2010                             //
// Platform:    Lenovo Y50-70, Core i7, Windows 10	                       //
// Application: CSE 687 Spring Projects, 2019                              //
// Author:      Yuhan Liu, Syracuse University						       //
/////////////////////////////////////////////////////////////////////////////
#include "../Display/display.h"

void toggleDisplay::htmlGenerate(const std::string& filename, std::vector<std::string> _de, countTable _tables)
{
	std::vector<std::string> _contents, temp;
	std::ifstream fin;
	std::string _abpath = FileSystem::Path::getFullFileSpec(filename);
	fin.open(_abpath);
	std::string line;
	for (auto f : _de)  //change dependencies into links
	{
		f = addLink(f);
		_contents.push_back(f);
		_contents.push_back("\n");
	}
	while (!fin.eof())  //read original file
	{
		std::getline(fin, line);
		temp.push_back(line);
	}
	temp = convertH(temp, filename);
	_tb.setclassTable(_tables.getclassTable());
	_tb.setfuncTable(_tables.getfuncTable());
	countTable::_table _class = _tb.getclassTable();
	countTable::_table _func = _tb.getfuncTable();
	std::vector<std::pair<size_t, size_t>> _classL = _class[filename];
	std::vector<std::pair<size_t, size_t>> _funcL = _func[filename];
	if(!_classL.empty())
		temp = addClass_2_(temp, _classL);
	if (!_funcL.empty())
		temp = addFunc_2_(temp, _funcL);
	for (auto line : temp)
		_contents.push_back(line);
	std::ofstream fout;
	fout.open("../convertedPages/" + realName(filename) + ".html");
	for (auto line : _contents)
		fout << line;
	fout.close();
	fin.close();
}

countTable toggleDisplay::getTable()
{
	return _tb;
}