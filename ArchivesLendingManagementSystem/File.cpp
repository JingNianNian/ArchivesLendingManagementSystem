#include "File.h"

file::file()
{
}

file::file(string _fileTitle, string _userName, myTime _loadTime, myTime _saveTime, string _fileContent, bool _fileType, int _fileSecrecy, bool _isBorrowed)
{
}

void file::setFileTitle(string _fileTitle, user _u)
{
}

string file::getFileTitle(user _u)
{
	return string();
}

void file::setUserName(string _userName, user _u)
{
}

string file::getUserName(user _u)
{
	return string();
}

void file::setLoadTime(myTime _loadTime, user _u)
{
}

myTime file::getLoadTime(user _u)
{
	return myTime();
}

void file::setSaveTime(myTime _saveTime, user _u)
{
}

myTime file::getSaveTime(user _u)
{
	return myTime();
}

void file::setFileContent(string _fileContent, user _u)
{
}

string file::getFileContent(user _u)
{
	return string();
}

void file::setFileType(bool _fileType, user _u)
{
}

bool file::getFileType(user _u)
{
	return false;
}

void file::setFileSecrecy(int _fileSecrecy, user _u)
{
}

int file::getFileSecrecy(user _u)
{
	return 0;
}

void file::setIsBorrowed(bool _isBorrowed, user _u)
{
}

bool file::getIsBorrowed(user _u)
{
	return false;
}

file::~file()
{
}
