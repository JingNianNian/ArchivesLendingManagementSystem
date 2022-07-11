#pragma once
#include "ALMSHeaderFiles.h"
#include "User.h"
#include "MyTime.h"
#include "File.h"

class borrowRecord
{
private:
	string guid;
	string userName;
	string fileTitle;
	myTime borrowTime;
	myTime returnTime;
	bool isDealWith;
	bool dealResult;
public:
	borrowRecord();



	~borrowRecord();
};