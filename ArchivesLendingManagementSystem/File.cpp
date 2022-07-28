#include "File.h"

file::file()
{
	fileTitle = QString();
	userName = QString();
	loadTime = myTime();
	saveTime = myTime();
	fileContent = QString();
	fileType = 0;
	fileSecrecy = 0;
	isBorrowed = 0;
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
	fileTitle = _fileTitle;
}

QString file::getFileTitle()
{
	QString ret = "";
	for (auto i : fileTitle) {
		if (i == (char)39) {
			ret += (char)39;
			ret += (char)39;
		}
		else {
			ret += i;
		}
	}
	return ret;
}

void file::setUserName(QString _userName)
{
	userName = _userName;
}

QString file::getUserName()
{
	return userName;
}

void file::setLoadTime(myTime _loadTime)
{
	loadTime = _loadTime;
}

myTime file::getLoadTime()
{
	return loadTime;
}

void file::setSaveTime(myTime _saveTime)
{
	saveTime = _saveTime;
}

myTime file::getSaveTime()
{
	return saveTime;
}

void file::setFileContent(QString _fileContent)
{
	fileContent = _fileContent;
}

QString file::getFileContent()
{
	QString ret = "";
	for (auto i : fileContent) {
		if (i == (char)39) {
			ret += (char)39;
			ret += (char)39;
		}
		else {
			ret += i;
		}
	}
	return ret;
}

void file::setFileType(bool _fileType)
{
	fileType = _fileType;
}

bool file::getFileType()
{
	return fileType;
}

void file::setFileSecrecy(int _fileSecrecy)
{
	fileSecrecy = _fileSecrecy;
}

int file::getFileSecrecy()
{
	return fileSecrecy;
}

void file::setIsBorrowed(bool _isBorrowed)
{
	isBorrowed = _isBorrowed;
}

bool file::getIsBorrowed()
{
	return isBorrowed;
}

file::~file()
{
}
