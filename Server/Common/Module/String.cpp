#include "String.h"

#ifdef WIN32

/*NULL*/
#include <string>

#else

#include <stdio.h>
#include <stdlib.h>
#include <iconv.h> 

#endif

/************************************************************************/
/* �ַ�������                                                           */
/************************************************************************/

string String::StrConvert(char* srcPchar)
{
	string str(srcPchar);
	return str;
}

char* String::StrConvert(string &srcStr)
{
	return &srcStr[0];
}

int String::StrLen(string str)
{
	return str.length();
}

int String::StrLen(char* pchar)
{
	return strlen(pchar);
}

string String::StrSub(string str, int index, int count)
{
	int strLen = StrLen(str);
	if (index >= strLen || count <= 0)
	{
		return "";
	}
	else
	{
		if (index < 0)
		{
			index = 0;
		}

		if (index + count > strLen)
		{
			count = strLen - index;
		}

		return str.substr(index, count);
	}
}

string String::StrSub(char* pchar, int index, int count)
{
	int pcharLen = StrLen(pchar);
	if (index >= pcharLen || count <= 0)
	{
		return "";
	}
	else
	{
		if (index < 0)
		{
			index = 0;
		}

		if (index + count > pcharLen)
		{
			count = pcharLen - index;
		}

		char* dstPchar = new char[count + 1];
		memset(dstPchar, 0, count + 1);
		memcpy(dstPchar, pchar + index, count);
		string tmpStr = StrConvert(dstPchar);
		delete[] dstPchar;
		return tmpStr;
	}
}

string String::StrSub(string str, int index)
{
	int strLen = StrLen(str);
	return StrSub(str, index, strLen);
}

string String::StrSub(char* pchar, int index)
{
	int pcharLen = StrLen(pchar);
	return StrSub(pchar, index, pcharLen);
}

string String::StrLeft(string str, int count)
{
	return StrSub(str, 0, count);
}

string String::StrLeft(char* pchar, int count)
{
	return StrSub(pchar, 0, count);
}

string String::StrRight(string str, int count)
{
	int strLen = StrLen(str);
	if (strLen >= count)
	{
		return StrSub(str, strLen - count, count);
	}
	else
	{
		return str;
	}
}

string String::StrRight(char* pchar, int count)
{
	int pcharLen = StrLen(pchar);
	if (pcharLen >= count)
	{
		return StrSub(pchar, pcharLen - count, count);
	}
	else
	{
		return StrSub(pchar, 0);
	}
}

string String::StrLeftL(string str, int leftLeaveCount)
{
	int strLen = StrLen(str);
	return StrLeft(str, strLen - leftLeaveCount);	
}

string String::StrLeftL(char* pchar, int leftLeaveCount)
{
	int pcharLen = StrLen(pchar);
	return StrLeft(pchar, pcharLen - leftLeaveCount);	
}

string String::StrRightL(string str, int rightLeaveCount)
{
	int strLen = StrLen(str);
	return StrRight(str, strLen - rightLeaveCount);	
}

string String::StrRightL(char* pchar, int rightLeaveCount)
{
	int pcharLen = StrLen(pchar);
	return StrRight(pchar, pcharLen - rightLeaveCount);	
}

int String::StrPos(string str1, string str2, int index)
{
	if (index >= StrLen(str1))
	{
		return -1;
	}

	if (index < 0)
	{
		index = 0;
	}

	return str1.find(str2, index);
}

int String::StrPos(char* pchar1, string str2, int index)
{
	return StrPos(StrConvert(pchar1), str2, index);
}

int String::StrPos(char* pchar1, char* pchar2, int index)
{
	return StrPos(StrConvert(pchar1), StrConvert(pchar2), index);
}

int String::StrPos(string str1, char* pchar2, int index)
{
	if (index >= StrLen(str1))
	{
		return -1;
	}

	if (index < 0)
	{
		index = 0;
	}

	return str1.find(pchar2, index);
}


int String::StrPosDown(string strs, string subs, int startp)
{
	int li_pos1;
	int li_pos2 = -1;
	do
	{
		li_pos1 = li_pos2;
		li_pos2 = StrPos(strs, subs, li_pos2 + 1);
	}
	while ((li_pos2 >= 0) && (li_pos2 <= startp));
	return li_pos1;
}

int String::StrPosDown(char* pchar, char* subPchar, int startp)
{
	int li_pos1;
	int li_pos2 = -1;
	do
	{
		li_pos1 = li_pos2;
		li_pos2 = StrPos(pchar, subPchar, li_pos2 + 1);
	}
	while ((li_pos2 >= 0) && (li_pos2 <= startp));
	return li_pos1;
}

int String::StrPosDown(string strs, string subs)
{
	int li_pos1;
	int li_pos2 = -1;
	do
	{
		li_pos1 = li_pos2;
		li_pos2 = StrPos(strs, subs, li_pos2 + 1);
	}
	while (li_pos2 >= 0);
	return li_pos1;
}

int String::StrPosDown(char* pchar, char* subPchar)
{
	int li_pos1;
	int li_pos2 = -1;
	do
	{
		li_pos1 = li_pos2;
		li_pos2 = StrPos(pchar, subPchar, li_pos2 + 1);
	}
	while (li_pos2 >= 0);
	return li_pos1;
}

string String::StrRepeat(string str, int repeatCount)
{
	string goalStr = "";
	for(int i=0;i<repeatCount;i++)
	{
		goalStr += str;
	}
	return goalStr;
}

string String::StrRepeat(char* pchar, int repeatCount)
{
	int pcharLen = StrLen(pchar);
	if (pcharLen == 0 || repeatCount <= 0)
	{
		return "";
	}
	else
	{
		char* goalPchar = new char[pcharLen * repeatCount + 1];
		memset(goalPchar, 0, pcharLen * repeatCount + 1);
		for(int i=0;i<repeatCount;i++)
		{
			memcpy(goalPchar + (pcharLen * i), pchar, pcharLen);
		}
		string tmpStr = StrConvert(goalPchar);
		delete[] goalPchar;
		return tmpStr;
	}
}

string String::StrUpper(char* pchar)
{
	int pcharLen = StrLen(pchar);
	char* tmpPchar = new char[pcharLen + 1];
	memset(tmpPchar, 0, pcharLen + 1);
	memcpy(tmpPchar, pchar, pcharLen);

	int i = 0;
	while (i != pcharLen)
	{
		if (islower(tmpPchar[i]))
			tmpPchar[i] = toupper(tmpPchar[i]);
		++i;
	}
	//_strupr_s(tmpPchar, pcharLen + 1);
	////tmpPchar = strupr(tmpPchar);

	string tmpStr = StrConvert(tmpPchar);
	delete[] tmpPchar;
	return tmpStr;
}

string String::StrUpper(string str)
{
	return StrUpper(StrConvert(str));
}

string String::StrLower(char* pchar)
{
	int pcharLen = StrLen(pchar);
	char* tmpPchar = new char[pcharLen + 1];
	memset(tmpPchar, 0, pcharLen + 1);
	memcpy(tmpPchar, pchar, pcharLen);

	int i = 0;
	while (i != pcharLen)
	{
		if (isupper(tmpPchar[i]))
			tmpPchar[i] = tolower(tmpPchar[i]);
		++i;
	}
	//_strlwr_s(tmpPchar, pcharLen + 1);
	////tmpPchar = strlwr(tmpPchar);

	string tmpStr = StrConvert(tmpPchar);
	delete[] tmpPchar;
	return tmpStr;
}

string String::StrLower(string str)
{
	return StrLower(StrConvert(str));
}

string String::StrTrim(string str)
{
	return StrRTrim(StrLTrim(str));
}

string String::StrTrim(char* pchar)
{
	return StrRTrim(StrLTrim(pchar));
}

string String::StrLTrim(string str)
{
	while (StrLen(str) > 0 && str[0] == ' ')
	{
		str = str.erase(0, 1);
	}
	return str;
}

string String::StrLTrim(char* pchar)
{
	int pcharLen = StrLen(pchar);
	int index = 0;
	while(index < pcharLen && *(pchar + index) == ' ')
	{
		index++;
	}
	if (index >= pcharLen)
	{
		return "";
	}
	else
	{
		char* dstPchar = new char[pcharLen - index + 1];
		memset(dstPchar, 0, pcharLen - index + 1);
		memcpy(dstPchar, pchar + index, pcharLen - index);
		string tmpStr = StrConvert(dstPchar);
		delete[] dstPchar;
		return tmpStr;
	}
}

string String::StrRTrim(string str)
{
	while (StrLen(str) > 0 && str[StrLen(str) - 1] == ' ')
	{
		str = str.erase(StrLen(str) - 1, 1);
	}
	return str;
}

string String::StrRTrim(char* pchar)
{
	int pcharLen = StrLen(pchar);
	int index = pcharLen - 1;
	while(index >= 0 && *(pchar + index) == ' ')
	{
		index--;
	}
	if (index < 0)
	{
		return "";
	}
	else
	{
		char* dstPchar = new char[index + 1 + 1];
		memset(dstPchar, 0, index + 1 + 1);
		memcpy(dstPchar, pchar, index + 1);
		string tmpStr = StrConvert(dstPchar);
		delete[] dstPchar;
		return tmpStr;
	}
}

int String::StrComp(string str1, string str2)
{
	return str1.compare(str2);
}

int String::StrComp(char* pchar1, string str2)
{
	return StrComp(pchar1, StrConvert(str2));
}

int String::StrComp(char* pchar1, char* pchar2)
{
	return strcmp(pchar1, pchar2);
}

int String::StrComp(string str1, char* pchar2)
{
	return StrComp(StrConvert(str1), pchar2);
}

string String::StrReplace(string str, int index, int count, string dstStr)
{
	int strLen = StrLen(str);
	if (index >= strLen || count <= 0)
	{
		return str;
	}
	if (index < 0)
	{
		index = 0;
	}
	if (index + count - 1 >= strLen)
	{
		count = strLen - index;
	}

	return str.replace(index, count, dstStr);
}

string String::StrReplace(string str, int index, int count, char* dstPchar)
{
	return StrReplace(str, index, count, StrConvert(dstPchar));
}

string String::StrReplace(char* pchar, int index, int count, char* dstPchar)
{
	return StrReplace(StrConvert(pchar), index, count, StrConvert(dstPchar));
}

string String::StrReplace(char* pchar, int index, int count, string dstStr)
{
	return StrReplace(StrConvert(pchar), index, count, dstStr);
}

string String::StrReplaceAll(string str, string searchFor, string replaceAs, int index)
{
	int strLen = StrLen(str);
	int searchForLen = StrLen(searchFor);
	int replaceAsLen = StrLen(replaceAs);
	if (index < 0)
	{
		index = 0;
	}
	if (index >= strLen || strLen - index  < searchForLen)
	{
		return str;
	}

	int pos = index;
	while(pos >= index)
	{
		pos = StrPos(str, searchFor, pos);
		if (pos >= 0)
		{
			str = StrReplace(str, pos, searchForLen, replaceAs);

			pos += replaceAsLen;
			if (pos >= StrLen(str))
			{
				pos = -1;
			}
		}
		else
		{
			break;
		}
	}
	return str;
}

string String::StrReplaceAll(char* pchar, char* searchFor, char* replaceAs, int index)
{
	return StrReplaceAll(StrConvert(pchar), StrConvert(searchFor), StrConvert(replaceAs), index);
}

string String::StrDepart(string strs, string dpts, int nos)
{
	string departedstr = "";
	int i, pos1, pos2, lenofdpts;
	//strs = strs.Trim();
	//dpts = dpts.Trim();
	lenofdpts = StrLen(dpts);
	if (nos > 0)
	{
		i = 0;
		pos2 = -lenofdpts;
loop1:
		pos1 = StrPos(strs, dpts, pos2 + lenofdpts);
		if (pos1 >= 0)
		{
			i = i + 1;
			pos2 = pos1;
			if (i == nos)
			{
				pos1 = StrPos(strs, dpts, pos2 + lenofdpts);
				if (pos1 >= 0)
				{
					departedstr = StrSub(strs, pos2 + lenofdpts, pos1 - pos2 - lenofdpts);
				}
				else
				{
					departedstr = StrSub(strs, pos2 + lenofdpts, StrLen(strs) - pos2 - lenofdpts);
				}
			}
			else if (i < nos)
			{
				goto loop1;
			}
		}
		else
		{
			departedstr = "";
		}
	}
	else if (nos == 0)
	{
		pos1 = StrPos(strs, dpts);
		if (pos1 >= 0)
		{
			departedstr = StrSub(strs, 0, pos1);
		}
		else
		{
			departedstr = strs;
		}
	}
	else
	{
		departedstr = "";
	}
	return departedstr;
}

string String::StrDepart(string strs, int nos)
{
	return StrDepart(strs, ";", nos);
}

string String::StrDepart(char* pchar, char* dptPchar, int nos)
{
	return StrDepart(StrConvert(pchar), StrConvert(dptPchar), nos);
}

string String::StrDepart(char* pchar, int nos)
{
	return StrDepart(pchar, ";", nos);
}

string String::GetParmStr(string strs, string dpts, string equs, string ids)
{
	int pos0, pos1, pos2;
	string poss;
	strs = dpts + strs;
	string upstrs = StrUpper(strs);
	string upquys = StrUpper(dpts + ids + equs);
	pos0 = StrPos(upstrs, upquys);
	if (pos0 >= 0)
	{
		pos1 = pos0 + StrLen(dpts + ids + equs);
		pos2 = StrPos(strs, dpts, pos1);
		if (pos2 >= 0)
		{
			poss = StrSub(strs, pos1, pos2 - pos1);
		}
		else
		{
			poss = StrSub(strs, pos1);
		}
	}
	else
	{
		poss = ""; //"<empty>"
	}
	return poss;
}

string String::GetParmStr(string strs, string dpts, string ids)
{
	return GetParmStr(strs, dpts, "=", ids);
}

string String::GetParmStr(string strs, string ids)
{
	return GetParmStr(strs, ";", ids);
}

string String::SetParmStr(string strs, string dpts, string equs, string ids, string vals)
{
	int pos0, pos1, pos2;
	strs = dpts + strs;
	pos0 = StrPos(StrUpper(strs), StrUpper(dpts + ids + equs));
	if (pos0 >= 0)
	{
		pos1 = pos0 + StrLen(dpts + ids + equs);
		pos2 = StrPos(strs, dpts, pos1);
		if (pos2 >= 0)
		{
			strs = StrLeft(strs, pos1) + vals + StrSub(strs, pos2);
		}
		else
		{
			strs = StrLeft(strs, pos1) + vals;
		}
	}
	else
	{
		if (strs == dpts)
		{
			strs = dpts + ids + equs + vals;
		}
		else
		{
			strs = strs + dpts + ids + equs + vals;
		}
	}
	strs = StrSub(strs, StrLen(dpts));
	return strs;
}

string String::SetParmStr(string strs, string dpts, string ids, string vals)
{
	return SetParmStr(strs, dpts, "=", ids, vals);
}

string String::SetParmStr(string strs, string ids, string vals)
{
	return SetParmStr(strs, ";", ids, vals);
}

string String::DelParmStr(string strs, string dpts, string equs, string ids)
{
	int pos0, pos1, pos2;
	strs = dpts + strs;
	pos0 = StrPos(StrUpper(strs), StrUpper(dpts + ids + equs));
	if (pos0 >= 0)
	{
		pos1 = pos0 + StrLen(dpts + ids + equs);
		pos2 = StrPos(strs, dpts, pos1);
		if (pos2 >= 0)
		{
			if (pos0 >= 1)
			{
				strs = StrLeft(strs, pos0) + StrSub(strs, pos2);
			}
			else
			{
				strs = StrSub(strs, pos2);
			}
		}
		else
		{
			if (pos0 >= 1)
			{
				strs = StrLeft(strs, pos0);
			}
			else
			{
				strs = dpts;
			}
		}
	}
	strs = StrSub(strs, StrLen(dpts));
	return strs;
}

string String::DelParmStr(string strs, string dpts, string ids)
{
	return DelParmStr(strs, dpts, "=", ids);
}

string String::DelParmStr(string strs, string ids)
{
	return DelParmStr(strs, ";", ids);
}

string String::StrConvertFromLong(long long lval)
{
#ifdef WIN32
	int pcharLen = 1;
	long long itmp = lval;
	if (itmp < 0)
	{
		itmp = -itmp;
	}
	itmp /= 10;
	while(itmp > 0)
	{
		pcharLen++;
		itmp = itmp / 10;
	}
	if (lval < 0)
	{
		pcharLen++;
	}

	char* strNum = new char[pcharLen + 1];
	memset(strNum, 0, pcharLen + 1); 
	_i64toa_s(lval, strNum, pcharLen + 1, 10);//����10������10���ƽ���ת��
	//_i64toa(lval, strNum, 10);//����10������10���ƽ���ת��

	string outStrNum = StrConvert(strNum);
	delete[] strNum;
	return outStrNum;
#else
	char strNum[20];
	sprintf(strNum, "%lld", lval);
	string outStrNum = strNum;
	return outStrNum;
#endif
}

string String::StrConvertFromInt(int ival)
{
	return StrConvertFromLong(ival);
}

string String::StrConvertFromShort(short sval)
{
	return StrConvertFromLong(sval);
}

string String::StrConvertFromByte(char bval)
{
	return StrConvertFromLong(bval);
}

string String::StrConvertFromDouble(double dval, int dec)
{
	char s[20];
#ifdef WIN32
	sprintf_s(s, 20, StrConvert(StrConvert("%.") + StrConvertFromInt(dec) + StrConvert("lf")), dval);
#else
	string sfmt = "%.";
	sfmt += StrConvertFromInt(dec);
	sfmt += "lf";
	sprintf(s, sfmt.c_str(), dval);
#endif
	return StrConvert(s);
}

string String::StrConvertFromFloat(float fval, int dec)
{
	return StrConvertFromDouble(fval, dec);
}

long long String::StrConvertToLong(string str)
{
#ifdef WIN32
	return _atoi64(StrConvert(str));
#else
	return atoll(StrConvert(str));
#endif
}

long long String::StrConvertToLong(char* pchar)
{
#ifdef WIN32
	return _atoi64(pchar);
#else
	return atoll(pchar);
#endif
}

int String::StrConvertToInt(string str)
{
	return atoi(StrConvert(str));
}

int String::StrConvertToInt(char* pchar)
{
	return atoi(pchar);
}

short String::StrConvertToShort(string str)
{
	return StrConvertToInt(str);
}

short String::StrConvertToShort(char* pchar)
{
	return StrConvertToInt(pchar);
}

unsigned char String::StrConvertToByte(string str)
{
	return StrConvertToInt(str);
}
unsigned char String::StrConvertToByte(char* pchar)
{
	return StrConvertToInt(pchar);
}

double String::StrConvertToDouble(string str)
{
	return StrConvertToDouble(StrConvert(str));
}

double String::StrConvertToDouble(char* pchar)
{
	return atof(pchar);
}

float String::StrConvertToFloat(string str)
{
	return StrConvertToFloat(StrConvert(str));
}

float String::StrConvertToFloat(char* pchar)
{
	return (float)StrConvertToDouble(pchar);
}


string String::StrExpr(string strs)
{
	string s = StrReplaceAll(strs, "\\", "\\\\");
	return "'" + StrReplaceAll(s, "'", "''") + "'";
}

vector<string> String::StrSplite(string strs, string dpts, bool noEmptyStr)
{
	vector<string> dstvect;
	int dptslen = StrLen(dpts);

	int dptspos = StrPos(strs, dpts);
	while (dptspos >= 0)
	{
		string subs = "";
		if (dptspos > 0)
		{
			subs = StrLeft(strs, dptspos);
		}
		if (noEmptyStr == false || StrTrim(subs) != "")
		{
			dstvect.push_back(subs);
		}

		strs = StrSub(strs, dptspos + dptslen);
		dptspos = StrPos(strs, dpts);
	}
	if (noEmptyStr == false || StrTrim(strs) != "")
	{
		dstvect.push_back(strs);
	}

	return dstvect;
}

bool String::StrIsNoSplitted(string sStr)
{
	for (int i = 0; i < StrLen(sStr); i++)
	{
		if (sStr[i] == ' ' || sStr[i] == '\n' || sStr[i] == 13 || sStr[i] == 10 || sStr[i] == '\t' || sStr[i] == '	')
		{
			return false;
		}
	}
	return true;
}

string String::StrGetSplittedPos(string sSrc, string sFirst, string sSecond, int &iPos)
{
	int iFirstPos = -1, iSecondPos;
loopgo:
	iFirstPos = StrPos(sSrc, sFirst, iFirstPos + 1);
	if (iFirstPos >= 0)
	{
		iSecondPos = StrPos(sSrc, sSecond, iFirstPos + 1);
		if (iSecondPos >= 0)
		{
			if (StrIsNoSplitted(StrSub(sSrc, iFirstPos + StrLen(sFirst), iSecondPos - iFirstPos - StrLen(sFirst))))
			{
				iPos = iFirstPos;
				return StrSub(sSrc, iFirstPos, iSecondPos + StrLen(sSecond) - iFirstPos);
			}
		}
		goto loopgo;
	}

	iPos = -1;
	return "";
}

string String::StrFillCode(string codestr, int codelen, bool restrictLen)
{
	codestr = StrRepeat("0", codelen - StrLen(codestr)) + codestr;
	if (restrictLen)
	{
		codestr = StrRight(codestr, codelen);
	}
	return codestr;
}

string String::StrFillCode(long long codelong, int codelen, bool restrictLen)
{
	return StrFillCode(StrConvertFromLong(codelong), codelen, restrictLen);
}

string String::StrPadChar(string sText, char cPadChar, int iWidth, bool bUntilWidth, bool bPadTail)
{
	if (!bPadTail)
	{
		if (bUntilWidth)
		{
			return StrRepeat(&cPadChar, iWidth - StrLen(sText)) + sText;
		}
		else
		{
			return StrRepeat(&cPadChar, iWidth) + sText;
		}
	}
	else
	{
		if (bUntilWidth)
		{
			return sText + StrRepeat(&cPadChar, iWidth - StrLen(sText));
		}
		else
		{
			return sText + StrRepeat(&cPadChar, iWidth);
		}
	}
}

string String::StrPadSpace(string sText, int iWidth, bool bUntilWidth, bool bPadTail)
{
	return StrPadChar(sText, ' ', iWidth, bUntilWidth, bPadTail);
}

string String::GetHzPY(string hzs)
{
	if (StrTrim(hzs) == "")
	{
		return "";
	}

	string pys[27];
	pys[1] = "����Aa߹������İ������������߰����Ȱ����������������Ȱ���訰��������ư�����������������������������갽������۰������������ְ���᮰�����İ�������";
	pys[2] = "�£�Bb�˰ͰȰǰ�ᱰṴ̋ư��ΰ����ð��ɰ��ٰаӰְ��Ѱ�����װٰ۰�����°ܰݰް����߰������������������������亰������������������߰�����������������𱱤���ٱ��������������鱰�������Ǳ���������������㣱����������������ͱ���Ｑ������б������Ա±ñ�괱ı�ݩ��ذ�����������±����ɱұرϱձ���ٱ���ݱ�������ر����������Ա����ϱױ���α���޵��娱�����ű���ֱ��������ޱ��������۱��������б���±����輱����������������������������������ϱ�������ٱ��ٱ��������ޱ����������������������𲦲���������ࣲ��������ò����������ಬ������𾲫�����۱��������������������߲���������������в���곲����԰�����";
	pys[3] = "�ã�Cc�����²ŲĲƲòɲʲǲȲ˲̲���ͲвϲѲ�������貲����ײԲղزٲڲ���������ݲ���������������農����ʲ�����鶲������������汲����٭�����������濲��������������������������������������潲������𳤳��ɳ��������ϳ�����㮳��곩���˳��������̳��˳������������鳵�����峸�����ӳ����������������巳����״��ĳ�����������������ة�ɳʳ��ǳϳǳ�����ͳ��������γȳѳҳӳ������������ʳ���γڳس۳��ݳֳ�ܯ�����߳޳ݳ�������߳����������������������������拾���ٱ�����������ų���������ۻ���������ܳ��������ƴ���������ء����穴�����������������ݴ�밴��������״�ⶴ����˴Ѵ��������봵�����ﴷ�鳴���������ݻ���ȴ����ִ�������ڴô�����ĴɴȴǴŴ����ٴ˴δ̴ʹӴ����ȴ���讴ϴ����������ꣴ������������״�������ߥ��ڴܴ���޴ߴ���譴���㲴���르��������������������������ȴ��ﱴ��������������������";
	pys[4] = "�ģ�Dd���Ǵ���״������δ����������߾�������߰��ʴ����������ܤ�������쵤�����񵢵����������ٵ��㵧������ࢵ������̵���壵��ɵ�������������е�߶��뮵�������������������������ｵµĵƵ������ŵ�ꭵ˵��ص�������Ƶ��ֵ������ϵе�ݶ�����صڮۡ�׵��������صܵ�淵ݵ�������޵����ǵ����������ڵ�����������������������������������������������������ܦ�����뺵����������궣���۶�������������������ֶ�������������𴶭����������ἶ����������϶�������������򽶹�����ྲྀ���������빶����Ƕ��ƶ¶Ķ�ܶ�ʶŶǶȶɶ��˶̶ζ϶���Ѷ����ѶӶԶ�������ֶض��������������۶ٶݶ��Ͷ��ֶ����������綶������������������������������ؼ";
	pys[5] = "�ţ�Ee������ݭﰶ���湶����������Ѷ���̶��������������ج��������������ܶ����Ƕ��������٦����";
	pys[6] = "�ƣ�Ff�跢�����ҷ���������������ᦷ�������������ެ�ܷ�������������������������������շ��������з·��ݷ����ŷ����Ƿ�糷��������������˷���������ͷϷ����η����зַԷ׷ҷշӷط��������۷ݷܷ��Ƿ߷���寷�����������׷��ۺ����������ٺ�����߻���������Ʒ��󸥷����ڷ�ܽ�����������޷��������ۮ����ݳ������������ʸ������ݷ�����긧�����Ը������������港�븸���������������⸴�������������������������";
	pys[7] = "�ǣ�Gg����ٸ¸����θ��������ؤ�ƸǸ�ꮸŸɸʸ˸������ո̸������ϸѸϸҸ�����ߦ����ƸӸԸոڸٸظ׸�۸����޸����غ��ݸ�꽸����¸��޻��ھ۬ﯸ����������˸�������ت������ܪ�����������������Ѹ���������ب��ݢ�������ٸ��칡箹����Ṥ�����������Ź���򼹪���������������������������ḹ������ѹ�ڸ�����������������ù¹���𳹽����������챹�������ڬ�ȹ�������ܹ���������̹ʹ���������������Ϲ�����ɹй���ڴ�ҹӹԹչֹع۹ٹ��Ĺ����ݹܹ�������¹��ٹ޹������׹������棹��������峹����й����������۹�����������絹������������������������������������������������ݸ��";
	pys[8] = "�ȣ�Hh������˺������������������������������������Ϻ��ʺ������������������������������嫺���笺���������޶���ƺ�����婺úº�껺ƺ����ڭ�Ǻ����̺Ϻ����ͺ��ºҺ����ɺԺк��º�����غֺպ��ֺںٺۺܺݺ޺�ߺ�������޿������ް����������ݦ���ޮ��ڧ�������������������˺�ܩ�׺���������������񻡺���������⩺��κ����κ�����첻����������������������������׻����������������������뻳�������׻���⵻���ۨ䡻���������߻���ۼ�»���佻������ջ�������ߧ���ĻŻʻ����������ػ��������ǻ�����лλѻϻ�ڶ�Իֻ������������Ļ����׻ڻܻ�����䫻����������޻�๻����ٻ�ޥ�����Ի��ƻ�ڻ�����������߫������ⷻ������������޽��������ڥ��";
	pys[9] = "�ɣ�Ii";
	pys[10] = "�ʣ�Jjܳ���٤آ����ߴ���������ἡܸ���Ҽ���������ǻ�������������һ�����Լ����᧼�������ؽ٥���ż�꫼��꼯������ު������򱼷���������ƼǼ��ͼ˼ɼ����ʼ������䩼ü����ʼżļ¼�������������꼽�����Ӽм��ȼ����������������ʼ����ۣ�������̼ռ��μּ����ۼݼܼټ޼�ꧼ���߼��������������������������������ż�����ȼ�������������ﵼ���꯼�����忼�������������������������립���������Լ����ݽ����������������佮���������𽳽��筽�����ܴ����毽��������������������޽����Խ�ٮ���ؽƽʽ��ýŽ½��н����ɽ�ώνϽ̽ѽ��������ܽԽӽ��ൽҽ��ݽ�ڦ�ٽ�ڵ�׽����漽��޽��ٽ����ɽ���������������������ƽ������������������誾���桽���ݣ���������ƽ������侩�����������ݼ���澦���������������¾�����㽾��������־���溾���������ⰾ������ľ������������౾��ݾžþľ��¾ƾɾʾ̾�����ǾȾ;����վӾо��ھԾ�����������¾����ֽ۾��پ׾ھپ����������ڪ���ľ߾��Ҿ��ƾ��ݾ���쫾���������������举����þ��þ�����������۲�پ��޾�������������Ⱦ������������ާ���Ӿ���������߾��������������忡�����ܿ�����ڢ����";
	pys[11] = "�ˣ�Kk�ǿ��������̿���﴿������������ܿ����鿯���述ꬿ�٩��ݨ����������������ʿ����꿼���࿾��������������������ݿ������������ǿȿ�᳿ʿ˿̿�㡿��������﾿Ͽѿҿ��̿Կ�﬿�������׿ֿؿ������ߵ�ۿ���ޢ�ڿݿ�ܥ��������෿���٨����������ۦ�����ڿ���ſ��ڲ�ѿ��ڿ���������������ܿ������㦿�������ظ�����ҿ�����������������������������������������������������ି�����";
	pys[12] = "�̣�Ll��������������������������������������������������������������������������������������������ݹ����������������������������������������������������������߷��������������������ڳ����������������������ܨ�����������������������������������������޼���������ٵ�������������������������������߿������������������ٳ��������۪��������ݰ������������������������������������������������������������������������������������ܮ������������������������������������������ޤ��������������������������������������������������������������������������������������������������������������������������۹������������������������������������������������������������������¡���¤¢��£¦�����¥��������§¨ª©����¶��ߣ¬®«����¯���������­��±²°³����½¼¸������¹»��µ·��¾�º�����´�¿�������������������������������������������������������������������������������������������������������������������������������߮��";
	pys[13] = "�ͣ�Mm��߼��������������������������������ݤ۽�������������������������áܬ���������������æäã��ç����èëì��é���ê�����î�������íïðó���ñ��ò�ôûöõüݮ÷ý������úø����ùÿ���þ�������������������������å�������ޫ������������������������������������������������������������������������������������������������������������������������������������������ؿ���������������������������������������������ڤ�������������������������ġģĤ��ĦĥĢħĨĩ��ĭ��İ��ĪįĮ����ī���Ĭ������Ĳٰ��ı��ĳĸ�ĶĵķĴľ��Ŀ����������ļĹĻ��Ľĺ������";
	pys[14] = "�Σ�Nn������������������������������ܵ����������ؾ������������������������߭ث����������������������ګ�������������������������������٣����������������������������������إ��������������������������������������������������š����������Ţ��ţ��Ť��Ŧťũٯ��ŨŧŪ��ū����Ŭ����ŭŮ�����űŰůŲ��ŵ�����ųŴ��������";
	pys[15] = "�ϣ�Oo��ŶکŷŹ�ŸŻż��ź��Ž���";
	pys[16] = "�У�Pp����ſž����������������ٽ�������������������������������������������������������������������������������������������������������������������������������ܡ���������������������ا�������������������Ƥ����ƣ�ۯ��ơ��Ƣ�����ܱƥ������Ʀߨ�ƨ�����Ƨ�ƩƬƫ��ƪ����������ƭ��Ư��Ʈ�ư���Ʊ�����ƲƳد���ƴƶ��Ƶ�Ʒ����Ƹƹٷƽ��ƾƺƻ����ƿƼ������������۶�����������������������������������������������������������������������";
	pys[17] = "�ѣ�Qq����������������������������������������������������������������ݽ��������������������ޭ�����������ܻ�������������������������������������ǡǢ��ǧǪ��ǤܷǨ���ǥǣ�Ǧǫ�ǩ���ǰݡ���ǮǯǬ����Ǳǭǳ���ǲǴ��Ƿ����ٻǵǶ��ǸǺǼ���ǹ��ǻ�������ǿǽ��Ǿ������������������������������������������������ڽ�������������������������������������������������������������������������������������������������������������������������������������������������������ٴ�������������������������ڰ������������������۾�����ޡ���޾�����ȡȢȣȥ����Ȥ�ȦȫȨڹȪ��ȭ��Ȭ������ȩ��ȧȮ��ȰȯȲȱȳȴ�ȸȷ����ȵȶ��ȹȺٹ��ۧ�";
	pys[18] = "�ң�Rr��Ȼ��ȼȽ��Ⱦ��ȿ�������������������������������������������������������������������������������������������������������������������޸����������������������������ި������������������ټ����";
	pys[19] = "�ӣ�Ss��ح�����������ئ��������������������ɡɢ����ɣɤ�����ɥɦɧ������ɨɩܣ��ɫɬ���ɪ�ɭɮɱɳɴɲɰɯ�������ɵ��ɶ�ɷ��ɸɹɽɾɼ���������ɺ����ɿ��������ڨ����ɻ��������۷��������������������������������������������������������������ۿ����������������������������������������������������ڷ�������������������������������������������ʤ������ʡ��ʥ��ʢʣ��ʬʧʦʭʫʩʨʪ������ʮʲʯʱʶʵʰ��ʴʳ��ݪ��ʷʸ��ʹʼʻʺʿ��������ʾʽ����������������������������������߱�������������������������������������������������ٿ���������������������������������������������������������ˡ������������ˢ�ˣ˥ˤ˦˧���˩˨��˫˪��ˬ˭ˮ˰˯˱˳˴˲˵��˸˷��˶������������˿˾˽��˼�˹��������˻˺���������������������������������������ڡ����ݿ���������������������������������������޴������������������������������������������������ݴ����������������������������������ݥ����������������������������������������ݷ��";
	pys[20] = "�ԣ�Tt��������������������̡��̢�����̨̧̤̣̥̦ۢ������޷̫̭̬����̩̪̮̰̯̲̱̳�̸۰̵��̷̶̴��̹̻��̺̼̾̿̽�����������������������������������������������������������������������ػ������߯��������������������������������������������������������������������������������٬�������������������������������������͡����ͤͥ͢��ͣ��������ͦ��ͧͨ����ͬ١ͮ��ͩ��ͭͯͪ��ͫͳͱͰͲ��ʹ͵ͷͶ��͸͹ͺͻͼͽͿݱ;������������ܢ��������������������������������������ر��������٢������������������������������������";
	pys[21] = "�գ�Uu";
	pys[22] = "�֣�Vv";
	pys[23] = "�ף�Ww��â���������������������������������������ܹ�������������������������������������������������������������Σ����������΢��ޱΡ��ΪΤ��Χ����Υ��Φ�Ψ�Ωά��Ϋΰαβγέί�����ή����������δλζηθ�ξνιμ�εοκ�������������������������������������޳������ݫ�������������������������������������������������������������������������������������������أ��������������������������������������";
	pys[24] = "�أ�Xx����Ϧ��ϫ����ϣ�������ۭ����Ϣ���Ϥϧ���ϩ��ݾ��Ϭϡ������Ϫ�����Ϩ��������ϥ��������������ϰϯϮ��ϱ��ϭϴ����ϳϲ��������Ϸϵ�ϸ����϶����ϺϹϻ����Ͽ��������Ͼ�Ͻϼ�����������������������ݲ����������������������������������������������޺���������������������������ܼ�����������������������������������������������������������������������������������������С����ТФ��ЧУЦХЩШЪЫЭавЮ��бгЯ��ߢ��Ьдйк�жме����л���и�ޯ�����з������о�����п���нܰ��ض������������������������������ߩ�����������������ܺ������������������������������������������������������������ڼ�������������������������������������ޣ�����������������������������ѡѢ����Ѥѣ���������ѥѦѨѧ���ѩ��Ѫ��ѫ��Ѭ��޹����ѰѲѮѱѯ�������ѭ��ѵѶѴѸ��ѷѳ��ަ��";
	pys[25] = "�٣�Yy�������ѾѹѽѺѻ��Ѽ�����ѿ���������������������������������������������������۳����������ܾ��������������������������ٲ����������۱�������������������������������������������������������������������������������������������������زߺ������سҢ��Ҧ����Ҥҥ��ҡң��������ҧ�Ҩ��ҩҪ����ҫҬҭүҮ����ҲұҰҵҶҷҳ��ҹ����ҴҺ��Ҹ��һ����ҽ�����ҿҼҾ��������������ڱ�������������������������������������������������������������������������߽��������٫�����������������������������������������������������������޲���������ܲ�������������������ܧ������������۴�����������������ӡ��طӦӢݺӤ������ӧ�ӣ�����ӥӭ��ӯӫӨөӪ���������Ӭ��Ӯ�۫�ӱӰ�ӳӲ��Ӵ�ӶӵӸ��ӹӺܭ�����ӷ��������ӽӾٸ��ӿ��Ӽӻ����������������������������ݯݵ��������������������ݬ�������������٧�������������������������������������خ��������������������������������������������������������ٶ������������������Ԧ�������������������ԡ��Ԥ����������Ԣ��ԣ������������ع��ԥ�������ԩ��ԧԨ��ԪԱ԰��ԫ�ԭԲԬԮԵ��ܫԴԳԯ���ԶԷԹԺ�������ԸԻԼ�����Կ������Ծ��Խ����������ܿ�������������������۩�������������";//";
	pys[26] = "�ڣ�Zz�����������������������������������������������������������������������������������������������������������������������������������������߸զ����������������բագ��էթ��դը����եիժլխծ��կ�մձ�ճղ��հնչյո��շռսջվ��տպ����۵����������������������������������������������������گ��������������������������ߡ�����������������������������������������������������������������������������������������������������������֤ں֣֡��֢֧֮ش֥֦֪֭֨֯֫������ֱִֵֶ֬֩��ְֲֳ��������ַֹֻּֽ������ָ����ֺ������־����������������ۤ������ֿ��������������������������������������������������������������ڣ����������������������������������������ݧ����������٪��ۥ��������������������������������������������������ס����ע��פ����ף��������������ץצקרש�ת��׬׫׭��ױׯ׮װ׳״ײ׷��׵׶׹׺���׸���׻׼׿׾پ׽������������������������ߪ���������������������������������������������������������������������������������������������������۸��������������������������������������߬������ީ����������ߤ��������������������������";
	for(int i = 0; i < 25; i++)
	{
		for(int j = pys[i + 1].length() / 2; j >= 0; j--)
		{
			pys[i + 1].insert(j * 2, " ");
		}
	}

	int i, j;
	string rtns, hz, hz2;
	rtns = "";
	for (i = 0; i < StrLen(hzs); i++)
	{
		hz = StrSub(hzs, i, 1);
		if ((unsigned char)(hz[0] & 0x80) > 0)
		{
			if (i < StrLen(hzs) - 1)
			{
				hz2 = StrSub(hzs, i + 1, 1);
				if ((unsigned char)(hz2[0] & 0x80) > 0)
				{
					hz += hz2;
					i++;
				}
			}
		}

		if ((hz[0] > 160) || (hz[0] <= 0))
		{
			for (j = 1; j <= 26; j++)
			{
				if (StrPos(pys[j], hz) >= 0)
				{
					break;
				}
			}
			if ((j <= 26) && (j >= 1))
			{
				rtns += (64 + j);
			}
			else
			{
				rtns += hz;
			}
		}
		else
		{
			rtns += hz;
		}
	}
	return rtns;
}

string String::GetHzWB(string hzs)
{
	if (StrTrim(hzs) == "")
	{
		return "";
	}

	string wbs[27];
	wbs[1] = "����Aa�����������ð������������ݩ���ɱͱ�޵�����в����˲̲Բ�ܳ�ݲ�������ɳ�����ݻ����ʴ���������߰�̵���ݶ�ٶ�𴶭��ܶݭ�����췡��ެ�����η��Ʒ˷���ܽ������ݳ�ʸ���޻����ݢ���������ù������������������к�����޶�ɺ�޿ްݦޮ�������ȻĻ�����ޥ�������޽ܸ����ު����������������������ܴ�����ڽ�����ݣ�����ݼ�����ھ����������ާ���ܿ��ݨ������ޢ��������������ݹ������������޼����ݰ����ޤ����������«������ݤ�����âãçé��ïݮ����ޫ����������������ġĢ��Ī��ĳ��ļĹĻĽĺܵ����إ������ŷŹ�Ÿź��������ƥ��ƻƼ����������������������ݽ��ޭܻ������ܷݡ����Ǿ��������������������������������������ޡ޾��ȧȵ����������������������޸��ި��������ɢɯ��ɻ��������ݪ��ʽ����������˹ݿ޴������ݴݥ��̦޷��߯�����������ݱ��ܹݸ����ޱέήε��޳ݫ����������ݾ��������ϻݲ޺��ܼ��������аЬޯоݷн��ܺ��ޣ��ѥѦ޹��ަѻ��ѿ��������ܾ۱����Ңҩҽ������߮��޲������۴��Ӣݺ����ӫӨөӪ����ݯݵݬ�������Էܿ����������պ��������֥��ݧ����������ީ";
	wbs[2] = "�£�Bb���������������ة���ܳ�����ϵ����������Ӷ�����⸽�����������������ؽ�ʽ�������������޿���������������¡¤ª½����İ�����������Ƹ����ȡȢ��������������������������������϶��������ѷ��ҮҲ������Ժ������ְ����׹������۸����";
	wbs[3] = "�ã�Cc���������������ҳ������ʵ��˵������ۺ��軶�����轾�澢�پ��ɾԿ���������¿������ì����Ĳ��������ƭ��������Ȱ�������ɣ�ɧ��ʥʻ˫������̨ۢ��ͨ����������Ϸ������ѱ���������������ԦԤԥ������������פ����";
	wbs[4] = "�ģ�Dd�����ưٰ����������ձ������������粼��޲�򲳧�����׳�����������������������Ǵ����������ڵ�����������������������������ܷ��ۺ�������ϸ���Ѹ���𳹼���Źʹ˹��޺��ĺ������߻ǻ������������ꩼ�������پ��ݾ¾����㿳�Ŀ��ڿ��ſ��������������������������������������������¢��µ��۽����������������������������������������������������ǣ����������Ȯȷ��������ɰ��������ʢʯ����ˣˬ˶��������̫̬̩̼��������������������������Ϯ�����������������������ѹ���������������������ҳ���Ӳ������������ԭԸ�������������������ש�����������";
	wbs[5] = "�ţ�Ee����������������������ɲʲ�������⵨�������ض��񷾷���η��ڷ�ۮ��������ꮸθظ����Ź���������ܺѼ������콺���������¾��̿�������������������ò����������Ĥ��������ؾ��������ŧ������������Ƣ��������ǻ������������������������ʤ������˦˴̥���������������������������ϥ������в����������������ң��Ҩ��Ҹ����ӯ��ӷ��������������������֫��֬������������������";
	wbs[6] = "�ƣ�Ff��������Ӱ��ౢ����ò���𾲺�Ųó�������ó���ܯ���ء����ܤ��������ص�����ܦ�����¶Ѷն�������ط����������ܪ���������챹���Թ����������������������ܩ��첻�����������弪����ν̽��ؽ���������������������ǿ�ܥ�����ۿ�����������ܨ������ܮ��������۹��¶��������ܬ�ù��������������������ܡ��������ܱ��ƺ������������Ǭǽ����������������ȥȤȴ������ɥܣ��������������ʮ��ʿʾ�˪��������̮̳̹�������������ܢ����Τ��Υδ��������������ϲϼ������ТЭܰ������ѩ��������Ҽ����ܲܧ����ܭ������ԪԫԬ��ܫԶ��Խ���������������������������ֱ֧��ַ־����ר����";
	wbs[7] = "�ǣ�Gg訰����۰����������˰�߱±Ʊ̱���������Ͳ��в�貲����뷴������譴��������鵽������ඹ�������Ѷ�ج�������󸦸�ؤتب��������������������������آ���Լ������ۣ��ꧼ߼����誽���������忪�������������������������۪����������������������������õ��������ĩ����ث�Ū��ا������ƽ����������������������ئɪɺ��������������������������������������������������������أ����������������ѳ������۳����������һ�������������������������������յ�����������ֳ��ۤ����׸��";
	wbs[8] = "�ȣ�Hh���벷���ǲ��Ӳ���������ݳ����ƴ���������㶢��������ح��򮻢�����޾������������ǿ������������¬�­±²�����������������Ŀ����Ű��Ƥ��Ƶ����������ȣ�������˯˲������������ͫ͹��ϹЩ����ѣ��������������գ��հռս����ֹ��׿��������������";
	wbs[9] = "�ɣ�Ii����������������������������������멳��������γس����ȴ���壵����ʵεӵ���¶������������Ƿз���㸡�����ٸ������Ƹ۹������ʹ��������������婺�尺Ӻ�������������䰻������佻��������䧻�䫻��������䩼�䤼��ս�������䮽��н������ƾھ�举�������������������������������������������������������������©��������º������������������û�������������������ĭĮ����������ŢŨŽ��������������������Ư������������������������ǢǱǳ����������ȸȾ������������ɬɳ��������������������������������ʡʪ������������ˮ�������������������̶̭̲���������������������ػ����͡��Ϳ�������������Ϋ�μ���������������ϫ���Ϫϴ��������������СФйк������������������ѧ���Ѵ������������������ҫҺ��������������Ӿӿ����������ԡ��Ԩ��Դ�������մ�տ�������������֭����������ע��������������";
	wbs[10] = "�ʣ�Jj�Ӱ������������������˳����׳�������ꭵ���������������꽸������ƹ�������������Ϻ�������º�������ͻ׻������̼���������������������������������������������������������������ð�������������������������ů������������������������������������������ɹ�������������ʦʱ����������˧�����������������������������������������������ϺϾ����������ЪЫ���������������������Ұҷ���������ӬӰӳӼ������خ�����������Ի��������������֩����������";
	wbs[11] = "�ˣ�Kk߹���İ�������໰Ȱɰ������Ա��������ϱ������߲�����������𳪳������ʳѳ�������߳���������ߴ��������������������઴�߾�߶����������ڵ������޶����ྲֶྀ��Ͷ���������������ȷͷ���߻����߼���¸��ø����칾�ɹ��۹���ù��˺����ƺ��źǺ����ٺߺ�����������׻����������ߴ��������������¼����ӽ�������౾��������������ǿ�����྿пԿ�ߵ�޿����������������߷�����߿������������������ʿ������·����������������������������������������������������ŶŻſž����������������ơ����Ʒ����������ǲǺ�����������������ɤ��ɶ��������ʷ�����˱˳������˻����������������̤̣��̾����������������������������Ψζι���������������������������������Х������������ѫѽ������ߺҧҭҶ��������߽���������۫Ӵ��ӽӻ������ԱԾ��������������߸զ��������֨����ֺֻ������������������������������";
	wbs[12] = "�̣�Ll���հ�����������������������������̹�����غں�����ػ�������¼׼ݼ���νϽ��������������������������������������īĬ���������������ǭǵ������������Ȧ���������������˼������ͼ��������ΧηθϽ������Ѽ�����������������԰Բԯ����������նշ�����������������ת���";
	wbs[13] = "�ͣ�Mm������ᱰܱ����±����ƲƲ�᯳����״ʹ��ϵ��ص����۵�����ǶĶ��뷫ᦷ��������᥸�����Ըո���ḹ�����������������᲻˻ϻ�᧼�����ᵼ����������������Ⱦ���������������ܿ��������������¸��ñ��������������������Ƕ�������Ƚ����ɽɾ����������������������̿������ͬͮ��������Ρ������Ͽ�������������������������Ӥ�������������������������ո����������֡�������������׬����";
	wbs[14] = "�Σ�Nn����ͱ�㹱ٱ��Աܱ��������޲��Ѳ�������������������ٳ����㰳��������㲴����򵬵��ᵼ�����󶮶�����㵷���㭷����ĸҹֹߺ������޺���ﻳ�Ż̻лֻ��켺�ɼ½쾡��㽾Ӿ־���������鿶��㡿���������������¾��������æü����ؿ���������������ų����������ƨ�Ʃ��ǡ��������������������ʬʭʺ��������ˢ˾����������������������Ωβξο��������ϧϬϰ����ми�����������������Ѹ������������������������������������������������չ�������������";
	wbs[15] = "�ϣ�Oo�α���������Ӳ��̳��㴶�ٴִ�ƶ��������ܷ۷��������ʺ��������κ����ͻ���ݽ����������߿�����������������������������¦¯��ú��������Ŵ��������Ȳȼ������ɿ����������˸��۰�������������ϩ��Ϩ���������������������ҵ��������������������ըճ������������";
	wbs[16] = "�У�Pp���������ٱ���������ѱ���������巳����ݳ���Ҵ�������������崵�����ֶ��𸤸����˸�ѹӹٹ�峺������ֺ׺���徻��ջ���żļ�������忽��ƽ󾽾������������̿տܿ߿��������������������»����������ڢ��������ڤį�����ũ����������������������������ȹ������������������������ʵ������������������̻�����ͻ��������������������������д����Ѩ���Ҥ���������������Ԣԣԩ۩����լխկ�����֮������ڣ��ף�����������";
	wbs[17] = "�ѣ�Qq�����������Ӱ��������������������������ٱ������ಬ���в���������β���������˳���������ۻ��������˴������ﱴ�������صۡ���������������������׶��ƶ���۶���ﰶ��������ܶ��Ƕ��ﷰ����������������������븺�����ŸƸָ���Ӹ�����������������������������������������������������������ۨ��ۼ�������������켢�������������ﵽ����޽ǽƽȽ����ڽ��Ľ���˾�ⰾ��þľ�︾��Ҿ���������������������������������������������������������������������������������������������³��������������������èêîíó���þ�����������������������������������������������������ť���������������������������ǥǦ��ǮǯǷ��������������������۾�����Ȼ��������������ɫ�ɱɲ�ɷ���������ʨ���ʴ��������߱������������������������̡��������������������������ͭ���������Σ��������������Ϧϣۭ�����ϳ�ۧ�������������������������зп�������������������Ѯ��س�������ҿ���������������������ӡӭ��������������������������ԧԳԹԿ�������աղ������������������������������������׶����������������";
	wbs[18] = "�ң�Rr���߰�������ְǰư��ɰ�������ڰݰ���豨�������ձ����𲦲����������ٲ�����󳭳������ӳ��γֳ�鴤����밴�ߥ�ݴ�����򵣵�����뮵��ĵֵ��������뱶��ܶݶ޶�������������������ߦ�׸޸��롹��Ϲҹ�������⺤���������˻���ߧ���ػ�߫���Ἴ���������븽ӽ��׽ݽ��������ܾݾ������ܿ���������봿ؿٿۿ������������������������������£§ߣ°��������������������ĨĴ����߭��������������šţŤŲ��������������������ۯߨ�Ʋƴƹ���������������Ǥ������������������Ȫȱ��������������ɦɨ������ʧʰ������������������ˤ˩��˺��������̢̧̯̽����������ͦͱͶ���������������������������������ЮЯߢж��ߩ����Ѻ�����������ҡ��ҴҾ���������ӵ��Ԯ�����������������ժ��������������ߡ������شִ����ָ����ֿ�������ۥ��ץצק׫ײ׾׽ߪ��߬ߤ";
	wbs[19] = "�ӣ�Ss��ذ��������輱���ı����Ĳ�農���߳���������ȳ��˳����������鳴�������������嵵��馶�����������鲷�����鼷����ٷ������Ÿ˸����ϸ����¸�������۹�����������������������������뻱�������鮼ϼ��ż�饼����������Ƚ�����駽������۲���ӿ���¿ÿɿݿ�����������������������������������������������������¥����´����ö÷�ø������������ģľ���������������������ƮưƱ��������������ǹ�����������Ȩȩȶ������ɭɼ�����������������˨��������������̪��̴������������ͩͪͰ������������Φ������������ϭ������������УШе������������������������������ҪҬ������ӣ����������������դեջ���������������֦��ֲ������������������׮׵������������";
	wbs[20] = "�ԣ�Tt��᮰°ʰް�����������Ǳ����������������ֱ��������������߳��䳹�Ƴ˳ͳ̳���������������������Ѵ����޴��������δ���쵾�õ�������еѵ���뺶�����빶��ƶ������췦�����������������������͸���غ�ݸ��۬���������ѹ����������Թ��������̺ͺܺ�������˻�����ɻջ�������������ż�����ռڼ����ȼ�림�����սֽ�̾�����������������ؿ������������������������������¨���������������ë��ôÿ�����������������ĵ�����������������������Ƭ��ƪد��۶���������ǧǨ�ǩ�������������������������������ɸ����������������������������ʣʸ��������������˰˽������������̺������������ͧ͢Ͳ͸ͺͽ��ر������΢ί��κ��������������Ϣ��Ϥϡ����ϵ������������������Цض��������ѡѪѬѭ��������������ز������������ط���������ع������������������������էձ�����������֪������������������������������׭����������";
	wbs[21] = "�գ�Uu�������걱�����űձֱԱױ��������������������곲����������Ѵ������񬴯�ôɴ��˴δմ���񵥵���������Ƶܵ۵������۶������˶��շ����������������ع�������غ�������������Լ�񤼽���������ϼ����彪���������������ܽ��ɽ꾻���������ξξ��þ������������������������������������������������������������������������������������ű��������ƣƦ�Ƴƿ������ǰǸǼ������������ȭȬȯȳ�����������������۷������������˷��ڡ�����������̵̱������������ͯʹͷ��������������������������������Ч���������ѢѾ�����������������������ұ������������������Ӹ�����������������բ���վ��۵������֣֢��������ױװ��׳״׼���������������������";
	wbs[22] = "�֣�Vv�������滰�����ϳ�����槴�����淶ʶ�湷�����������Ź�棺ûٻ鼧������˼��߼޼齨毽�����������žʾ˾�����ѿ�ظ�����������¼������ý����������ķ��������������ū����Ŭ����ŭŮ����������Ⱥ���������ɩ���ۿ������ʼ���ˡ���������������������������������ϱ�������������ѰѲ���������Ҧ����������������������������������";
	wbs[23] = "�ף�Ww�����˰ְ۰����ұ��������±��ϲ��������٭���������ѳ�ٱ�Ŵ������ӴԴ���ߴ���ᷴ������ٵ����ǵʵ͵���궱�ζ�٦���ҷ·ַݷ���ٺ�������������������٤��������������Ĺ�����Ϻκ���򻪻�����٥�����ʼ��Ѽۼټ�������Խ�������ٮ�Ľ�������־��ƾ���������٩����٨��ۦ��������ٵ����ٳ�����������������������������������ٰ������٣��������ٯ��żٽ������Ƨƫƶٷƾ����Ǫ��ٻ���������������ٴȫ���������������ټ��ɡɮɵ���������ʲʳʹ������ٿ�������ٹ��������������̰��������٬ͣ��١��͵;��٢����ΰαλ����������������������������б�������������ٲ������ү��������������٫Ӷٸ��������٧������������ٶ��������ծ������ֵֶ����٪��ס��׷پ��������������";
	wbs[24] = "�أ�Xx�����ذ�ȱϱѱ��������Ͳ��ڳ�穴���窵��޶�綷�糷ѷ׷츥������礸�������箹��ù��笺�컡�ٻ��û��������ܼ��ͼ̼����ֽ����ʽɽԽ��ƾ�������������������������������������������������ĸ��Ŧ��������ǿ�����������������ɴ�������������˿�����������ͳ�����άγ����ϸ���������������������Ѥ��������������ӧ�ӱ��������ԵԼ���������ּֽ֯���������׺�����������";
	wbs[25] = "�٣�Yy����������������ر��������������Ʋ������߳ϳ䴲�ȴʵ���ڮ���е�����������ض��̷������÷���̷Ϸ������ø߸�ھ����ڸڬ��ڴ���ѹ������������ڭ����ڧ�����軰����ڶ����ڻ�������ƼǼ������ɽ�ڦڵ����۾�������ڪ�����念���̿ο�ڲڿ���������������ڳ��������������������������®¹���������������������������á��ä���å��������������������ĦĥħıĶګ�ŵک���������������������������������ǫǴ����ڽ����ڰڹȿ����ڨ������ڷ��ʫʩʶ��������������˥˭˵����������̸̷����ͤͥ��������������Ϊ��ν������������ϯ��������г��л������ڼ������������ѯѵѶ��ڥ������ҥҹ����ڱ�����������������Ӧ��ӥ��ӮӹӺ���������������������թի���گ������������֤ں����������ؼ����ׯ׻��������������";
	wbs[26] = "�ڣ�Zz";
	for(int i = 0; i < 25; i++)
	{
		for(int j = wbs[i + 1].length() / 2; j >= 0; j--)
		{
			wbs[i + 1].insert(j * 2, " ");
		}
	}

	int i, j;
	string rtns, hz, hz2;
	rtns = "";
	for (i = 0; i < StrLen(hzs); i++)
	{
		hz = StrSub(hzs, i, 1);
		if ((unsigned char)(hz[0] & 0x80) > 0)
		{
			if (i < StrLen(hzs) - 1)
			{
				hz2 = StrSub(hzs, i + 1, 1);
				if ((unsigned char)(hz2[0] & 0x80) > 0)
				{
					hz += hz2;
					i++;
				}
			}
		}

		if ((hz[0] > 160) || (hz[0] <= 0))
		{
			for (j = 1; j <= 26; j++)
			{
				if (StrPos(wbs[j], hz) >= 0)
				{
					break;
				}
			}
			if ((j <= 26) && (j >= 1))
			{
				rtns += (64 + j);
			}
			else
			{
				rtns += hz;
			}
		}
		else
		{
			rtns += hz;
		}
	}
	return rtns;
}

string String::StrFormat(const char *fmt, ...)
{
	va_list argptr;
	va_start(argptr, fmt);
	string outs = StrFormat(fmt, argptr);
	va_end(argptr);
	return outs;
}

string String::StrFormat(const char *fmt, va_list argptr)
{
	char  buffer[512];
#ifdef WIN32
	vsnprintf_s(buffer, 512, 512, fmt, argptr);
	//vsnprintf(buffer, sizeof(buffer), fmt, argptr);
#else
	vsnprintf(buffer, 512, fmt, argptr);
#endif
	return buffer;
}

#ifdef WIN32

/*NULL*/

#else

static int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	iconv_t cd;
	int rc;
	char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open(to_charset, from_charset);
	if (cd == 0)
		return -1;
	memset(outbuf, 0, outlen);
	if (iconv(cd, pin, &inlen, pout, &outlen) == -1)
		return -1;
	iconv_close(cd);
	return 0;
}

#endif

string String::StrConvertUtf8ToGbk(char* utf8)
{
#ifdef WIN32
	int buffLen = 0;
	WCHAR wbuff[5120];
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wbuff, 5120);
	buffLen = WideCharToMultiByte(CP_ACP, 0, wbuff, -1, NULL, 0, 0, 0);
	char* m_gb2312 = new char[buffLen + 1];
	WideCharToMultiByte(CP_ACP, 0, wbuff, -1, (LPSTR)m_gb2312, buffLen, 0, 0);
	string s_gb2312 = StrConvert(m_gb2312);
	delete[] m_gb2312;
	return s_gb2312;
#else
	int inlen = strlen(utf8);
	int outlen = inlen + 1;
	char* outbuf = new char[outlen];
	memset(outbuf, 0, outlen);
	code_convert("utf-8", "gb2312", utf8, inlen, outbuf, outlen);
	string s_gb2312 = StrConvert(outbuf);
	delete[] outbuf;
	return s_gb2312;
#endif
}

string String::StrConvertUtf8ToGbk(string utf8)
{
	char* putf8 = StrConvert(utf8);
	return StrConvertUtf8ToGbk(putf8);
}

string String::StrConvertGbkToUtf8(char* gb2312)
{
#ifdef WIN32
	int buffLen = 0;
	WCHAR wbuff[5120];
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wbuff, 5120);
	buffLen = WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, NULL, 0, 0, 0);
	char* m_utf8 = new char[buffLen + 1];
	WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, (LPSTR)m_utf8, buffLen, 0, 0);
	string s_utf8 = StrConvert(m_utf8);
	delete[] m_utf8;
	return s_utf8;
#else
	int inlen = strlen(gb2312);
	int outlen = inlen * 3 + 1;
	char* outbuf = new char[outlen];
	memset(outbuf, 0, outlen);
	code_convert("gb2312", "utf-8", gb2312, inlen, outbuf, outlen);
	string s_utf8 = StrConvert(outbuf);
	delete[] outbuf;
	return s_utf8;
#endif
}

string String::StrConvertGbkToUtf8(string gb2312)
{
	char* pgb2312 = StrConvert(gb2312);
	return StrConvertGbkToUtf8(pgb2312);
}

int String::StrGetHashCode(string s)
{
	return StrGetHashCode(StrConvert(s));
}

int String::StrGetHashCode(char* pchar)
{
	int i=0;
	int h=0;
	while (pchar[i] != 0)
	{
		h += h * 31 + pchar[i];
		i++;
	}
	return h;
}


#define STRENCDEC_C1 52845
#define STRENCDEC_C2 22719

string String::StrEncrypt(string S, long long Key)
{
 	string result, str;
// 	int i, j;
// 
// 	result = S; // ��ʼ������ַ���
// 	for(i = 0; i < (int)S.length(); i++) // ���ζ��ַ����и��ַ����в���
// 	{
// 		result[i] = S[i] ^ (char)(Key >> 8); // ����Կ��λ�����ַ����
// 		Key = ((BYTE)result[i] + Key) * STRENCDEC_C1 + STRENCDEC_C2; // ������һ����Կ
// 	}
// 	S = result; // ������
// 	result.clear(); // ������
// 	for(i = 0; i < (int)S.length(); i++) // �Լ��ܽ������ת��
// 	{
// 		j = (BYTE)S[i]; // ��ȡ�ַ�
// 		// ���ַ�ת��Ϊ������ĸ����
// 		str = "12"; // ����str����Ϊ2
// 		str[0] = 65 + j / 26;//���ｫ65�Ĵ���������256�����ľͻ�����룬Ч�����ã���Ӧ�ģ����ܴ�Ҫ��Ϊ��ͬ����
// 		str[1] = 65 + j % 26;
// 		result += str;
// 	}
 	return result;
}


string String::StrDecrypt(string S, long long Key)
{
 	string result, str;
// 	int i, j;
// 
// 	result.clear(); // ������
// 	for(i = 0; i < (int)S.length() / 2; i++) // ���ַ���������ĸһ����д���
// 	{
// 		j = ((BYTE)S[2 * i] - 65) * 26;//��Ӧ�ģ����ܴ�Ҫ��Ϊ��ͬ����
// 
// 		j += (BYTE)S[2 * i + 1] - 65;
// 		str = "1"; // ����str����Ϊ1
// 		str[0] = j;
// 		result += str; // ׷���ַ�����ԭ�ַ���
// 	}
// 	S = result; // �����м���
// 	for(i = 0; i < (int)S.length(); i++) // ���ζ��ַ����и��ַ����в���
// 	{
// 		result[i] = (BYTE)S[i] ^ (char)(Key >> 8); // ����Կ��λ�����ַ����
// 		Key = ((BYTE)S[i] + Key) * STRENCDEC_C1 + STRENCDEC_C2; // ������һ����Կ
// 	}
 	return result;
}