#pragma once
#include "ALMSHeaderFiles.h"
#include <qstring.h>
#include "qdatetime.h"
class myTime
{
private:
    time_t timeStamp;
    //当前年，月，日
    int year, month, day;
    //当前时，分，秒
    int hh, mm, ss;
    //是否是时间段
    bool isTimeQuantum = false;
    void setData();
public:
	myTime();//默认初始化
    myTime(QDateTime q);
    myTime(time_t _timeStamp);//通过timeStamp初始化
    myTime(int _hh, int _mm, int _ss);//初始化一个时间段

	~myTime();

    QString getTimeStamp();
    QString getTime();
    QString getDate();
    QString getDateAndTime();
    QDateTime toQDateTime();
    myTime& operator += (const myTime& rhs);
    bool operator < (const myTime& rhs);
    bool operator == (const myTime& rhs);
    bool operator > (const myTime& rhs);
    bool operator >= (const myTime& rhs);
    bool operator <= (const myTime& rhs);
};