#pragma once
#include "ALMSHeaderFiles.h"
#include "MyTime.h"
#include "User.h"
using namespace std;

class file
{
private:
	string fileTitle;
	string userName;
	myTime loadTime;
	myTime saveTime;
	string fileContent;
	bool fileType;
	int fileSecrecy;
	bool isBorrowed;

public:
	file();
	file(string _fileTitle, string _userName, myTime _loadTime, myTime _saveTime, string _fileContent, bool _fileType, int _fileSecrecy, bool _isBorrowed);
	void setFileTitle(string _fileTitle);
	string getFileTitle();
	void setUserName(string _userName);
	string getUserName();
	void setLoadTime(myTime _loadTime);
	myTime getLoadTime();
	void setSaveTime(myTime _saveTime);
	myTime getSaveTime();
	void setFileContent(string _fileContent);
	string getFileContent();
	void setFileType(bool _fileType);
	bool getFileType();
	void setFileSecrecy(int _fileSecrecy);
	int getFileSecrecy();
	void setIsBorrowed(bool _isBorrowed);
	bool getIsBorrowed();

	~file();
};