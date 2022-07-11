#pragma once
#include "ALMSHeaderFiles.h"

class myTime
{
private:
    //��ǰʱ���
    int timeStamp;
    //��ǰ�꣬�£���
    int year, month, day;
    //��ǰʱ���֣���
    int hh, mm, ss;
    //��ǰ����
    int week;
    //�Ƿ�24Сʱ��
    bool is24Clock = true;
    //�Ƿ���ʱ���
    bool isTimeQuantum = false;
    //���ڸ�ʽ
    string dayFormat = "ymd";
    // ToDo : ʹ��time��localtime��ʱ����и���ֵ
    void setData();
public:
	myTime();//Ĭ�ϳ�ʼ��
    myTime(bool _is24Clock);//�Ƿ�ʹ��12Сʱ
    myTime(bool _is24Clock, string _dayFormat);//�Ƿ�ʹ��12Сʱ����������ĸ�ʽ
    myTime(int _hh, int _mm, int _ss);//��ʼ��һ��ʱ���

	~myTime();
    // ToDo : ����ʱ��
    // ToDo : ��������
    // ToDo : �������ڣ�ʱ��
    // ToDo : ʹ�����������ʵ�ֵ�ǰʱ�����һ��ʱ���
    // ToDo : ʹ�����������ʵ������ʱ��ıȽ�
};