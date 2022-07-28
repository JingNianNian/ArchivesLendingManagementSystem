#include "borrowRecoed.h"

borrowRecord::borrowRecord()
{
	guid = QString();
	userName = QString();
	fileTitle = QString();
	borrowTime = myTime();
	borrowTime = myTime();
	isDealWith = dealResult = isReturn = false;
}

borrowRecord::borrowRecord(QString _guid, QString _userName, QString _fileTitle, myTime _borrowTime, myTime _returnTime, bool _isDealWith, bool _dealResult, bool _isReturn)
{
	guid = _guid, userName = _userName, fileTitle = _fileTitle, borrowTime = _borrowTime, returnTime = _returnTime, isDealWith = _isDealWith, dealResult = _dealResult, isReturn = _isReturn;
}

void borrowRecord::setGuid(QString _val)
{
	guid = _val;
}

void borrowRecord::setUserName(QString _val)
{
	userName = _val;
}

void borrowRecord::setFileTitle(QString _val)
{
	fileTitle = _val;
}

void borrowRecord::setBorrowTime(myTime _val)
{
	borrowTime = _val;
}

void borrowRecord::setReturnTime(myTime _val)
{
	returnTime = _val;
}

void borrowRecord::setIsDealWith(bool _val)
{
	isDealWith = _val;
}

void borrowRecord::setDealResult(bool _val)
{
	dealResult = _val;
}

void borrowRecord::setIsReturn(bool _val)
{
	isReturn = _val;
}

QString borrowRecord::getGuid()
{
	return guid;
}

QString borrowRecord::getUserName()
{
	return userName;
}

QString borrowRecord::getFileTitle()
{
	return fileTitle;
}

myTime borrowRecord::getBorrowTime()
{
	return borrowTime;
}

myTime borrowRecord::getReturnTime()
{
	return returnTime;
}

bool borrowRecord::getIsDealWith()
{
	return isDealWith;
}

bool borrowRecord::getDealResult()
{
	return dealResult;
}

bool borrowRecord::getIsReturn()
{
	return isReturn;
}

borrowRecord::~borrowRecord()
{

}