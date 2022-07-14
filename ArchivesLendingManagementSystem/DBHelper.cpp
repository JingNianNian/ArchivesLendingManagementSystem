#pragma once

#include "DBHelper.h"

dbHelper::dbHelper()
{
	
}

bool dbHelper::openDB(QString host, QString odbcName, QString userName, QString password)
{
	db.setHostName(host);
	db.setDatabaseName(odbcName);
	db.setUserName(userName);
	db.setPassword(password);

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

bool dbHelper::checkLogin(QString userName, QString password)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from userTable where userName = '%1'").arg(userName);
		if (qry.exec(qs))
		{
			if (qry.next()) 
			{
				if (password == qry.value(1).toString())
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

user dbHelper::getUser(QString userName)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from userTable where userName = '%1'").arg(userName);
		if (qry.exec(qs))
		{
			if (qry.next()) {
				user ret = user(
					qry.value(0).toString(), 
					qry.value(1).toString(), 
					qry.value(2).toString(), 
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

vector<user> dbHelper::getAllUser()
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
					qry.value(0).toString(),
					qry.value(1).toString(),
					qry.value(2).toString(),
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
		QString userName = _u.getUserName();
		QSqlQuery qry(db);
		QString qs = QString("select * from userTable where userName = '%1'").arg(userName);
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
			arg(_u.getUserName()).
			arg(_u.getUserPassword()).
			arg(_u.getUserPhoneNumber()).
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
			arg(_u.getUserPassword()).
			arg(_u.getUserName());
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
			arg(_u.getUserName());
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
			arg(_u.getUserPhoneNumber()).
			arg(_u.getUserName());
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

bool dbHelper::deleteUser(user _u)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("delete userTable where userName = '%1'").arg(_u.getUserName());
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

file dbHelper::getFileByTitle(QString fileTitle)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from fileTable where fileTitle = '%1'").arg(fileTitle);
		if (qry.exec(qs)) {
			if (qry.next()) {
				file ret = file(
					qry.value(0).toString(),
					qry.value(1).toString(),
					myTime(qry.value(2).toString().toInt()),
					myTime(qry.value(3).toString().toInt()),
					qry.value(4).toString(),
					qry.value(5).toString().toShort(),
					qry.value(6).toString().toShort(),
					qry.value(7).toString().toShort()
				);
				//log
				return ret;
			}
			else {
				// log
				return file();
			}
		}
		else {
			//log
			return file();
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

vector<file> dbHelper::getAllFile()
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from fileTable");
		if (qry.exec(qs)) {
			vector<file> ret;
			while (qry.next()) {
				ret.push_back(
					file(
						qry.value(0).toString(),
						qry.value(1).toString(),
						myTime(qry.value(2).toString().toInt()),
						myTime(qry.value(3).toString().toInt()),
						qry.value(4).toString(),
						qry.value(5).toString().toShort(),
						qry.value(6).toString().toShort(),
						qry.value(7).toString().toShort()
					)
				);
			}
			//log
			return ret;
		}
		else {
			//log
			return vector<file>();
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

vector<file> dbHelper::getFilesByUser(QString userName)
{
	
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from fileTable where userName = '%1'").arg(userName);
		if (qry.exec(qs)) {
			vector<file> ret;
			while (qry.next())
			{
				ret.push_back(
					file(
						qry.value(0).toString(),
						qry.value(1).toString(),
						myTime(qry.value(2).toString().toShort()),
						myTime(qry.value(3).toString().toShort()),
						qry.value(4).toString(),
						qry.value(5).toString().toShort(),
						qry.value(6).toString().toShort(),
						qry.value(7).toString().toShort()
					)
				);
			}
			//log
			return ret;
		}
		else {
			//log
			return vector<file>();
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

vector<file> dbHelper::getFilesByTime(myTime start, myTime end)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from fileTable");
		if (qry.exec(qs)) {
			vector<file> ret;
			while (qry.next()) {
				auto f = file(
					qry.value(0).toString(),
					qry.value(1).toString(),
					myTime(qry.value(2).toString().toShort()),
					myTime(qry.value(3).toString().toShort()),
					qry.value(4).toString(),
					qry.value(5).toString().toShort(),
					qry.value(6).toString().toShort(),
					qry.value(7).toString().toShort()
				);
				myTime mt = f.getLoadTime();
				
				if (mt > start && mt < end) {
					ret.push_back(f);
				}
			}
			return ret;
		}
		else {
			//log
			return vector<file>();
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

bool dbHelper::checkFile(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from fileTable where fileTitle = '%1'").arg(_f.getFileTitle());
		if (qry.exec(qs)) {
			if (qry.next()) {
				//log
				return true;
			}
			else {
				//log
				return false;
			}
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

bool dbHelper::addFile(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs =
			QString("insert into fileTable values('%1', '%2', '%3', '%4', '%5', %6, %7, %8)").
			arg(_f.getFileTitle()).
			arg(_f.getUserName()).
			arg(_f.getLoadTime().getTimeStamp()).
			arg(_f.getSaveTime().getTimeStamp()).
			arg(_f.getFileContent()).
			arg(_f.getFileType()).
			arg(_f.getFileSecrecy()).
			arg(_f.getIsBorrowed());
		if (qry.exec(qs)) {
			return true;
		}
		else {
			return false;
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

bool dbHelper::setFileUserName(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update fileTable set userName = '%1' where fileTitle = '%2'").
			arg(_f.getUserName()).
			arg(_f.getFileTitle());
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

bool dbHelper::setFileLoadTime(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update fileTable set loadTime = '%1' where fileTitle = '%2'").
			arg(_f.getLoadTime().getTimeStamp()).
			arg(_f.getFileTitle());
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

bool dbHelper::setFileSaveTime(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update fileTable set saveTime = '%1' where fileTitle = '%2'").
			arg(_f.getSaveTime().getTimeStamp()).
			arg(_f.getFileTitle());
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

bool dbHelper::setFileContent(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update fileTable set FileContent = '%1' where fileTitle = '%2'").
			arg(_f.getFileContent()).
			arg(_f.getFileTitle());
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

bool dbHelper::setFileType(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update fileTable set fileType = '%1' where fileTitle = '%2'").
			arg(_f.getFileType()).
			arg(_f.getFileTitle());
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

bool dbHelper::setFileSecrecy(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update fileTable set fileSecrecy = '%1' where fileTitle = '%2'").
			arg(_f.getFileSecrecy()).
			arg(_f.getFileTitle());
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

bool dbHelper::setFileIsBorrowed(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update fileTable set isBorrowed = '%1' where fileTitle = '%2'").
			arg(_f.getIsBorrowed()).
			arg(_f.getFileTitle());
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

bool dbHelper::deleteFile(file _f)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("delete from fileTable where fileTitle = '%1'").arg(_f.getFileTitle());
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

borrowRecord dbHelper::getRecordByGuid(QString guid)
{

	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from borrowRecordTable where guid = '%1'").arg(guid);
		if (qry.exec(qs)) {
			if (qry.next()) {
					borrowRecord ret = borrowRecord(
					qry.value(0).toString(),
					qry.value(1).toString(),
					qry.value(2).toString(),
					myTime(qry.value(3).toString().toInt()),
					myTime(qry.value(4).toString().toInt()),
					qry.value(5).toString().toShort(),
					qry.value(6).toString().toShort()
				);
				//log
				return ret;
			}
			else {
				// log
				return borrowRecord();
			}
		}
		else {
			//log
			return borrowRecord();
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}

	
}

vector<borrowRecord> dbHelper::getAllRecord()
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from borrowRecordTable");
		if (qry.exec(qs)) {
			vector<borrowRecord> ret;
			while (qry.next()) {
				ret.push_back(
					borrowRecord(
						qry.value(0).toString(),
						qry.value(1).toString(),
						qry.value(2).toString(),
						myTime(qry.value(3).toString().toInt()),
						myTime(qry.value(4).toString().toInt()),
						qry.value(5).toString().toShort(),
						qry.value(6).toString().toShort()
						
					)
				);
			}
			//log
			return ret;
		}
		else {
			//log
			return vector<borrowRecord>();
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
	
}

vector<borrowRecord> dbHelper::getRecordByUser(user _u)
{

	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from borrowRecordTable where userName = '%1'").arg(_u.getUserName());
		if (qry.exec(qs)) {
			vector<borrowRecord> ret;
			while (qry.next())
			{
				ret.push_back(
					borrowRecord(
						qry.value(0).toString(),
						qry.value(1).toString(),
						qry.value(2).toString(),
						myTime(qry.value(3).toString().toInt()),
						myTime(qry.value(4).toString().toInt()),
						qry.value(5).toString().toShort(),
						qry.value(6).toString().toShort()
					)
				);
			}
			//log
			return ret;
		}
		else {
			//log
			return vector<borrowRecord>();
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
	
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
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("select * from borrowRecordTable where fileTitle = '%1'").arg(_f.getFileTitle());
		if (qry.exec(qs)) {
			vector<borrowRecord> ret;
			while (qry.next())
			{
				ret.push_back(
					borrowRecord(
						qry.value(0).toString(),
						qry.value(1).toString(),
						qry.value(2).toString(),
						myTime(qry.value(3).toString().toInt()),
						myTime(qry.value(4).toString().toInt()),
						qry.value(5).toString().toShort(),
						qry.value(6).toString().toShort()
					)
				);
			}
			//log
			return ret;
		}
		else {
			//log
			return vector<borrowRecord>();
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

vector<borrowRecord> dbHelper::getOutOfLimitTimeRecord(myTime _t)
{
	return vector<borrowRecord>();
}

bool dbHelper::checkRecord(borrowRecord _bR)
{

	try
	{/*
		QSqlQuery qry(db);
		QString qs = QString("select * from  borrowRecordTable where guid = '%1'").arg(_bR.getGuid());
		if (qry.exec(qs)) {
			if (qry.next()) {
				//log
				return true;
			}
			else {
				//log
				return false;
			}
		}
		else {
			//log
			return false;
		}*/
		return false;
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
	
}
/*
bool dbHelper::addRecord(borrowRecord _bR)
{
	try
	{
		QSqlQuery qry(db);
		QString qs =
			QString("insert into borrowRecordTable values('%1', '%2', '%3', '%4', '%5', %6, %7)").
			arg(_bR.getGuid()).
			arg(_bR.getUserName()).
			arg(_bR.getFileTitle()).
			arg(_bR.getBorrowTime().getTimeStamp()).
			arg(_bR.getReturnTime().getTimeStamp()).
			arg(_bR.getIsDealWith()).
			arg(_bR.getDealResult());
		
		if (qry.exec(qs)) {
			return true;
		}
		else {
			return false;
		}
	}
	catch (const std::exception& e)
	{
		//log
		qDebug() << e.what();
	}
}

bool dbHelper::setBorrowTime(borrowRecord _bR)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update borrowRecordTable set borrowTime = '%1' where guid = '%2'").
			arg(_bR.getBorrowTime()).
			arg(_bR.getGuid());
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

bool dbHelper::setReturnTime(borrowRecord _bR)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update borrowRecordTable set returnTime = '%1' where guid = '%2'").
			arg(_bR.getBorrowTime()).
			arg(_bR.getGuid());
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

bool dbHelper::setIsDealWith(borrowRecord _bR)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update borrowRecordTable set isDealWith = '%1' where guid = '%2'").
			arg(_bR.getIsDealWith()).
			arg(_bR.getGuid());
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

bool dbHelper::setDealResult(borrowRecord _bR)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("update borrowRecordTable set dealResult = '%1' where guid = '%2'").
			arg(_bR.getDealResult()).
			arg(_bR.getGuid());
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

bool dbHelper::deleteRecord(borrowRecord _bR)
{
	try
	{
		QSqlQuery qry(db);
		QString qs = QString("delete borrowRecordTable  where guid = '%1'").arg(_bR.getGuid());
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

dbHelper::~dbHelper()
{

}
*/

dbHelper::~dbHelper()
{
}
