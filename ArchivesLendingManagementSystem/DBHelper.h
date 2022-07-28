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
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
	bool open = false;
public:
	dbHelper();

	bool openDB(QString host, QString odbcName, QString userName, QString password);
	bool closeDB();
	
	bool checkLogin(QString userName, QString password);

	QSqlTableModel* getTableModel(QString tableName);

	user getUser(QString userName);
	vector<user> getAllUser();
	bool checkUser(user _u);
	bool addUser(user _u);
	bool setUserPassword(user _u);
	bool setUserLevel(user _u);
	bool setUserPhoneNumber(user _u);
	bool deleteUser(user _u);

	file getFileByTitle(QString fileTitle);
	vector<file> getAllFile();
	vector<file> getFilesByUser(QString userName);
	vector<file> getFilesByTime(myTime start, myTime end);
	bool checkFile(file _f);
	bool addFile(file _f);
	bool setFileUserName(file _f);
	bool setFileLoadTime(file _f);
	bool setFileSaveTime(file _f);
	bool setFileContent(file _f);
	bool setFileType(file _f);
	bool setFileSecrecy(file _f);
	bool setFileIsBorrowed(file _f);
	bool deleteFile(file _f);

	borrowRecord getRecordByGuid(QString guid);
	vector<borrowRecord> getAllRecord();
	vector<borrowRecord> getRecordByUser(user _u);
	vector<borrowRecord> getRocordByFileTitle(file _f);
	bool checkRecord(borrowRecord _bR);
	bool addRecord(borrowRecord _bR);
	bool setBorrowTime(borrowRecord _bR);
	bool setReturnTime(borrowRecord _bR);
	bool setIsReturn(borrowRecord _bR);
	bool setIsDealWith(borrowRecord _bR);
	bool setDealResult(borrowRecord _bR);
	bool deleteRecord(borrowRecord _bR);
	
	~dbHelper();
};
