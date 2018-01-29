#include "HtDateTime.h"

#ifndef WIN32

#include <ctime>
extern "C" int gettimeofday( struct timeval *tv, struct timezone *tz );

#include <stdio.h>
#include <stdlib.h>

#endif

static bool m_bHasSrand = false;

HtDateTime::HtDateTime()
{
	this->Year = 1900;//1970;
	this->Month = 1;
	this->Day = 1;
	this->Hour = 0;//8;
	this->Minute = 0;
	this->Second = 0;
	this->MillSecond = 0;
}

HtDateTime::HtDateTime(char* initTimeStr)
{
	*this = HtDateTime::StrConvertToHtDateTime(initTimeStr);
}

HtDateTime::~HtDateTime()
{
}


/************************************************************************/
/* 公有成员函数                                                         */
/************************************************************************/

string HtDateTime::ToString()
{
	char buf[24] = "\0";
	if (this->MillSecond == 0)
	{
#ifdef WIN32
		sprintf_s(buf, "%04d-%02d-%02d %02d:%02d:%02d", this->Year, this->Month, this->Day, this->Hour, this->Minute, this->Second);
		//sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", this->Year, this->Month, this->Day, this->Hour, this->Minute, this->Second);
#else
		sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", this->Year, this->Month, this->Day, this->Hour, this->Minute, this->Second);
#endif
	}
	else
	{
#ifdef WIN32
		sprintf_s(buf, "%04d-%02d-%02d %02d:%02d:%02d.%03d", this->Year, this->Month, this->Day, this->Hour, this->Minute, this->Second, this->MillSecond);
		//sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d.%03d", this->Year, this->Month, this->Day, this->Hour, this->Minute, this->Second, this->MillSecond);
#else
		sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d.%03d", this->Year, this->Month, this->Day, this->Hour, this->Minute, this->Second, this->MillSecond);
#endif
	}
	return HtString::StrConvert(buf);
}

string HtDateTime::ToString(string fmt)
{
	string stryear = HtString::StrConvertFromInt(getYear());
	fmt = HtString::StrReplaceAll(fmt, "yyyy", stryear);
	fmt = HtString::StrReplaceAll(fmt, "yy", HtString::StrRight(stryear, 2));

	string strmoneth = HtString::StrConvertFromInt(getMonth());
	fmt = HtString::StrReplaceAll(fmt, "MM", HtString::StrRight("0" + strmoneth, 2));
	fmt = HtString::StrReplaceAll(fmt, "M", strmoneth);

	string strday = HtString::StrConvertFromInt(getDay());
	fmt = HtString::StrReplaceAll(fmt, "dd", HtString::StrRight("0" + strday, 2));
	fmt = HtString::StrReplaceAll(fmt, "d", strday);

	string strhour = HtString::StrConvertFromInt(getHour());
	fmt = HtString::StrReplaceAll(fmt, "HH", HtString::StrRight("0" + strhour, 2));
	fmt = HtString::StrReplaceAll(fmt, "H", strhour);

	string strminute = HtString::StrConvertFromInt(getMinute());
	fmt = HtString::StrReplaceAll(fmt, "mm", HtString::StrRight("0" + strminute, 2));
	fmt = HtString::StrReplaceAll(fmt, "m", strminute);

	string strsecond = HtString::StrConvertFromInt(getSecond());
	fmt = HtString::StrReplaceAll(fmt, "ss", HtString::StrRight("0" + strsecond, 2));
	fmt = HtString::StrReplaceAll(fmt, "s", strsecond);

	string strmillsecond = HtString::StrConvertFromInt(getMillSecond());
	fmt = HtString::StrReplaceAll(fmt, "fff", HtString::StrRight("00" + strmillsecond, 3));

	return fmt;
}

long long HtDateTime::DiffSeconds(HtDateTime starttime)
{
	int millsecd = 0;
	return (long long)difftime(HtDateTimeConvertToTimet(*this, millsecd), HtDateTimeConvertToTimet(starttime, millsecd));
}

long long HtDateTime::DiffMillSeconds(HtDateTime starttime)
{
	long long diffnum = DiffSeconds(starttime);
	diffnum *= 1000;
	diffnum += this->MillSecond - starttime.MillSecond;
	return diffnum;
}

HtDateTime HtDateTime::AddMillSeconds(long long addnum)
{
	int millsecd = 0;
	time_t tb = HtDateTime::HtDateTimeConvertToTimet(*this, millsecd);
	tb += addnum / 1000;
	millsecd += (int)(addnum % 1000);
	tb += millsecd / 1000;
	if (millsecd >= 0)
	{
		millsecd = millsecd % 1000;
	}
	else
	{
		tb--;
		millsecd = 1000 + millsecd % 1000;
	}
	HtDateTime rt = HtDateTime::TimetConvertToHtDateTime(tb, millsecd);
	return rt;
}

HtDateTime HtDateTime::AddSeconds(long long addnum)
{
	long long millsecpersec = 1000;
	millsecpersec *= addnum;
	return AddMillSeconds(millsecpersec);
}

HtDateTime HtDateTime::AddSeconds(int addnum)
{
	return AddSeconds((long long)addnum);
}

HtDateTime HtDateTime::AddMinutes(int addnum)
{
	return AddSeconds(60 * addnum);
}

HtDateTime HtDateTime::AddHours(int addnum)
{
	return AddMinutes(60 * addnum);
}

HtDateTime HtDateTime::AddDays(int addnum)
{
	return AddHours(24 * addnum);
}

HtDateTime HtDateTime::AddMonths(int addnum)
{
	int daynum = 0;
	HtDateTime monthStart;
	if (addnum >= 0)
	{
		monthStart = AddDays(1 - getDay());
		int y = monthStart.Year;
		int m = monthStart.Month;
		for(int i=1;i<=addnum;i++)
		{
			daynum += GetDayNumOfMonth(y, m);

			m++;
			if (m > 12)
			{
				m = 1;
				y++;
			}
		}
		int lastAddDays = GetDayNumOfMonth(y, m);
		if (lastAddDays > getDay())
			lastAddDays = getDay();
		daynum += lastAddDays - 1;
	}
	else
	{
		monthStart = AddDays(1 - getDay());
		int y = monthStart.Year;
		int m = monthStart.Month;
		for(int i=1;i<=abs(addnum);i++)
		{
			m--;
			if (m <= 0)
			{
				m = 12;
				y--;
			}

			daynum -= GetDayNumOfMonth(y, m);
		}
		int lastAddDays = GetDayNumOfMonth(y, m);
		if (lastAddDays > getDay())
			lastAddDays = getDay();
		daynum += lastAddDays - 1;
	}

	return monthStart.AddDays(daynum);
}

HtDateTime HtDateTime::AddYears(int addnum)
{
	return AddMonths(12 * addnum);
}

/************************************************************************/
/* 公有静态函数                                                         */
/************************************************************************/

char HtDateTime::GetDayNumOfMonth(short year, char month)
{
	char mthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month >= 1 && month <= 12)
	{
		char daynum = mthdays[month - 1];

		if (month == 2)
		{
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
			{
				daynum++;
			}
		}

		return daynum;
	}
	else
		return 0;
}

short HtDateTime::GetDayNumOfYear(short year)
{
	short daynum = 0;
	
	for(char i=1;i<=12;i++)
	{
		daynum += GetDayNumOfMonth(year, i);
	}

	return daynum;
}

short HtDateTime::GetDayNumInYear(short year, char month, char day)
{
	short daynum = 0;

	for(char i=1;i<month;i++)
	{
		daynum += GetDayNumOfMonth(year, i);
	}

	daynum += day;

	return daynum;
}

char HtDateTime::GetWeekDay(short year, char month, char day)
{
	char refenceweekday = 5;//参考的2010-01-01的周天
	int daynum = 0;

	if (year >= 2010)
	{
		for(int i=2010;i<year;i++)
		{
			daynum += GetDayNumOfYear(i);
		}
		daynum += GetDayNumInYear(year, month, day) - 1;

		return (char)((daynum + refenceweekday) % 7);
	}
	else
	{
		for(short i=year+1;i<2010;i++)
		{
			daynum += GetDayNumOfYear(i);
		}
		daynum += GetDayNumOfYear(year) - GetDayNumInYear(year, month, day) + 1;

		int weekday = refenceweekday - daynum % 7;
		if (weekday < 0)
		{
			weekday = 7 + weekday;
		}
		return (char)weekday;
	}	
}

HtDateTime HtDateTime::GetMondayOfWeek(HtDateTime dttime)
{
	int weekday = GetWeekDay(dttime.getYear(), dttime.getMonth(), dttime.getDay());
	return dttime.AddDays(1 - weekday);
}

string HtDateTime::HtDateTimeConvertToStr(HtDateTime httime)
{
	int millsecd = 0;
	tm tmtime = HtDateTimeConvertToTm(httime, millsecd);
	char* ptimestr = new char[24];
	strftime(ptimestr, 24, "%Y-%m-%d %H:%M:%S", &tmtime);
	string s = HtString::StrConvert(ptimestr);
	delete[] ptimestr;
	s += "." + HtString::StrFillCode(HtString::StrConvertFromInt(millsecd), 3, true);
	return s;
}

HtDateTime HtDateTime::StrConvertToHtDateTime(string timestr)
{
	HtDateTime httime;

	string datepart = HtString::StrDepart(timestr, " ", 0);
	httime.Year = HtString::StrConvertToInt(HtString::StrDepart(datepart, "-", 0));
	httime.Month = HtString::StrConvertToInt(HtString::StrDepart(datepart, "-", 1));
	httime.Day = HtString::StrConvertToInt(HtString::StrDepart(datepart, "-", 2));

	string timepart = HtString::StrDepart(timestr, " ", 1);
	httime.Hour = HtString::StrConvertToInt(HtString::StrDepart(timepart, ":", 0));
	httime.Minute = HtString::StrConvertToInt(HtString::StrDepart(timepart, ":", 1));

	string secondpart = HtString::StrDepart(timepart, ":", 2);
	httime.Second = HtString::StrConvertToInt(HtString::StrDepart(secondpart, ".", 0));
	httime.MillSecond = HtString::StrConvertToInt(HtString::StrDepart(secondpart, ".", 1));

	if (httime <= HtDateTime())
		httime = HtDateTime();
	return httime;
}

HtDateTime HtDateTime::GetCurrTime()
{
	auto tNow = time(nullptr);
	struct tm stTime;
#ifdef WIN32	

	localtime_s(&stTime, &tNow);
#else
	localtime_r(&tNow, &stTime);
#endif
	HtDateTime dt;
	dt.Year = (int)stTime.tm_year+1900;
	dt.Month = (int)stTime.tm_mon+1;
	dt.Day = (int)stTime.tm_mday;
	dt.Hour = (int)stTime.tm_hour;
	dt.Minute = (int)stTime.tm_min;
	dt.Second = (int)stTime.tm_sec;
	dt.MillSecond = 0;
	return dt;
}

// HtDateTime HtDateTime::GetCurrTime()
// {
// #ifdef WIN32
// 	SYSTEMTIME stUTC;
// 	GetLocalTime(&stUTC);
// 
// 	HtDateTime dt;
// 	dt.Year = (int)stUTC.wYear;
// 	dt.Month = (int)stUTC.wMonth;
// 	dt.Day = (int)stUTC.wDay;
// 	dt.Hour = (int)stUTC.wHour;
// 	dt.Minute = (int)stUTC.wMinute;
// 	dt.Second = (int)stUTC.wSecond;
// 	dt.MillSecond = (int)stUTC.wMilliseconds;
// 
// 	return dt;
// #else
// 	timeval tv;
// 	gettimeofday(&tv, NULL);
// 	
// 	time_t tt = tv.tv_sec;//time(&tt); 
// 	
// 	struct tm* t_tm = localtime(&tt);
// 
// 	HtDateTime dt;
// 	dt.Year = (int)(t_tm->tm_year + 1900);
// 	dt.Month = (int)(t_tm->tm_mon + 1);
// 	dt.Day = (int)t_tm->tm_mday;
// 	dt.Hour = (int)t_tm->tm_hour;
// 	dt.Minute = (int)t_tm->tm_min;
// 	dt.Second = (int)t_tm->tm_sec;
// 	dt.MillSecond = (int)(tv.tv_usec / 1000);
// 
// 	return dt;	
// #endif	
// }

 
long long HtDateTime::GetAppSpendTicket()
{
	return clock();
}

int HtDateTime::Random(int maxnum)
{
	if (maxnum <= 0)
		return 0;

	if (!m_bHasSrand)
	{
		srand((unsigned int)time(0));
		m_bHasSrand = true;
	}

	//double dbval = rand() / (double)(RAND_MAX / (maxnum + 1));
	//dbval = max((double)0, dbval - 1);
	//int rdval = (int)dbval % maxnum;

	double dbval = rand() / (double)(RAND_MAX );
	//dbval = max((double)0, dbval - 1);
	int rdval = (int)(dbval * maxnum);
	return rdval;
}

int HtDateTime::Random(int minnum, int maxnum)
{
	int rdmval = Random(maxnum - minnum);
	rdmval += minnum;
	if (rdmval < 0)
	{
		rdmval = 0;
	}
	return rdmval;
}

/************************************************************************/
/* 私有静态函数                                                         */
/************************************************************************/

// HtDateTime HtDateTime::MysqlDateTimeConvertToHtDateTime(htdepends::mysql::DateTime mysqldt, int millsecd)
// {
// 	HtDateTime httime;
// 
// 	httime.Year = mysqldt.year;
// 	httime.Month = (char)mysqldt.month;
// 	httime.Day = (char)mysqldt.day;
// 	httime.Hour = (char)mysqldt.hour;
// 	httime.Minute = (char)mysqldt.minute;
// 	httime.Second = (char)mysqldt.second;
// 	httime.MillSecond = (short)millsecd;
// 
// 	return httime;
// }

HtDateTime HtDateTime::TimetConvertToHtDateTime(time_t timet, int millsecd)
{
	if (timet < 0)
		timet = 0;
	tm* httime = HtGmTime(&timet);
	return TmConvertToHtDateTime(*httime, millsecd);
}

time_t HtDateTime::HtDateTimeConvertToTimet(HtDateTime httime, int& millsecd)
{
	tm tmtime = HtDateTimeConvertToTm(httime, millsecd);
	time_t timet = HtMkTime(&tmtime);
	if (timet < 0)
		timet = 0;
	return timet;
}

HtDateTime HtDateTime::TmConvertToHtDateTime(tm tmtime, int millsecd)
{
	HtDateTime httime;

	httime.Year = tmtime.tm_year + 1900;//注意这里不是1970
	httime.Month = tmtime.tm_mon + 1;
	httime.Day = tmtime.tm_mday;
	httime.Hour = tmtime.tm_hour;
	httime.Minute = tmtime.tm_min;
	httime.Second = tmtime.tm_sec;
	httime.MillSecond = millsecd;

	return httime;
}

tm HtDateTime::HtDateTimeConvertToTm(HtDateTime httime, int& millsecd)
{
	tm tmtime;

	tmtime.tm_year = httime.Year - 1900;//注意这里不是1970
	tmtime.tm_mon = httime.Month - 1;
	tmtime.tm_mday = httime.Day;
	tmtime.tm_wday = GetWeekDay(httime.Year, httime.Month, httime.Day);
	tmtime.tm_yday = GetDayNumInYear(httime.Year, httime.Month, httime.Day) - 1;

	tmtime.tm_hour = httime.Hour;
	tmtime.tm_min = httime.Minute;
	tmtime.tm_sec = httime.Second;

	millsecd = httime.MillSecond;

	tmtime.tm_isdst = 0;

	return tmtime;
}
