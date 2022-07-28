#include "MyTime.h"

void myTime::setData()
{
	auto st = localtime(&timeStamp);
	year = st->tm_year + 1900;
	month = st->tm_mon + 1;
	day = st->tm_mday;
	hh = st->tm_hour;
	mm = st->tm_min;
	ss = st->tm_sec;
}

myTime::myTime()
{
	timeStamp = time(NULL);
	setData();
}

myTime::myTime(QDateTime q)
{
	timeStamp = q.toTime_t();
	setData();
}

myTime::myTime(time_t _timeStamp)
{
	timeStamp = _timeStamp;
	setData();
}

myTime::myTime(int _hh, int _mm, int _ss)
{
	hh = _hh;
	mm = _mm;
	ss = _ss;
	isTimeQuantum = true;
}

myTime::~myTime()
{
}

QString myTime::getTimeStamp()
{
	return	QString(to_string(timeStamp).c_str());
}

QString myTime::getTime()
{
	auto ret = (hh < 10 ? "0" : "") + to_string(hh) + ":" + (mm < 10 ? "0" : "") + to_string(mm) + ":" + (ss < 10 ? "0" : "") + to_string(ss);
	return QString(ret.c_str());
}

QString myTime::getDate()
{
	auto ret = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
	return QString(ret.c_str());
}

QString myTime::getDateAndTime()
{
	return getDate() + " " + getTime();
}

QDateTime myTime::toQDateTime()
{
	return QDateTime(QDate(year, month, day), QTime(hh, mm, ss));
}

myTime& myTime::operator+=(const myTime& rhs)
{
	if (rhs.isTimeQuantum) {
		this->ss += rhs.ss;
		this->mm += this->ss / 60;
		this->ss %= 60;
		this->mm += rhs.mm;
		this->hh += this->mm / 60;
		this->mm %= 60;
		this->hh += rhs.hh;
		this->day += this->hh / 24;
		this->hh %= 24;
		int f = 1;
		if (f) for (auto x : { 1, 3, 5, 7, 8, 10, 12 }) {
			if (this->month == x) {
				f = 0;
				if (this->day == 32) this->day = 1, this->month++;
				if (this->month == 13)this->month = 1, this->year++;
				break;
			}
		}
		if (f) for (auto x : { 4,6,9,11 }) {
			if (this->month == x) {
				f = 0;
				if (this->day == 31) this->day = 1, this->month++;
				break;
			}
		}
		if (f && this->month == 2) {
			if (this->year % 4 == 0 && this->year % 100 != 0) {
				if(this->day == 30) this->day = 1, this->month++;
			}
			else if (this->year % 400 == 0) {
				if (this->day == 30) this->day = 1, this->month++;
			}
			else {
				if (this->day == 29) this->day = 1, this->month++;
			}
		}
	}
	else {
		//log operation error
	}
	return *this;
}

bool myTime::operator<(const myTime& rhs)
{
	vector<int> a{ this->year, this->month, this->day, this->hh, this->mm, this->ss };
	vector<int> b{ rhs.year, rhs.month, rhs.day, rhs.hh, rhs.mm, rhs.ss };
	for (int i = 0; i < 6; i++) {
		if (a[i] > b[i]) return false;
		else if (a[i] < b[i]) return true;
		else continue;
	}
	return false;
}

bool myTime::operator==(const myTime& rhs)
{
	if (this->day == rhs.day &&
		this->year == rhs.year &&
		this->month == rhs.month &&
		this->hh == rhs.hh &&
		this->mm == rhs.mm &&
		this->ss == rhs.ss)return true;
	return false;
}

bool myTime::operator>(const myTime& rhs)
{
	vector<int> a{ this->year, this->month, this->day, this->hh, this->mm, this->ss };
	vector<int> b{ rhs.year, rhs.month, rhs.day, rhs.hh, rhs.mm, rhs.ss };
	for (int i = 0; i < 6; i++) {
		if (a[i] < b[i]) return false;
		else if (a[i] > b[i]) return true;
		else continue;
	}
	return false;
}

bool myTime::operator>=(const myTime& rhs)
{
	return ((*this) > rhs) || ((*this) == rhs);
}

bool myTime::operator<=(const myTime& rhs)
{
	return ((*this) < rhs) || ((*this) == rhs);
}