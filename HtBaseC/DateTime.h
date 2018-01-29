#ifndef _HtDateTime_Defined_
#define _HtDateTime_Defined_
#include <time.h>
#include <iostream>
#include <string>
#include "HtString.h"
using namespace std;

//tm��time_t���Ͷ�ֻ��ȷ���룬timeb��ȷ������

class HtDateTime
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
	HtDateTime();
	HtDateTime(char* initTimeStr);
	~HtDateTime();


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
	HtDateTime getDate()
	{
		HtDateTime dtdate;
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

	//��HtDateTimeת��Ϊ�ַ�����ʽ
	string ToString();
	string ToString(string fmt);
	//ȡ����HtDateTimeʱ��֮��������
	long long DiffSeconds(HtDateTime starttime);
	//ȡ����HtDateTimeʱ��֮����������
	long long DiffMillSeconds(HtDateTime starttime);
	//����ָ��������
	HtDateTime AddMillSeconds(long long addnum);
	//����ָ������
	HtDateTime AddSeconds(long long addnum);
	HtDateTime AddSeconds(int addnum);
	//����ָ������
	HtDateTime AddMinutes(int addnum);
	//����ָ��Сʱ
	HtDateTime AddHours(int addnum);
	//����ָ������
	HtDateTime AddDays(int addnum);
	//����ָ������
	HtDateTime AddMonths(int addnum);
	//����ָ������
	HtDateTime AddYears(int addnum);

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
	static HtDateTime GetMondayOfWeek(HtDateTime dttime);

	//��HtDateTimeת��Ϊ�ַ�����ʽ
	static string HtDateTimeConvertToStr(HtDateTime dttime);
	//���ַ���ת��ΪHtDateTime
	static HtDateTime StrConvertToHtDateTime(string timestr);

	//��ȡ��ǰʱ��
	static HtDateTime GetCurrTime();
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

	//��Mysql��DateTimeת��ΪHtDateTime
//	static HtDateTime MysqlDateTimeConvertToHtDateTime(htdepends::mysql::DateTime mysqldt, int millsecd = 0);
	//��time_tת��ΪHtDateTime
	static HtDateTime TimetConvertToHtDateTime(time_t timet, int millsecd = 0);
	//��HtDateTimeת��Ϊtime_t
	static time_t HtDateTimeConvertToTimet(HtDateTime httime, int& millsecd);
	//ת��tm����ΪHtDateTime
	static HtDateTime TmConvertToHtDateTime(tm tmtime, int millsecd = 0);
	//ת��HtDateTime����Ϊtm
	static tm HtDateTimeConvertToTm(HtDateTime httime, int& millsecd);

public:

	/************************************************************************/
	/* ������                                                               */
	/************************************************************************/

	long long operator - (const HtDateTime& httime)
	{
		return this->DiffMillSeconds(httime);
	}

	HtDateTime operator - (const long long millsec)
	{
		return this->AddMillSeconds(-millsec);
	}

	void operator -- ()
	{
		*this = this->AddMillSeconds(-1);
	}

	HtDateTime operator + (const long long millsec)
	{
		return this->AddMillSeconds(millsec);
	}

	void operator ++ ()
	{
		*this = this->AddMillSeconds(1);
	}

	bool operator == (const HtDateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = HtDateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = HtDateTimeConvertToTimet(httime, millsecd2);

		return tb1 == tb2 && millsecd1 == millsecd2;
	}

	bool operator != (const HtDateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = HtDateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = HtDateTimeConvertToTimet(httime, millsecd2);

		return tb1 != tb2 || millsecd1 != millsecd2;
	}

	bool operator > (const HtDateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = HtDateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = HtDateTimeConvertToTimet(httime, millsecd2);

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

	bool operator >= (const HtDateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = HtDateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = HtDateTimeConvertToTimet(httime, millsecd2);

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

	bool operator < (const HtDateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = HtDateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = HtDateTimeConvertToTimet(httime, millsecd2);

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

	bool operator <= (const HtDateTime& httime) const
	{
		int millsecd1 = 0;
		time_t tb1 = HtDateTimeConvertToTimet(*this, millsecd1);
		int millsecd2 = 0;
		time_t tb2 = HtDateTimeConvertToTimet(httime, millsecd2);

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