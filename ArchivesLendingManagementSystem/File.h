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
	void setFileTitle(string _fileTitle, user _u);
	string getFileTitle(user _u);
	void setUserName(string _userName, user _u);
	string getUserName(user _u);
	void setLoadTime(myTime _loadTime, user _u);
	myTime getLoadTime(user _u);
	void setSaveTime(myTime _saveTime, user _u);
	myTime getSaveTime(user _u);
	void setFileContent(string _fileContent, user _u);
	string getFileContent(user _u);
	void setFileType(bool _fileType, user _u);
	bool getFileType(user _u);
	void setFileSecrecy(int _fileSecrecy, user _u);
	int getFileSecrecy(user _u);
	void setIsBorrowed(bool _isBorrowed, user _u);
	bool getIsBorrowed(user _u);

	~file();
};