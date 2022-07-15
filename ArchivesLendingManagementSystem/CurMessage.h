#pragma once
#include "ALMSHeaderFiles.h"
#include "dbhelper.h"
class curMessage {
public:
	static user curUser;
	static dbHelper db;
	static void setCurUser(user _u) {
		curUser = _u;
	};
	static void setDbHelper(dbHelper _db) {
		db = _db;
	};
};