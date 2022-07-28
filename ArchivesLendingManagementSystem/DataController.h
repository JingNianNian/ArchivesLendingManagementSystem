#pragma once
#include "ALMSHeaderFiles.h"
#include <qstring.h>
class dataControl {
public:
	static void deleteFiles(vector<QString> list);
	static void upUserLevel(vector<QString> list);
	static void downUserLevel(vector<QString> list);
	static void deleteUser(vector<QString> list);
	static void dealRecord(vector<QString> list, bool isOk);
	static vector<QString> getOverdueFiles();
};