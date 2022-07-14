#pragma once
#include "ALMSHeaderFiles.h"
#include <qstring.h>
class user
{
private:
	QString userName;
	QString passwordMd5;
	QString userPhoneNumber;
	int userLevel;
public:
	user();
	user(QString _userName, QString _passwordMd5, QString _userPhoneNumber, int _userLevel);
	
	void setUserName(QString _userName);
	QString getUserName();

	void setUserPassword(QString _userPasswordMd5);
	QString getUserPassword();

	void setUserPhoneNumber(QString _userPhoneNumber);
	QString getUserPhoneNumber();

	void setUserLevel(int _userLevel);
	int getUserLevel();

	~user();
};
