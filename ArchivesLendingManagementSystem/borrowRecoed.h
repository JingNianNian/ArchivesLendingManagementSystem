#pragma once
#include "ALMSHeaderFiles.h"
#include "User.h"
#include "MyTime.h"
#include "File.h"
#include <qstring.h>

class borrowRecord
{
private:
	QString guid;
	QString userName;
	QString fileTitle;
	myTime borrowTime;
	myTime returnTime;
	bool isDealWith;
	bool dealResult;
	bool isReturn;
public:
	borrowRecord();
	borrowRecord(QString _guid, QString _userName, QString _fileTitle, myTime _borrowTime, myTime _returnTime, bool _isDealWith = false, bool _dealResult = false, bool _isReturn = false);

	void setGuid(QString _val);
	void setUserName(QString _val);
	void setFileTitle(QString _val);
	void setBorrowTime(myTime _val);
	void setReturnTime(myTime _val);
	void setIsDealWith(bool _val);
	void setDealResult(bool _val);
	void setIsReturn(bool _val);
	QString getGuid();
	QString getUserName();
	QString getFileTitle();
	myTime getBorrowTime();
	myTime getReturnTime();
	bool getIsDealWith();
	bool getDealResult();
	bool getIsReturn();

	~borrowRecord();
};