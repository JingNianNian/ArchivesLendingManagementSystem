#pragma once
#include "ALMSHeaderFiles.h"
#include <qstring.h>
#include "qdatetime.h"
class myTime
{
private:
    time_t timeStamp;
    //��ǰ�꣬�£���
    int year, month, day;
    //��ǰʱ���֣���
    int hh, mm, ss;
    //�Ƿ���ʱ���
    bool isTimeQuantum = false;
    void setData();
public:
	myTime();//Ĭ�ϳ�ʼ��
    myTime(QDateTime q);
    myTime(time_t _timeStamp);//ͨ��timeStamp��ʼ��
    myTime(int _hh, int _mm, int _ss);//��ʼ��һ��ʱ���

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