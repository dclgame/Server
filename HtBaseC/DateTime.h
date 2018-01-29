#ifndef _DateTime_Defined_
#define _DateTime_Defined_
#include <time.h>
#include <iostream>
#include <string>
#include "string.h"
using namespace std;

//tm��time_t���Ͷ�ֻ��ȷ���룬timeb��ȷ������

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
	/* ���г�Ա����                                                         */
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

	//��DateTimeת��Ϊ�ַ�����ʽ
	string ToString();
	string ToString(string fmt);
	//ȡ����DateTimeʱ��֮��������
	long long DiffSeconds(DateTime starttime);
	//ȡ����DateTimeʱ��֮����������
	long long DiffMillSeconds(DateTime starttime);
	//����ָ��������
	DateTime AddMillSeconds(long long addnum);
	//����ָ������
	DateTime AddSeconds(long long addnum);
	DateTime AddSeconds(int addnum);
	//����ָ������
	DateTime AddMinutes(int addnum);
	//����ָ��Сʱ
	DateTime AddHours(int addnum);
	//����ָ������
	DateTime AddDays(int addnum);
	//����ָ������
	DateTime AddMonths(int addnum);
	//����ָ������
	DateTime AddYears(int addnum);

public:

	/************************************************************************/
	/* ���þ�̬����                                                         */
	/************************************************************************/

	//��ȡĳ��ĳ�µ�������
	static char GetDayNumOfMonth(short year, char month);
	//��ȡĳ���������
	static short GetDayNumOfYear(short year);
	//��ȡָ���������ڸ����е�����
	static short GetDayNumInYear(short year, char month, char day);
	//��ȡĳ���������죬����Ϊ0
	static char GetWeekDay(short year, char month, char day);
	//��ȡĳ�������ܵ���һ������
	static DateTime GetMondayOfWeek(DateTime dttime);

	//��DateTimeת��Ϊ�ַ�����ʽ
	static string DateTimeConvertToStr(DateTime dttime);
	//���ַ���ת��ΪDateTime
	static DateTime StrConvertToDateTime(string timestr);

	//��ȡ��ǰʱ��
	static DateTime GetCurrTime();
	//��ȡ���������󾭹��ĺ�����
	static long long GetAppSpendTicket();

	//��ȡ0��maxnum-1֮��������
	static int Random(int maxnum);
	//��ȡminnum��maxnum-1֮��������
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
	/* ���þ�̬����                                                         */
	/************************************************************************/

	//��Mysql��DateTimeת��ΪDateTime
//	static DateTime MysqlDateTimeConvertToDateTime(htdepends::mysql::DateTime mysqldt, int millsecd = 0);
	//��time_tת��ΪDateTime
	static DateTime TimetConvertToDateTime(time_t timet, int millsecd = 0);
	//��DateTimeת��Ϊtime_t
	static time_t DateTimeConvertToTimet(DateTime httime, int& millsecd);
	//ת��tm����ΪDateTime
	static DateTime TmConvertToDateTime(tm tmtime, int millsecd = 0);
	//ת��DateTime����Ϊtm
	static tm DateTimeConvertToTm(DateTime httime, int& millsecd);

public:

	/************************************************************************/
	/* ������                                                               */
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