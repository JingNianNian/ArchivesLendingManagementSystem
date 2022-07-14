#pragma once
#include "ALMSHeaderFiles.h"
#include "MyTime.h"
#include "User.h"
using namespace std;

class file
{
private:
	QString fileTitle;
	QString userName;
	myTime loadTime;
	myTime saveTime;
	QString fileContent;
	bool fileType;
	int fileSecrecy;
	bool isBorrowed;

public:
	file();
	file(QString _fileTitle, QString _userName, myTime _loadTime, myTime _saveTime, QString _fileContent, bool _fileType, int _fileSecrecy, bool _isBorrowed);
	void setFileTitle(QString _fileTitle);
	QString getFileTitle();
	void setUserName(QString _userName);
	QString getUserName();
	void setLoadTime(myTime _loadTime);
	myTime getLoadTime();
	void setSaveTime(myTime _saveTime);
	myTime getSaveTime();
	void setFileContent(QString _fileContent);
	QString getFileContent();
	void setFileType(bool _fileType);
	bool getFileType();
	void setFileSecrecy(int _fileSecrecy);
	int getFileSecrecy();
	void setIsBorrowed(bool _isBorrowed);
	bool getIsBorrowed();

	~file();
};