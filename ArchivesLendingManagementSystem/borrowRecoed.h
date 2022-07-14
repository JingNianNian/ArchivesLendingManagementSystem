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
public:
	borrowRecord();
	borrowRecord(QString _guid, QString _userName, QString _fileTitle, myTime _borrowTime, myTime _returnTime, bool _isDealWith = false, bool _dealResult = false);



	~borrowRecord();
};