#pragma once
/////////////////////////////////////////////////////////////////////
// DirExplorer.h - directory explorer				               //
// ver 1.1                                                         //
// Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019         //
/////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 * DirExplorer provides a class, of the same name, that executes a
 * depth first search of a directory tree rooted at a specified path.
 * Each time it enters a directory, it invokes its member function
 * doDir, and for every file in that directory, it invokes doFile.
 *
 * Required Files:
 * ---------------
 * DirExplorerN.h, DirExplorerN.cpp
 * FileSystem.h, FileSystem.cpp      // Directory and Path classes
 * StringUtilities.h                 // Title function
 * CodeUtilities.h                   // ProcessCmdLine class
 *
 * Maintenance History:
 * --------------------
 * ver 1.1 : 1 Feb 2019
 * - Adding function findfile()
 * ver 1.0 : 11 Aug 2018
 * - first release
 *
*/
#include <vector>
#include <iostream>
#include "../FileSystem/FileSystem.h"
#include "../Utilities/Utilities.h"
#include "../Utilities/codeUtilities.h"

namespace FileSystem
{
	class DirExplorerN
	{
	public:
		using patterns = std::vector<std::string>;
		using reg = std::vector<std::string>;

		static std::string version() { return "ver 1.3"; }

		DirExplorerN(const std::string& path);

		// set options for analysis

		void addPattern(const std::string& patt);
		void addRegex(const std::string& regx);
		void recurse(bool doRecurse = true);

		// conduct depth first search

		void search();
		void find(const std::string& path);
		void findfile(const std::string& path, std::vector<std::string> regexes_, std::vector<std::string> patt);
		//void findpatt(const std::string& path, std::vector<std::string> patt);
		std::vector<std::string> getfilepath_();
		std::vector<std::string> getfilename_();
		std::vector<std::string> getfilepathpatt_();
		std::vector<std::string> getfilenamepatt_();
		// define what happens when a file or dir is encountered

		void doFile(const std::string& filename);
		void doDir(const std::string& dirname);

		// extract traversal statistics 

		size_t fileCount();
		size_t dirCount();
		void showStats();

	private:
		std::string path_;
		patterns patterns_;
		reg regex_;
		size_t dirCount_ = 0;
		size_t fileCount_ = 0;
		bool recurse_ = false;
		std::vector<std::string> filepath_;
		std::vector<std::string> filename_;
		std::vector<std::string> filepathpatt_;
		std::vector<std::string> filenamepatt_;
	};

	//----< construct DirExplorerN instance with default pattern >-----

	DirExplorerN::DirExplorerN(const std::string& path) : path_(path)
	{
		patterns_.push_back("*.*");
	}
	//----< add specified patterns for selecting file names >----------

	void DirExplorerN::addPattern(const std::string& patt)
	{
		if (patterns_.size() == 1 && patterns_[0] == "*.*")
			patterns_.pop_back();
		patterns_.push_back(patt);
	}

	void DirExplorerN::addRegex(const std::string& regx)
	{
		regex_.push_back(regx);
	}
	//----< set option to recusively walk dir tree >-------------------

	void DirExplorerN::recurse(bool doRecurse)
	{
		recurse_ = doRecurse;
	}
	//----< start Depth First Search at path held in path_ >-----------

	void DirExplorerN::search()
	{
		find(path_);
	}
	//----< search for directories and their files >-------------------
	/*
	  Recursively finds all the dirs and files on the specified path,
	  executing doDir when entering a directory and doFile when finding a file
	*/
	void DirExplorerN::find(const std::string& path)
	{
		// show current directory

		std::string fpath = FileSystem::Path::getFullFileSpec(path);
		//doDir(fpath);

		for (auto patt : patterns_)
		{
			std::vector<std::string> files = FileSystem::Directory::getFiles(fpath, patt);
			for (auto f : files)
			{
				doFile(f);  // show each file in current directory
			}
		}

		std::vector<std::string> dirs = FileSystem::Directory::getDirectories(fpath);
		for (auto d : dirs)
		{
			if (d == "." || d == "..")
				continue;
			std::string dpath = fpath + "\\" + d;
			if (recurse_)
			{
				find(dpath);   // recurse into subdirectories
			}
			else
			{
				doDir(dpath);  // show subdirectories
			}
		}
	}
	//----< an application changes to enable specific file ops >-------

	void DirExplorerN::doFile(const std::string& filename)
	{
		++fileCount_;
		std::cout << "\n  --   " << filename;
	}
	//----< an application changes to enable specific dir ops >--------

	void DirExplorerN::doDir(const std::string& dirname)
	{
		++dirCount_;
		std::cout << "\n  ++ " << dirname;
	}
	//----< return number of files processed >-------------------------

	size_t DirExplorerN::fileCount()
	{
		return fileCount_;
	}
	//----< return number of directories processed >-------------------

	size_t DirExplorerN::dirCount()
	{
		return dirCount_;
	}
	//----< show final counts for files and dirs >---------------------

	void DirExplorerN::showStats()
	{
		std::cout << "\n\n  processed " << fileCount_ << " files in " << dirCount_ << " directories";
	}

	void DirExplorerN::findfile(const std::string& path, std::vector<std::string> regexes_, std::vector<std::string> patt)
	{
		std::string fpath = FileSystem::Path::getFullFileSpec(path);
		patterns_ = patt;
		regex_ = regexes_;
		for (auto p : patt){
			std::vector<std::string> files = FileSystem::Directory::getFiles(fpath, p);
			for (auto f : files){
				for (auto re : regexes_) {
					if (std::regex_match(f, std::regex(re))) {
						filepath_.push_back(path + "/" + f);
						filename_.push_back(f);
					}
				}
			}
		}
		std::vector<std::string> dirs = FileSystem::Directory::getDirectories(fpath);
		for (auto d : dirs){
			if (d == "." || d == "..")
				continue;
			std::string dpath = fpath + "\\" + d;
			if (recurse_)
				findfile(dpath, regexes_, patt);   // recurse into subdirectories
		}
	}

	//void DirExplorerN::findpatt(const std::string& path, std::vector<std::string> patt)
	//{
	//	std::string fpath = FileSystem::Path::getFullFileSpec(path);
	//	for (auto p : patt)
	//	{
	//		std::vector<std::string> files = FileSystem::Directory::getFiles(fpath, p);
	//		for (auto f : files)
	//		{
	//			filepathpatt_.push_back(path + "/" + f);
	//			filenamepatt_.push_back(f);
	//		}
	//	}
	//	std::vector<std::string> dirs = FileSystem::Directory::getDirectories(fpath);
	//	for (auto d : dirs)
	//	{
	//		if (d == "." || d == "..")
	//			continue;
	//		std::string dpath = fpath + "\\" + d;
	//		if (recurse_)
	//			findpatt(dpath, patt);   // recurse into subdirectories
	//	}
	//}

	std::vector<std::string> DirExplorerN::getfilepath_()
	{
		return filepath_;
	}

	std::vector<std::string> DirExplorerN::getfilename_()
	{
		return filename_;
	}

	std::vector<std::string> DirExplorerN::getfilepathpatt_()
	{
		return filepathpatt_;
	}
	std::vector<std::string> DirExplorerN::getfilenamepatt_()
	{
		return filenamepatt_;
	}
}
