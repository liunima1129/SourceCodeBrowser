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
#include <regex>
#include "../Test/FileSystem.h"
#include "../Utilities/codeUtilities.h"
#include "../Utilities/StringUtilities.h"

namespace FileSystem
{
	class DirExplorerN
	{
	public:
		using patterns = std::vector<std::string>;

		static std::string version() { return "ver 1.3"; }

		DirExplorerN(const std::string& path);

		// set options for analysis

		void addPattern(const std::string& patt);
		void recurse(bool doRecurse = true);

		// conduct depth first search

		void search();
		void find(const std::string& path);
		std::vector<std::string> findfile(std::vector<std::regex> regexes_);

		// define what happens when a file or dir is encountered

		void doFile(const std::string& filename);
		void doDir(const std::string& dirname);

		// extract traversal statistics 

		size_t fileCount();
		size_t dirCount();
		void showStats();

	private:
		std::vector<std::string> filepath_;
		std::string path_;
		patterns patterns_;
		size_t dirCount_ = 0;
		size_t fileCount_ = 0;
		bool recurse_ = false;
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

	std::vector<std::string> DirExplorerN::findfile(std::vector<std::regex> regexes_)
	{
		std::string fpath = FileSystem::Path::getFullFileSpec(path_);
		//		std::vector<std::string> filenames;

		for (auto patt : patterns_)
		{
			std::vector<std::string> files = FileSystem::Directory::getFiles(fpath, patt);
			for (auto f : files)
			{
				for (auto re : regexes_) {
					if (std::regex_match(f, re)) {
						filepath_.push_back(f);
					}
				}
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
				findfile(regexes_);   // recurse into subdirectories
			}


		for (auto f : patterns_)
		{
			std::cout << f << std::endl;
		}
		return filepath_;
	}

}
