#pragma once
#include "ALMSHeaderFiles.h"
#include "User.h"
#include "Time.h"
#include "File.h"
#include "borrowRecoed.h"
#include <QSqlQuery>
#include <QtSql>
#include <qsqldatabase.h>

using namespace std;

class dbHelper
{
private:
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");;
	bool open = false;
public:
	dbHelper();

	bool openDB(string host, string odbcName, string userName, string password);
	bool closeDB();
	
	bool checkLogin(string userName, string password);
	bool checkIsRegistered(string userName);

	user getUser(string userName);
	vector<user> getAllUser(user _u);
	bool checkUser(user _u);
	bool addUser(user _u);
	bool setUserPassword(user _u);
	bool setUserLevel(user _u);
	bool setUserPhoneNumber(user _u);

	file getFileByTitle(string fileTitle);
	vector<file> getAllFile();
	vector<file> getFilesByUser(string userName);
	vector<file> getFilesByTime(myTime start, myTime end);
	bool checkFile(file _f);
	bool addFile(file _f);
	bool setFileTitle(file _f);
	bool setFileUserName(file _f);
	bool setFileLoadTime(file _f);
	bool setFileSaveTime(file _f);
	bool setFileContent(file _f);
	bool setFileType(file _f);
	bool setFileSecrecy(file _f);
	bool setFileIsBorrowed(file _f);

	borrowRecord getRecordByGuid(string guid);
	vector<borrowRecord> getAllRecord();
	vector<borrowRecord> getRecordByUser(user _u);
	vector<borrowRecord> getUnDealRecord();
	vector<borrowRecord> getDealRecord();
	vector<borrowRecord> getRocordByFileTitle(file _f);
	vector<borrowRecord> getOutOfLimitTimeRecord(myTime _t);
	bool checkRecord(borrowRecord _bR);
	bool addRecord(borrowRecord _bR);
	bool setBorrowTime(borrowRecord _bR);
	bool setReturnTime(borrowRecord _bR);
	bool setIsDealWith(borrowRecord _bR);
	bool setDealResult(borrowRecord _bR);
	
	~dbHelper();
};
