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
    // ToDo : 使用time及localtime对时间进行赋初值(设置为现在的时间)
    void setData();
public:
	myTime();//默认初始化
    myTime(QDateTime q);
    myTime(time_t _timeStamp);//通过timeStamp初始化
    myTime(int _hh, int _mm, int _ss);//初始化一个时间段

	~myTime();

    QString getTimeStamp();
    // ToDo : 返回时间
    QString getTime();
    // ToDo : 返回日期
    QString getDate();
    // ToDo : 返回日期＋时间
    QString getDateAndTime();
    QDateTime toQDateTime();
    // ToDo : 使用运算符重载实现当前时间加上一个时间段
    myTime& operator += (const myTime& rhs);
    // ToDo : 使用运算符重载实现两个时间的比较
    bool operator < (const myTime& rhs);
    bool operator == (const myTime& rhs);
    bool operator > (const myTime& rhs);
    bool operator >= (const myTime& rhs);
    bool operator <= (const myTime& rhs);
};