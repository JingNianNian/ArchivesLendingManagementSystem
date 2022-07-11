#include "User.h"
#include <qdebug.h>
user::user()
{
	userName = passwordMd5 = userPhoneNumber = "";
	userLevel = 2;
}

user::user(string _userName, string _passwordMd5, string _userPhoneNumber, int _userLevel)
{
	userName = _userName;
	passwordMd5 = _passwordMd5;
	userPhoneNumber = _userPhoneNumber;
	userLevel = _userLevel;
}

void user::setUserName(string _userName)
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

string user::getUserName()
{
	return userName;
}

void user::setUserPassword(string _userPasswordMd5)
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

string user::getUserPassword()
{
	return passwordMd5;
}

void user::setUserPhoneNumber(string _userPhoneNumber)
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

string user::getUserPhoneNumber()
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
