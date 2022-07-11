#pragma once

#include "DBHelper.h"

dbHelper::dbHelper()
{
	
}

bool dbHelper::openDB(string host, string odbcName, string userName, string password)
{

	db.setHostName(host.c_str());
	db.setDatabaseName(odbcName.c_str());
	db.setUserName(userName.c_str());
	db.setPassword(password.c_str());

	if (db.open()) {
		// log successed
		open = true;
		qDebug() << "open database successed";
		return true;
	}
	else {
		// log failed
		qDebug() << "open database failed";
		return false;
	}
}

bool dbHelper::closeDB()
{
	if (open) {
		// log close
		db.close();
		return true;
	}
	else {
		// log not open
		return false;
	}

}

bool dbHelper::checkLogin(string userName, string password)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = ("select * from userTable where userName = '" + userName + "'").c_str();
		if (qry.exec(qs))
		{
			if (qry.next()) 
			{
				if (password == qry.value(1).toString().toStdString()) 
				{
					//log user success login
					qDebug() << "login successed";
					return true;
				}
				else 
				{
					//log user fail login
					qDebug() << "login failed";
					return false;
				}
			}
			else {
				// log ?
				return false;
			}
			
		}
		else 
		{
			//log ?
			return false;
		}
		
	}
	catch (const std::exception& e)
	{
		//log exception
		qDebug() << e.what();
	}

}

user dbHelper::getUser(string userName)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = ("select * from userTable where userName = '" + userName + "'").c_str();
		if (qry.exec(qs))
		{
			if (qry.next()) {
				user ret = user(
					qry.value(0).toString().toStdString(), 
					qry.value(1).toString().toStdString(), 
					qry.value(2).toString().toStdString(), 
					qry.value(3).toString().toShort()
				);
				//log ok
				return ret;
			}
			else {
				//log notfound
				return user();
			}
		}
		else
		{
			//log exec error
			return user();
		}
	}
	catch (const std::exception& e)
	{
		qDebug() << e.what();
	}
}

vector<user> dbHelper::getAllUser(user _u)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = "select * from userTable";
		if (qry.exec(qs)) 
		{
			vector<user> ret;
			while (qry.next()) {
				ret.push_back(user(
					qry.value(0).toString().toStdString(),
					qry.value(1).toString().toStdString(),
					qry.value(2).toString().toStdString(),
					qry.value(3).toString().toShort()
				));
			}
			//log ok
			return ret;
		}
		else
		{
			//log exec error
			return vector<user>();
		}
	}
	catch (const std::exception& e)
	{
		//log runtime error
		qDebug() << e.what();
	}
}

bool dbHelper::checkUser(user _u)
{
	try
	{
		QString name = _u.getUserName().c_str();
		QSqlQuery qry(db);
		QString qs = "select * from userTable where userName = '" + name + "'";
		if (qry.exec(qs)) {
			if (qry.next()) {
				//log ok
				return true;
			}
			else {
				//log false
				return false;
			}
		}
		else {
			//log exec error
			return false;
		}
	}
	catch (const std::exception& e)
	{
		//log runtime error
		qDebug() << e.what();
	}
}

bool dbHelper::addUser(user _u)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("insert into userTable values('%1', '%2', '%3', %4)").
			arg(_u.getUserName().c_str()).
			arg(_u.getUserPassword().c_str()).
			arg(_u.getUserPhoneNumber().c_str()).
			arg(_u.getUserLevel());
		if (qry.exec(qs)) {
			//log
			return true;
		}
		else {
			//log
			return false;
		}
	}
	catch (const std::exception& e)
	{
		qDebug() << e.what();
	}
}

bool dbHelper::setUserPassword(user _u)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update userTable set userPassword = '%1' where userName = '%2'").
			arg(_u.getUserPassword().c_str()).
			arg(_u.getUserName().c_str());
		if (qry.exec(qs)) {
			//log
			return true;
		}
		else {
			//log
			return false;
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

bool dbHelper::setUserLevel(user _u)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update userTable set userLevel = %1 where userName = '%2'").
			arg(_u.getUserLevel()).
			arg(_u.getUserName().c_str());
		if (qry.exec(qs)) {
			//log
			return true;
		}
		else {
			//log
			return false;
		}
	}
	catch (const std::exception& e)
	{
		qDebug() << e.what();
	}
}

bool dbHelper::setUserPhoneNumber(user _u)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update userTable set userPhoneNumber = '%1' where userName = '%2'").
			arg(_u.getUserPhoneNumber().c_str()).
			arg(_u.getUserName().c_str());
		if (qry.exec(qs)) {
			//log
			return true;
		}
		else {
			//log
			return false;
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

file dbHelper::getFileByTitle(string fileTitle)
{
	try
	{

	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

vector<file> dbHelper::getAllFile()
{
	return vector<file>();
}

vector<file> dbHelper::getFilesByUser(string userName)
{
	return vector<file>();
}

vector<file> dbHelper::getFilesByTime(myTime start, myTime end)
{
	return vector<file>();
}

bool dbHelper::checkFile(file _f)
{
	return false;
}

bool dbHelper::addFile(file _f)
{
	return false;
}

bool dbHelper::setFileTitle(file _f)
{
	return false;
}

bool dbHelper::setFileUserName(file _f)
{
	return false;
}

bool dbHelper::setFileLoadTime(file _f)
{
	return false;
}

bool dbHelper::setFileSaveTime(file _f)
{
	return false;
}

bool dbHelper::setFileContent(file _f)
{
	return false;
}

bool dbHelper::setFileType(file _f)
{
	return false;
}

bool dbHelper::setFileSecrecy(file _f)
{
	return false;
}

bool dbHelper::setFileIsBorrowed(file _f)
{
	return false;
}

borrowRecord dbHelper::getRecordByGuid(string guid)
{
	return borrowRecord();
}

vector<borrowRecord> dbHelper::getAllRecord()
{
	return vector<borrowRecord>();
}

vector<borrowRecord> dbHelper::getRecordByUser(user _u)
{
	return vector<borrowRecord>();
}

vector<borrowRecord> dbHelper::getUnDealRecord()
{
	return vector<borrowRecord>();
}

vector<borrowRecord> dbHelper::getDealRecord()
{
	return vector<borrowRecord>();
}

vector<borrowRecord> dbHelper::getRocordByFileTitle(file _f)
{
	return vector<borrowRecord>();
}

vector<borrowRecord> dbHelper::getOutOfLimitTimeRecord(myTime _t)
{
	return vector<borrowRecord>();
}

bool dbHelper::checkRecord(borrowRecord _bR)
{
	return false;
}

bool dbHelper::addRecord(borrowRecord _bR)
{
	return false;
}

bool dbHelper::setBorrowTime(borrowRecord _bR)
{
	return false;
}

bool dbHelper::setReturnTime(borrowRecord _bR)
{
	return false;
}

bool dbHelper::setIsDealWith(borrowRecord _bR)
{
	return false;
}

bool dbHelper::setDealResult(borrowRecord _bR)
{
	return false;
}

dbHelper::~dbHelper()
{

}