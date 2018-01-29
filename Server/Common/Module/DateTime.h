#ifndef _DateTime_Defined_
#define _DateTime_Defined_
#include <time.h>
#include <iostream>
#include <string>
#include "string.h"
using namespace std;

//tm和time_t类型都只精确到秒，timeb精确到毫秒

class DateTime
{
private:
	short Year;
	char Month;
	char Day;
	char Hour;
	char Minute;
	char Second;
	short MillSecond;

public:
	DateTime();
	DateTime(char* initTimeStr);
	~DateTime();


	static const int VT_SECOND_1970 = 2209161600;
	static const int SECONDS_IN_ONE_DAY = 86400;
	/************************************************************************/
	/* 公有成员函数                                                         */
	/************************************************************************/

	short getYear()
	{
		return Year;
	}
	char getMonth()
	{
		return Month;
	}
	char getDay()
	{
		return Day;
	}
	char getHour()
	{
		return Hour;
	}
	char getMinute()
	{
		return Minute;
	}
	char getSecond()
	{
		return Second;
	}
	short getMillSecond()
	{
		return MillSecond;
	}
	DateTime getDate()
	{
		DateTime dtdate;
		dtdate.Year = Year;
		dtdate.Month = Month;
		dtdate.Day = Day;
		dtdate.Hour = 0;
		dtdate.Minute = 0;
		dtdate.Second = 0;
		dtdate.MillSecond = 0;

		return dtdate;
	}

	void setHour(char cHour)
	{
		Hour = cHour;
	}
	void setMinute(char cMinute)
	{
		Minute = cMinute;
	}

	//将DateTime转化为字符串格式
	string ToString();
	string ToString(string fmt);
	//取两个DateTime时间之间间隔秒数
	long long DiffSeconds(DateTime starttime);
	//取两个DateTime时间之间间隔毫秒数
	long long DiffMillSeconds(DateTime starttime);
	//增加指定毫秒数
	DateTime AddMillSeconds(long long addnum);
	//增加指定秒数
	DateTime AddSeconds(long long addnum);
	DateTime AddSeconds(int addnum);
	//增加指定分钟
	DateTime AddMinutes(int addnum);
	//增加指定小时
	DateTime AddHours(int addnum);
	//增加指定天数
	DateTime AddDays(int addnum);
	//增加指定月数
	DateTime AddMonths(int addnum);
	//增加指定年数
	DateTime AddYears(int addnum);

public:

	/************************************************************************/
	/* 常用静态函数                                                         */
	/************************************************************************/

	//获取某年某月的总天数
	static char GetDayNumOfMonth(short year, char month);
	//获取某年的总天数
	static short GetDayNumOfYear(short year);
	//获取指定年月日在该年中的天数
	static short GetDayNumInYear(short year, char month, char day);
	//获取某日所属周天，周日为0
	static char GetWeekDay(short year, char month, char day);
	//获取某日所在周的周一的日期
	static DateTime GetMondayOfWeek(DateTime dttime);

	//将DateTime转化为字符串格式
	static string DateTimeConvertToStr(DateTime dttime);
	//将字符串转化为DateTime
	static DateTime StrConvertToDateTime(string timestr);

	//获取当前时间
	static DateTime GetCurrTime();
	//获取进程启动后经过的毫秒数
	static long long GetAppSpendTicket();

	//获取0到maxnum-1之间的随机数
	static int Random(int maxnum);
	//获取minnum到maxnum-1之间的随机数
	static int Random(int minnum, int maxnum);

private:
	static bool IsLeapYear(unsigned short nYear)
	{
		return !(nYear % 4) && (nYear % 100) || !(nYear % 400);
	}

	static int DaysFromJan1st(unsigned short wYear, unsigned short wMonth)
	{
		static unsigned short monthday[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
		return monthday[wMonth - 1] + (IsLeapYear(wYear) && wMonth > 2 ? 1 : 0);
	}

#ifdef WIN32
	static tm* HtGmTime(const time_t* pTT)
	{
		static tm s_tm;
		localtime_s(&s_tm, pTT);
		return &s_tm;
	}

	static time_t HtMkTime(tm* pTM)
	{
		return mktime(pTM);
	}
#else
	static tm* HtGmTime(const time_t* pTT)
	{
		static struct tm t_tm;
		localtime_r(pTT, &t_tm);
		return &t_tm;
	}

	static time_t HtMkTime(tm* pTM)
	{
		time_t tt = mktime(pTM);
		return tt;
	}
#endif

public:

	/************************************************************************/
	/* 慎用静态函数                                                         */
	/************************************************************************/

	//将Mysql的DateTime转换为DateTime
//	static DateTime MysqlDateTimeConvertToDateTime(htdepends::mysql::DateTime mysqldt, int millsecd = 0);
	//将time_t转换为DateTime
	static DateTime TimetConvertToDateTime(time_t timet, int millsecd = 0);
	//将DateTime转换为time_t
	static time_t DateTimeConvertToTimet(DateTime httime, int& millsecd);
	//转换tm类型为DateTime
	static DateTime TmConvertToDateTime(tm tmtime, int millsecd = 0);
	//转换DateTime类型为tm
	static tm DateTimeConvertToTm(DateTime httime, int& millsecd);

public:

	/************************************************************************/
	/* 操作符                                                               */
	/************************************************************************/

	long long operator - (const DateTime& httime)
	{
		return this->DiffMillSeconds(httime);
	}

	DateTime operator - (const long long millsec)
	{
		return this->AddMillSeconds(-millsec);
	}

	void operator -- ()
	{
		*this = this->AddMillSeconds(-1);
	}

	DateTime operator + (const long long millsec)
	{
		return this->AddMillSeconds(millsec);
	}

	void operator ++ ()
	{
		*this = this->AddMillSeconds(1);
	}

	bool operator == (const DateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = DateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = DateTimeConvertToTimet(httime, millsecd2);

		return tb1 == tb2 && millsecd1 == millsecd2;
	}

	bool operator != (const DateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = DateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = DateTimeConvertToTimet(httime, millsecd2);

		return tb1 != tb2 || millsecd1 != millsecd2;
	}

	bool operator > (const DateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = DateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = DateTimeConvertToTimet(httime, millsecd2);

		if (tb1 > tb2)
			return true;
		else if (tb1 == tb2)
		{
			if (millsecd1 > millsecd2)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator >= (const DateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = DateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = DateTimeConvertToTimet(httime, millsecd2);

		if (tb1 > tb2)
		{
			return true;
		}
		else if (tb1 == tb2)
		{
			if (millsecd1 >= millsecd2)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator < (const DateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = DateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = DateTimeConvertToTimet(httime, millsecd2);

		if (tb1 < tb2)
			return true;
		else if (tb1 == tb2)
		{
			if (millsecd1 < millsecd2)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator <= (const DateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = DateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = DateTimeConvertToTimet(httime, millsecd2);

		if (tb1 < tb2)
			return true;
		else if (tb1 == tb2)
		{
			if (millsecd1 <= millsecd2)
				return true;
			else
				return false;
		}
		else
			return false;
	}

};

#endif