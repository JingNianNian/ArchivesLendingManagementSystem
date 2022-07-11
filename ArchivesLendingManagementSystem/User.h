#pragma once
#include "ALMSHeaderFiles.h"

class user
{
private:
	string userName;
	string passwordMd5;
	string userPhoneNumber;
	int userLevel;
public:
	user();
	user(string _userName, string _passwordMd5, string _userPhoneNumber, int _userLevel);
	
	void setUserName(string _userName);
	string getUserName();

	void setUserPassword(string _userPasswordMd5);
	string getUserPassword();

	void setUserPhoneNumber(string _userPhoneNumber);
	string getUserPhoneNumber();

	void setUserLevel(int _userLevel);
	int getUserLevel();

	~user();
};
