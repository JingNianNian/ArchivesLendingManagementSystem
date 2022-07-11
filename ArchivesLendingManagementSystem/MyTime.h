#pragma once
#include "ALMSHeaderFiles.h"

class myTime
{
private:
    //当前时间戳
    int timeStamp;
    //当前年，月，日
    int year, month, day;
    //当前时，分，秒
    int hh, mm, ss;
    //当前星期
    int week;
    //是否24小时制
    bool is24Clock = true;
    //是否是时间段
    bool isTimeQuantum = false;
    //日期格式
    string dayFormat = "ymd";
    // ToDo : 使用time及localtime对时间进行赋初值
    void setData();
public:
	myTime();//默认初始化
    myTime(bool _is24Clock);//是否使用12小时
    myTime(bool _is24Clock, string _dayFormat);//是否使用12小时，日期输出的格式
    myTime(int _hh, int _mm, int _ss);//初始化一个时间段

	~myTime();
    // ToDo : 返回时间
    // ToDo : 返回日期
    // ToDo : 返回日期＋时间
    // ToDo : 使用运算符重载实现当前时间加上一个时间段
    // ToDo : 使用运算符重载实现两个时间的比较
};