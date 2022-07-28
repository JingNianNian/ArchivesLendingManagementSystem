#include "mylog.h"
#include <shlobj.h>
#include "mytime.h"
#include "MyTime.h"
#include "qdebug.h"
#include <direct.h>
#include <io.h>
QString myLog::myLogPath = QString("");
void myLog::setLogPath()
{
	wchar_t buffer[512];
	SHGetSpecialFolderPath(0, buffer, CSIDL_LOCAL_APPDATA, false);
	auto str = QString("");
	for (auto c : buffer) {
		if (c == '\0') break;
		str += (char)c;
	}
	str += QString("\\ALMS\\");
	if (_access(str.toStdString().c_str(), 0) == -1){
		auto _ = _mkdir(str.toStdString().c_str());
	}
	str += QString("ALMS_log_") + myTime().getTimeStamp() + QString(".log");
	myLogPath = str;
	
}
void myLog::writeInfoLog(QString logContent)
{
	auto mt = myTime();
	auto logC = QString("[INFO] [") + mt.getDateAndTime() + QString("] ") + logContent;
	writeContent(logC.toStdString());
}

void myLog::writeInfoLog(string logContent)
{
	auto mt = myTime();
	auto logC = string("[INFO] [") + mt.getDateAndTime().toStdString() + string("] ") + logContent;
	writeContent(logC);
}

void myLog::writeDebugLog(QString logContent)
{
	auto mt = myTime();
	auto logC = QString("[DEBUG] [") + mt.getDateAndTime() + QString("] ") + logContent;
	writeContent(logC.toStdString());
}

void myLog::writeDebugLog(string logContent)
{
	auto mt = myTime();
	auto logC = string("[DEBUG] [") + mt.getDateAndTime().toStdString() + string("] ") + logContent;
	writeContent(logC);
}

void myLog::writeWarningLog(QString logContent)
{
	auto mt = myTime();
	auto logC = QString("[WARNING] [") + mt.getDateAndTime() + QString("] ") + logContent;
	writeContent(logC.toStdString());
}

void myLog::writeWarningLog(string logContent)
{
	auto mt = myTime();
	auto logC = string("[WARNING] [") + mt.getDateAndTime().toStdString() + string("] ") + logContent;
	writeContent(logC);
}

void myLog::writeErrorLog(QString logContent)
{
	auto mt = myTime();
	auto logC = QString("[ERROR] [") + mt.getDateAndTime() + QString("] ") + logContent;
	writeContent(logC.toStdString());
}

void myLog::writeErrorLog(string logContent)
{
	auto mt = myTime();
	auto logC = string("[ERROR] [") + mt.getDateAndTime().toStdString() + string("] ") + logContent;
	writeContent(logC);
}

void myLog::writeContent(string logContent)
{
	ofstream ofs;
	ofs.open(myLogPath.toStdString().c_str(), ofstream::app);
	ofs << logContent << endl;
	ofs.close();
}
