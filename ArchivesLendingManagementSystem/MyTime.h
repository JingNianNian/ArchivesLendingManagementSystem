#pragma once
#include "ALMSHeaderFiles.h"

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
    // ToDo : ʹ��time��localtime��ʱ����и���ֵ(����Ϊ���ڵ�ʱ��)
    void setData();
public:
	myTime();//Ĭ�ϳ�ʼ��
    myTime(int _timeStamp);//ͨ��string��ʼ��
    myTime(int _hh, int _mm, int _ss);//��ʼ��һ��ʱ���

	~myTime();

    string getTimeStamp();
    // ToDo : ����ʱ��
    string getTime();
    // ToDo : ��������
    string getDate();
    // ToDo : �������ڣ�ʱ��
    string getDateAndTime();
    // ToDo : ʹ�����������ʵ�ֵ�ǰʱ�����һ��ʱ���
    myTime& operator += (const myTime& rhs);
    // ToDo : ʹ�����������ʵ������ʱ��ıȽ�
    bool operator < (const myTime& rhs);
    bool operator = (const myTime& rhs);
    bool operator > (const myTime& rhs);
};