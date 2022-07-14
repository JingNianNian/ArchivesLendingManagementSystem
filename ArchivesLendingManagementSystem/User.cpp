#include "User.h"
#include <qdebug.h>
user::user()
{
	userName = passwordMd5 = userPhoneNumber = "";
	userLevel = 2;
}

user::user(QString _userName, QString _passwordMd5, QString _userPhoneNumber, int _userLevel)
{
	userName = _userName;
	passwordMd5 = _passwordMd5;
	userPhoneNumber = _userPhoneNumber;
	userLevel = _userLevel;
}

void user::setUserName(QString _userName)
{
	try
	{
		userName = _userName;
	}
	catch (const std::exception& e)
	{
		// log
		qDebug() << e.what();
	}
}

QString user::getUserName()
{
	return userName;
}

void user::setUserPassword(QString _userPasswordMd5)
{
	try
	{
		passwordMd5 = _userPasswordMd5;
	}
	catch (const std::exception& e)
	{
		// log
		qDebug() << e.what();
	}
}

QString user::getUserPassword()
{
	return passwordMd5;
}

void user::setUserPhoneNumber(QString _userPhoneNumber)
{
	try
	{
		userPhoneNumber = _userPhoneNumber;
	}
	catch (const std::exception& e)
	{
		// log
		qDebug() << e.what();
	}
}

QString user::getUserPhoneNumber()
{
	return userPhoneNumber;
}

void user::setUserLevel(int _userLevel)
{
	try
	{
		userLevel = _userLevel;
	}
	catch (const std::exception& e)
	{
		// log
		qDebug() << e.what();
	}
}

int user::getUserLevel()
{
	return userLevel;
}

user::~user()
{
}
