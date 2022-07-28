#pragma once
#include "ALMSHeaderFiles.h"
#include <qstring.h>

using namespace std;
class myLog {
public:
	static QString myLogPath;
	//static ofstream ofs;

	static void setLogPath();
	
	static void writeInfoLog(QString logContent);
	static void writeInfoLog(string logContent);
	static void writeDebugLog(QString logContent);
	static void writeDebugLog(string logContent);
	static void writeWarningLog(QString logContent);
	static void writeWarningLog(string logContent);
	static void writeErrorLog(QString logContent);
	static void writeErrorLog(string logContent);

	static void writeContent(string logContent);
};