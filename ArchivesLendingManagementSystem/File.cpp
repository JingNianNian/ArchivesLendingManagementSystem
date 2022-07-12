#include "File.h"

file::file()
{
}

file::file(QString _fileTitle, QString _userName, myTime _loadTime, myTime _saveTime, QString _fileContent, bool _fileType, int _fileSecrecy, bool _isBorrowed)
{
	fileTitle = _fileTitle;
	userName = _userName;
	loadTime = _loadTime;
	saveTime = _saveTime;
	fileContent = _fileContent;
	fileType = _fileType;
	fileSecrecy = _fileSecrecy;
	isBorrowed = _isBorrowed;
}

void file::setFileTitle(QString _fileTitle)
{
}

QString file::getFileTitle()
{
	return fileTitle;
}

void file::setUserName(QString _userName)
{
}

QString file::getUserName()
{
	return userName;
}

void file::setLoadTime(myTime _loadTime)
{
}

myTime file::getLoadTime()
{
	return loadTime;
}

void file::setSaveTime(myTime _saveTime)
{
}

myTime file::getSaveTime()
{
	return saveTime;
}

void file::setFileContent(QString _fileContent)
{
}

QString file::getFileContent()
{
	return fileContent;
}

void file::setFileType(bool _fileType)
{
}

bool file::getFileType()
{
	return fileType;
}

void file::setFileSecrecy(int _fileSecrecy)
{
}

int file::getFileSecrecy()
{
	return fileSecrecy;
}

void file::setIsBorrowed(bool _isBorrowed)
{
}

bool file::getIsBorrowed()
{
	return isBorrowed;
}

file::~file()
{
}
