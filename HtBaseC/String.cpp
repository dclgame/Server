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
/* ×Ö·û´®´¦Àí                                                           */
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
	_i64toa_s(lval, strNum, pcharLen + 1, 10);//ÕâÀï10´ú±í°´ÕÕ10½øÖÆ½øÐÐ×ª»»
	//_i64toa(lval, strNum, 10);//ÕâÀï10´ú±í°´ÕÕ10½øÖÆ½øÐÐ×ª»»

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
	pys[1] = "£Á£áAaß¹°¢°¡ï¹àÄ°¥°§°¦°£°¤ïÍÞß°¨°©àÈ°«°ªö°°¬°®íÁ°¯àÉæÈ°­êÓè¨°²èñ°±âÖÚÏðÆ°°°³Ûûï§Þîáí°¶°´°¸°·°µ÷ö°¹°º°»°¼Ûê°½à»âÚéáåÛ°¾°¿ñúòü÷¡÷éÞÖ°ÀæÁá®°Á°Âæñ°Ä°ÃöËÚÆëç";
	pys[2] = "£Â£âBb°Ë°Í°È°Ç°Éá±°Å°Ì°Æ°ÊôÎ°ÎÜØÝÃ°Ï÷É°ÑîÙ°Ð°Ó°Ö°ÕöÑ°Ôå±êþ°×°Ù°Û°ØÞã°ÚßÂ°Ü°Ý°Þ°â°à°ã°ä°ß°áñ£ñ­ÚæÛà°å°æîÓô²°ì°ë°é°ç°è°í°ê°î°ï°ðäº°ó°ñ°ò°ö°ø°ô°ùÝò°õ°÷°üæß°ú°ûìÒöµ°ý±¢±¦±¥±£ð±±¤ÝáñÙ±¨±§±ªõÀ±«±©±¬Úé±°±­±¯±®ðÇ±±±´±·Úý±¸±³±µ±¶ã£±»±¹±º±²íÕÝíñØ÷¹öÍ±¼êÚï¼±¾±½ÛÎÛÐ±¿±À±ÁàÔ±Â±Ã±Åê´±Ä±ÆÝ©±ÇØ°±ÈßÁåþ±ËïõÙÂ±Êô°±É±Ò±Ø±Ï±Õ±Óî¯ßÙ±ÑÜê±Ý±Ðáùîéæ¾âØ±ÖÝÉåöã¹óÙää±Ô±ÍñÔõÏ±×±Ìóë±Î±Úó÷Þµ±Üå¨±Û÷ÂèµôÅ±ßí¾óÖ±àìÔòùöý±Þ±á±âñ¹ØÒíÜñÛ±åÛÍâíãêÜÐ±ã±äçÂ±é±æ±ç±èè¼±ë±êì©÷Ôæô±ìñ¦ïÚì­ì®ïð±íæ»ñÑ÷§±ï±î±ðõ¿±ñ±ö±òÙÏ±ó±õçÍéÄïÙ±ôáÙ±÷éëë÷÷Æ÷Þ±ù±ø±ûÚû±ü±ú±þ±ýÙ÷²¢²¡Þð²¦²¨²£°þ²§âÄà£²±²¤²¥²®ØÃ²µ²¯²´²ªÙñîà²¬²°²©²³ð¾²«²­²²õÛ±¡íçõËô¤ë¢éÞåÍîßêÎõ³²·ß²²¹²¸²¶²»²¼²½²ÀîÐ²¿²ºê³²¾çãçÔ°ÒÜÅÛý";
	pys[3] = "£Ã£ãCcàê²Áíå²Â²Å²Ä²Æ²Ã²É²Ê²Ç²È²Ë²Ì²Îæî²Í²Ð²Ï²Ñ²Ò÷õ²ÓôÓè²²ÖØ÷²×²Ô²Õ²Ø²Ù²Ú²ÜàÐäî²Ûô½ó©²Ý²á²à²Þâü²â²ßá¯ä¹àá²ã²ä²æè¾²åâÇïÊ²é²ç²è²ëâªé¶²ì²êéßñÃïïãâ²í²ïæ±²î²ðîÎÙ­²ñ²òò²ðûêè²ô²óæ¿²÷åîìø²ö²ø²õâÜäýïâó¸õð²ú²ù²ûÝÛÙæâã²üåñØö²ýæ½²þÝÅãÑöð³¤³¦ÜÉ³¢³¥³£áäæÏ³§³¡êÆã®³¨âê³©³«ÛË³ª³­â÷³®ìÌ³¬êË³²³¯³°³±³³³´ñé³µíº³¶³¹Ûå³¸³·³ºÞÓ³»è¡àÁ³¾³¼³À³Á³½³Âå·³¿ÚÈí×´³³Ä³Æö³³Ãé´ÚßèßòÉîõ³ÅîªØ©³É³Ê³ÐèÇ³Ï³Ç³ËÛôîñ³Í³ÌñÎëóõ¨³Î³È³Ñ³Ò³Ó³Ôßêò¿ð·í÷ó×àÍæÊ³Õó¤÷Î³Ú³Ø³Û³ÙÜÝ³Ö³×Ü¯õØóø³ß³Þ³Ý³ÜôùñÝáÜß³³â³àâÁ³ã³áë·à´ÙÑñ¡³ä³åâçÜûô©ã¿ô¾³æ³ç³èï¥³éñ¬³ðÙ±àü³ñ³ë³î³í³ï³ê³ìöÅ³ó³ò³ô³ö³õéËÛ»³ý³ø³ü³úòÜ³û³÷³ùõéèÆ´¡´¢èú³þñÒØ¡´¦âðç©´¤´¥ãÀ÷í´£Þõ´§à¨àÜõßçÝ´¨ë°´©´«ô­´¬å×´ªâ¶´­´®îË´Ñ´¯´°´²´´âë´µ´¶´¹Úï´·é¢é³´¸´º´»òí´¿´½Ý»´¾ðÈ´¼´ÀõÖ´Á´Âê¡öºßÚ´Ã´ÊìôÜë´Ä´É´È´Ç´Å´ÆðËôÙ´Ë´Î´Ì´Í´Ó´ÒÜÊèÈ´Ðæõè®´Ï´ÔäÈçý´Õé¨ëíê£´ÖáÞéã´Ùâ§õ¡Ýý´×´Øõ¾õíÙàß¥ïé´Ú´Ü´Ûìà´Þ´ß´ÝéÁè­´àßýã²´ãÝÍë¥´á´â´ä´åñå´æââ´ç´ê´è´éõãáÏðîïóõºëâØÈ´ì´ëï±´íÛæÞÃä°ÚÃâàé«ëúå¤æö´±ö¿";
	pys[4] = "£Ä£äDdßÕÞÇ´îàªñ×´ïæ§âòí³óÎ´ð´ñ÷°÷²´ò´ó´ôß¾´õ´ö´úá·ß°çªåÊ´ø´ýµ¡´ùçé´ûÜ¤´ü´þ´÷÷ìµ¤µ¥µ£íñµ¢µ¦ñõééð÷óìÙÙµ¨ðãµ§µ©µ«µ®à¢µ¯µ¬µ­ÝÌµ°µªå£µ±ñÉµ²µ³ÚÔÛÊå´í¸µ´µµÝÐµ¶ß¶âáë®µ¼µºµ¹µ·µ»µ¸µ½µ¿ìâµÁµÀµ¾ôîµÃï½µÂµÄµÆµÇàâô£µÅµÈê­µËµÊáØµÉíãïëµÍôÆµÌàÖµÎïáµÒÙáµÏµÐµÓÝ¶µÑêëµÕØµÚ®Û¡µ×µÖèÜíÆ÷¾µØµÜµÛæ·µÝµÚÚÐé¦íûµÞµÙíÚàÇµàµáµßáÛñ²µäµãµâõÚµçµèµéÚçÛãµêµæçèîäµëµíµìµîµåñ°ô¡µóµðµòõõµïµñöôµõµöµ÷µôîöµùµøµüÛìð¬µýà©Ü¦ÞéñóµþëºµúµûõÞöø¶¡Øê¶£çàðÛ¶¢¶¤ñôôú¶¥¶¦¶©¶¨à¤ëëíÖ¶§¶ªîû¶«¶¬ßËá´ë±ð´¶­¶®¶¯¶³¶±Ûíá¼¶²¶°¶´ëËëØíÏ¶¼¶µÝúóû¶·¶¶¶¸ò½¶¹¶º¶»ñ¼à½¶½¶¾¶ÁäÂèüë¹¶¿÷ò÷Ç¶ÀóÆ¶Â¶Ä¶ÃÜ¶¶Ê¶Å¶Ç¶È¶É¶Æó¼¶Ë¶Ì¶Î¶Ï¶Ðé²ìÑ¶Íóý¶Ñ¶Ó¶Ô¶Òí¡íÔí­ïæ¶Ö¶Ø¶Õíâ¶×íïõ»¶Úãç¶Üí»¶Û¶Ù¶Ý¶àßÍ¶ßñÖ¶áîì¶Þõâ¶äßá¶âç¶¶ã¶çãõ¶é¶æ¶è¶åØçç¿í±ëÀææêæç°ï¢î®îúèÞØýµÔØ¼";
	pys[5] = "£Å£åEeåí¶ï¶í¶ð¶ëÝ­ï°¶ì¶ê¶îæ¹¶òßÀ¶óÜÃéîÛÑ¶ñ¶öÚÌ¶õãÕãµÝà¶ôëñïÉðÊò¦Ø¬öù¶÷ÝìÞô¶ù¶øð¹öÜ¶û¶úåÇ¶ý¶üçíîï¶þÙ¦·¡ÚÀ";
	pys[6] = "£Æ£æFfÙè·¢·¦·¥ÛÒ·£·§·¤·¨íÀ·©·«·¬á¦·­·ª·²·¯·°·³·®Þ¬ìÜ·±õìÞÀ·´·µ·¸·º·¹·¶··î²èó·½Úú·»·¼èÊîÕ·À·Á·¿·¾öÐ·Â·ÃáÝ·Äô³·Å·Éåú·Ç·Èç³·Æìéòãö­öî·ÊäÇëè·Ë·Ìã­ì³é¼ôäóõ·Í·Ï·Ðáô·Î·ÑðòïÐ·Ö·Ô·×·Ò·Õ·Ó·Ø·Úèû·Ù÷÷·Û·Ý·Ü·ÞÙÇ·ß·àö÷å¯·á·çãã·ã·â·èí¿·å·éÝ×·æ·äÛº·ë·ê·ì·íßô·ï·îÙº·ðó¾·ñ·òß»·ôõÃôïïûõÆ·õ·ó¸¥·üÙìæÚ·öÜ½ÜÀâö·÷·þç¦ç¨ÜÞ·ý·úìðî·ÜòÛ®¸¡íÉÝ³ò¶Ùëèõ¸¢·ûåõÝÊ¸¤·ù¸£òÝ·øá¥òðíê¸§¸¦¸®ÞÔ¸«¸©¸ª¸¬¸¨¸­äæ¸¯íë¸¸¸¼¸¶¸¾¸º¸½¸À¸·æâ¸´¸°¸±¸µ¸»¸³¸¿¸¹öÖêçòóöû¸²ð¥";
	pys[7] = "£Ç£çGgê¸îÅæÙ¸Â¸ÁæØÞÎ¸ÃÚëÛòêà¸ÄØ¤¸Æ¸Ç¸Èê®¸Å¸É¸Ê¸Ë¸ÎÛáãïÜÕ¸Ì¸ÍðáôûÞÏ¸Ñ¸Ï¸Ò¸Ðä÷éÏß¦êºí·ç¤äÆ¸Ó¸Ô¸Õ¸Ú¸Ù¸Ø¸×¸Öî¸¸Û¸Üóàí°¸Þ¸á¸ßéÀØº¸à¸Ý¸âê½¸ãçÉéÂ¸å¸äÞ»¸æÚ¾Û¬ï¯¸êÛÙæü¸í¸ç¸ìñË¸ë¸î¸é¸è¸ó¸ï¸ñØª¸ð¸ò¸ôàÃÜªë¡ëõïÓ÷ÀÛÁô´¸ö¸÷ò´íÑ¸õ¸ø¸ù¸úßçØ¨ôÞÝ¢¸ü¸ý¸ûâÙ¸þßì¹¡ç®¹¢¹£öá¹¤¹­¹«¹¦¹¥¹©ëÅ¹¬¹§ò¼¹ª¹¨ö¡¹®¹¯¹°çî¹²¹±¹´Øþ¹µ¹³çÃóô÷¸á¸¹·¹¶èÛóÑ¹¹Ú¸¹º¹¸¹»æÅì°åÜêí¹À¹¾¹Ã¹Â¹Áéïð³¹½ÝÔòÁõý¹¼ôþì±¹¿÷½¹ÅãéÚ¬¹È¹Éêô¹Çî¹îÜ¹ÆðÀ¹ÄØÅëûî­¹Ì¹Ê¹ËáÄèôêö¹ÍðóïÀöñ¹Ï¹ÎëÒð»ßÉ¹Ð¹ÑØÔÚ´¹Ò¹Ó¹Ô¹Õ¹Ö¹Ø¹Û¹Ù¹ÚÙÄ¹×÷¤¹Ý¹Ü¹á¹ßÞèäÊîÂ¹àðÙ¹Þ¹âßÛèæë×¹ãáî¹ä¹é¹çæ£¹ê¹æð§¹ë¹è¹åöÙå³¹ìâÑØÐ¹î¹ï¹íêÐóþ¹ôØÛ¹ñêÁ¹ó¹ð¹ò÷¬Ùòçµ¹õ¹öíÞöç¹÷ßÃÛö¹ùáÆñø¹øòå¹úàþÞâë½Ùå¹ûâ£é¤òä¹ü¹ýò¢èíÚàñæèéâ»Ý¸Øî";
	pys[8] = "£È£èHhã°îþ¹þàËº¢º¡º£ëÜõ°º¥º§º¦º¤ñüòÀº¨º©÷ýÚõº¬ºªº¯êÏº­ìÊº®º«º±º°ººº¹ºµº·º´º¸ÝÕò¥Þþº¶º³º²å«º»º¼ç¬º½ñþãìÝïàãÞ¶òººÁàÆºÀº¿º¾å©ºÃºÂºÅê»ºÆºÄð©ò«å°Ú­ºÇºÈàÀºÌºÏºÎÛÀºÍºÓêÂºÒºËîÁºÉºÔºÐºÊòÂºÑãØôçºØºÖºÕº×ÛÖºÚºÙºÛºÜºÝºÞºàºßºãèìçñºáºâÞ¿ºäºåÙêºæÞ°ºëºìºêãÈãüºéÝ¦ºçºèÞ®ÙäÚ§ºîºíºïðúóóô×÷¿ºðºóºñááåËºòÜ©ö×ºõºôºöìÃéõßüã±äïàñ»¡ºüºúºøõúºþâ©ºùìÎº÷ðÉéÎºýºûõ­ì²»¢»£çú»¥»§Ùü»¤»¦á²âïìæìïóËìèð­ð×»¨»ª»©æèîü»¬»«»¯»®»­»°èë»³»²»´»±õ×»µ»¶âµ»¹»·Û¨ä¡»¸ÝÈïÌå¾çÙ÷ß»º»ÃÛ¼»Â»½»»ä½»Á»¼»ÀåÕ»¾»¿äñöéß§ëÁ»Ä»Å»Ê»ËÚò»Æáå»ÌäÒåØ»Íäêè«óò»Èñ¥»Ç»Éó¨öü»Ð»Î»Ñ»Ï»ÒÚ¶ßÔ»Ö»Óò³êÍçõ»Ô÷â»ÕãÄ»Øä§Üî»×»Ú»Ü»ã»á»äßÜä«»æÜö»åí£»â»ßåç»Þ»àà¹»ÝçÀ»Ù»ÛÞ¥ó³»è»ç»éãÔ»ëâÆ»êÚ»»ìäãñëïÁØå»íß«»î»ð»ïîØâ·»ò»õ»ñ»ö»ó»ôïìàëÞ½ó¶ãÛÀ£ÛÉí¹Ú¥à÷";
	pys[9] = "£É£éIi";
	pys[10] = "£Ê£êJjÜ³ë©ìÀÙ¤Ø¢¼¥»÷ß´¼¢ØÀ»ø»úçá¼¡Ü¸í¶¼¦ßÒ¼£ØÞßó¼§åì»ýóÇ»ù¼¨ïúê÷¼©êå»ûõÒ»þçÜì´ÛÔ¼¤î¿¼°¼ªá§¼³¼¶¼´¼«Ø½Ù¥¼±óÅ¼²ê«¼¬éê¼¯¼µé®Ýð¼­ñ¤Þª¼®¼¸¼ºò±¼·¼¹ÞáêªáÕ÷ä¼Æ¼Ç¼¿¼Í¼Ë¼É¼¼ÜÁ¼Ê¼Á¼¾ßâ¼Èä©¼Ã¼ÌêéÙÊ¼Å¼Ä¼Â¼À¼»ôßõÕö«öÝð¢öê¼½÷Ùæ÷¼Ó¼Ð¼ÑåÈ¼Ïä¤çì¼ÒðèóÕôÂñÊÝçõÊ¼ÎïØáµÛ£¼Ôí¢ê©îòòÌ¼Õ¼×ëÎ¼Ö¼Øðý¼Û¼Ý¼Ü¼Ù¼Þ¼Úê§¼é¼â¼á¼ß¼ä¼ç¼è¼æ¼à¼ãÝÑäÕêù¼êÞö¼åçÌÝóöäðÏ÷µàî¼ðèÅ¼ó¼í¼ë¼ñóÈ¼õ¼ô¼ìõÂíú¼ïñÐïµ¼òÚÙê¯¼îôååÀå¿¼û¼þ½¨½¤½£êð¼ö¼ú½¡½§½¢½¥ÚÉé¥ë¦½¦ëì¼ù¼ø¼üÙÔ¼÷¼ýõÝ½­½ª½«Üü½¬ôø½©çÖíä½®½²½±½°½¯ñð½³½µä®ç­½´êñôÝÜ´½»½¼æ¯½¿½½Üú½¾½º½·½¹òÔõÓÙÕöÞ½¶½¸ðÔ½ÇÙ®½ÄÞØ½Æ½Ê½Èð¨½Ã½Å½Â½ÁäÐ½Ëë¸áè½É½Ðá½½Î½Ï½Ì½Ñ½ÍàÝõ´½×ðÜ½Ô½Ó½Õà®àµ½Ò½ÖæÝ½ÚÚ¦½Ù½ÜÚµÞ×½à½áèîæ¼½Ýò¡½Þ½ØíÙ½ßöÚôÉ½ã½â½é½ä½æ½ì½ç½ê½ë½èò»÷º½å½í½ñ½ï½ð½òñÆ½î½ó½öÚá½ôÝÀ½÷½õâÛâËéÈèª¾¡¾¢æ¡½ü½øÝ£½ú½þ½ýêáçÆ½û½ùêîàä¾©ãþ¾­¾¥¾£¾ªìºÝ¼¾§ëæ¾¦¾¬¾¤¾«¾¨¾®ÚåØÙëÂ¾±¾°ÙÓã½¾¯¾»åò¾¶åÉëÖ¾·¾ºæº¾¹¾´ö¦¾¸¾³â°¾²¾µìçåÄ¾¼¾½¾À¾¿ð¯ôñãÎà±¾¾÷Ý¾Å¾Ã¾Ä¾Á¾Â¾Æ¾É¾Ê¾Ì¾ÎèÑèê¾Ç¾È¾Í¾ËÙÖðÕ¾Ó¾Ð¾ÑÜÚ¾Ô¾ÒÞäé§è¢ôòï¸ñÕöÂ¾Ï÷¶¾Ö½Û¾ÕéÙ¾×¾Ú¾Ù¾ØÜìé°ö´õá¾ä¾ÞÚª¾ÜÜÄ¾ß¾æîÒ¾ãÙÆ¾ç¾å¾Ý¾àêøì«¾âñÀ¾Ûåð¾áåáõ¶¾ê¾èä¸¾éïÔîÃ¾íïÃ¾ëèðáú¾îöÁ¾ìÛ²àÙ¾ïæÞ¾ö¾÷¾ñçå¾ø¾õ¾óáÈ¾òèöõûØÊØãÚÜâ±Þ§àåéÓ¾ôïãõê½ÀÛÇìß¾ð¾ü¾ý¾ù¾ûñä¾úóÞ÷å¿¡¿¤¾þÞÜ¿£¿¥¿¢Ú¢ÜùéÇ";
	pys[11] = "£Ë£ëKkßÇ¿§¿¦¿¨ØûëÌ¿ª¿«ï´¿­ØÜÛîâýîø¿®ÝÜ¿¬ïÇâé¿¯¿±íè¿°ê¬¿²Ù©¿³Ý¨¿´î«¿µ¿¶¿·¿¸¿ºØø¿¹ãÊ¿»îÖåê¿¼¿½èà¿¾îíêû¿¿¿À¿Á¿Âçæ¿ÆéððâîÝ¿Ãò¤ïýñ½¿Åî§¿Äòò÷Á¿Ç¿È¿Éá³¿Ê¿Ë¿Ì¿Íã¡¿Îë´æìç¼à¾äÛï¾¿Ï¿Ñ¿Ò¿ÐñÌ¿Ô¿Óï¬¿ÕÙÅáÇóí¿×¿Ö¿Ø¿ÙÜÒíî¿Úßµ¿Û¿ÜóØÞ¢ØÚ¿Ý¿ÞÜ¥¿ß÷¼¿à¿âç«à·¿ã¿á¿äÙ¨¿å¿æ¿è¿çØá¿é¿ì¿ëÛ¦ßàáöëÚ¿ê¿í÷Å¿î¿ïÚ²ßÑ¿ð¿ñÚ¿ÞÅÚ÷ÛÛæþ¿ö¿õ¿óêÜ¿ò¿ô¿÷¿ùã¦¿ø¿ú¿üåÓØ¸à­Þñ¿ûêÒ¿ýî¥òñÙç¿þõÍØÑà°ã´À¢ÝÞÀ¡óññùÀ¤À¥çûï¿÷Õõ«öïã§À¦ãÍÀ§À©À¨òÒÀ«Àªà¬¿©Úóö¸";
	pys[12] = "£Ì£ìLlò®îÄÀ¬À­À²ååê¹íÇÀ®ØÝÀ°ðøÀ¯À±À´áÁáâäµÀ³ïªêãíùÀµäþñ®ô¥À¼á°À¹À¸À·À»À¶À¾À½ñÜìµÀºïçÀÀÀ¿ÀÂé­äíî½ÀÁÀÃÀÄà¥ÀÉÀÇÝ¹ÀÈÀÅÀÆïüï¶òëÀÊãÏÀËÝõÀÌÀÍÀÎßëáÀðìï©õ²ÀÏÀÐÀÑèáîîÁÊÀÔÀÓñìÀÒØìÀÖß·ãîÀÕ÷¦À×æÐçÐéÛÀØÙúñçÚ³ÀÝÀÚÀÙÀÜÀßÀáÀàÀÛõªÀÞàÏÜ¨ÀâÀãÀäã¶ÀåÀæÀêÀëÀòæêÀçð¿ÀìçÊÝñòÛæËÁ§öâÀèÀéî¾Þ¼÷óó»ÀñÀîÀïÙµÁ¨æ²åÎÀíï®Àðå¢õ·÷¯Á¦ÀúÀ÷Á¢ÀôÀöÀûÀøß¿ÛÞÁ¤ÜÂÀýìåèÀðÝÁ¥ÀþÙ³èÝðßÀóéöÛªÀõáûíÂÀùÝ°à¦óÒÁ£ôÏòÃÀüÁ¡îºõÈö¨äàóöÁ©ÞÆÁ¬Á±Á¯Á°Á«ÁªñÍÁ®öãå¥ì¡Á­ó¹Á²çöÁ³ñÏÝüÁ·æ®Á¶ÁµéçÁ´é¬äòÁ¼Á¹Áºé£Á¸Á»Ü®õÔÁ½÷ËÁÁÁÂÁ¾ÁÀÁ¿ÁÉÁÆÁÄÁÅÁÈÁÎàÚå¼ÁÃâ²ÁÇÁÍðÓîÉÞ¤ÁËÞÍÁÏÁÌßÖÁÐÁÓÙýä£ÛøÁÒÞæÁÔÁÑôóõñ÷àÁÚÁÖÁÙßøÁÜÁÕôÔá×åàê¥ÁØî¬Á×ÁÛ÷ëÁÝâÞãÁéÝÁßÁÞÝþì¢õïÁàÁæÁéàòÁëãöÜßèÚÁáê²ÁèÁåÁêèùç±ÁçôáñöÁâòÈÁãÁäöìÛ¹ÁìÁîÁíßÊÁïìÖÁõä¯Á÷ÁôÁðÁòì¼åÞÁóæòÁñÁöïÖöÌÁøç¸ï³ÁùðÒÁúÁüãñÜ×èÐççëÊíÃÁýÁûÂ¡ñªÁþÂ¤Â¢ÛâÂ£Â¦ÙÍà¶ÝäÂ¥ñïò÷÷ÃáÐÂ§Â¨ÂªÂ©ðüïÎÂ¶ààß£Â¬Â®Â«ÛäãòÂ¯èÓëÍéñðµôµÂ­öÔÂ±Â²Â°Â³éÖïåÂ½Â¼Â¸éûäËåÖÂ¹Â»ÂËÂµÂ·äõÂ¾ê¤Âºè´óüðØÂ´ëªÂ¿ãÌéµÂÀÂÂÂÃïùÂÁÂÅÂÆëöñÚÂÄÂÉÂÇÂÊÂÌÂÈÂÏÂÍÂÎèïð½ÙõÂÐöÇÂÑÂÒÂÓÂÔï²ÂÕÂØÂ×àðÂÙÂÚÂÖÂÛÞÛÂÞâ¤ëáÂÜÂßé¡ÂàÂáÂâïÝÂÝÙÀÂãñ§ÙùãøÂåÂçÜýÂæçóÂäÞûäðöÃå²ðÚØéß®ãÜ";
	pys[13] = "£Í£íMmÙûß¼ÂèæÖÂéó¡ÂíáïÂêÂëÂìè¿ÂîßéÂðÂïÂñö²ÂòÝ¤Û½ÂõÂóÂôÂöò©ÂùÂøÂ÷÷´÷©ÂúòýÂüÃ¡Ü¬á£ÂýÂþçÏÂûì×ïÜÚøÃ¦Ã¤Ã£íËÃ§äÝòþÃ¨Ã«Ã¬êóÃ©ì¸òÖÃª÷Öòúó±Ã®á¹ã÷ÜâêÄÃ­Ã¯Ã°Ã³ë£ÙóÃ±è£î¦Ã²í®Ã´Ã»Ã¶ÃµÃ¼Ý®Ã·Ã½áÒäØâ­é¹ÃºÃ¸ïÑðÌÃ¹Ã¿ÃÀä¼Ã¾ÃÃÃÁñÇÃÄÃÂ÷ÈÃÅÞÑîÍÃÆìËí¯ÃÇÃ¥òµÃÈÃËÝùÞ«ëüÃÊíæô¿ÛÂÃÍÃÉÃÌô»òìãÂó·ÃÏÃÎßäÃÖìòÃÔâ¨ÃÕÃÑÃÓ÷ã÷çÃÒÞÂÃ×ØÂåôôÍëßÃÐôéãèåµÃÚÃÙÃØÃÜÃÝÚ×à×ÃÛÃßÃàÃÞÃâãæö¼ÃãííÃäÃáäÏÃåëïÃæß÷ÃçÃèÃéðÅèÂíðÃëíµÃìÃêåãÃîÃíØ¿ßãÃðÃïóúóºÃñáºçäÜåçëçÅÃóãÉÃòãýÃöÃõÃôíª÷ªÃûÃ÷ÃùÜøÚ¤ÃúäéêÔî¨Ãøõ¤ÃüÃýçÑÃþÚÓæÆâÉÄ¡Ä£Ä¤÷áÄ¦Ä¥Ä¢Ä§Ä¨Ä©éâÄ­ÜÔÄ°ï÷ÄªÄ¯Ä®ÝëõöÄ«ñ¢ïÒÄ¬õøñòßèÄ²Ù°íøÄ±öÊÄ³Ä¸ë¤Ä¶ÄµÄ·Ä´Ä¾ØïÄ¿ãåÛéÄÁÜÙîâÄ¼Ä¹Ä»ÄÀÄ½ÄºÄÂäÅìê";
	pys[14] = "£Î£îNnìáÚâÄÃïÕÄÄÄÚÄÇÄÉëÇÄÈñÄÄÆÞàÄËÄÌÜµÄÊÄÎèÍÄÍÝÁØ¾àïÄÐÄÏÄÑà«éªôöëîòïàìÄÒâÎêÙß­Ø«ßÎÄÓíÐîóâ®òÍÛñÄÕÄÔè§ÄÖÄ×Ú«ÄÅÄØÄÙÄÛÄÜàÅÄÝÄáÛèâõÄàÄßîêâ¥ÄÞöòÙ£ÄãÄâì»êÇÄæÄäÄçíþÄåÄéÄêöÓöóð¤ÄíéýÄìÄëØ¥ÄîÛþÄïÄðÄñÜàôÁæÕÄòëåÄóÚíÄùÄôô«Äöà¿Ä÷Äøò¨õæÄõÞÁÄúÄþßÌÅ¡ÄüÄûñ÷ÄýØúÅ¢å¸æ¤Å£âîÅ¤áðÅ¦Å¥Å©Ù¯ßæÅ¨Å§ÅªññÅ«æÛæåÅ¬åóæÀÅ­Å®îÏí¤ô¬Å±Å°Å¯Å²ÙÐÅµßöÞùï»Å³Å´í¥ÞÐí«ÄèÜÑ";
	pys[15] = "£Ï£ïOoàÞÅ¶Ú©Å·Å¹ê±Å¸Å»Å¼ñîÅºâæÅ½à¸ñÂ";
	pys[16] = "£Ð£ðPp±ÙÞÕÅ¿Å¾ÝâèËÅÀÅÃóáÅÁÅÂÅÄÙ½ÅÇÅÅÅÆßßÅÉÅÈÝåÅËÅÊãÝÅÌÅÍõçó´ÅÐãúÅÑÅÎÅÏñÈñáÅÒäèÅÓåÌÅÔó¦ÅÕÅÖÅ×ëãÅÙÅØâÒáóÅÚÅÛÞËÅÜÅÝðåÅÞÅßõ¬ÅãÅàÅâïÂÅáÅæÅåàúì·ÅäàÎö¬ÅçÅèäÔâñÅêÅéÅëàØÅóÜ¡ÅíÅïÅðÅîÅôÅìÅñÅòó²ÅõÅöØ§Åúç¢ÚüÅ÷ÅûÅøîëÅüàèÅùÆ¤èÁÅþÆ£ò·Û¯ÚðÆ¡ÅýÆ¢î¼òçõùÜ±Æ¥âÏØòÛÜÆ¦ß¨ñ±Æ¨äÄæÇî¢Æ§ê¶Æ©Æ¬Æ«êúÆªôææéëÝõäÚÒÆ­ØâÆ¯çÎÆ®óªÆ°éèî©Æ±àÑæÎë­Æ²Æ³Ø¯ÜÖæ°Æ´Æ¶æÉÆµò­Æ·é¯êòæ³Æ¸Æ¹Ù·Æ½ÆÀÆ¾ÆºÆ»ÆÁèÒÆ¿Æ¼öÒîÇÆÂÆÃÆÄÆÅÛ¶ð«ØÏîÞóÍÆÈçêÆÆÆÉÆÇÆÊÞåÙöÆÍê·ÆËÆÌàÛÙéÆÎÆÐÆÏÆÑè±å§ïäÆÓÆÔÆÒÆÖÆÕäßÆ×ë«ïèõëÆÙÆØñâ";
	pys[17] = "£Ñ£ñQq»üöÄÆßÆãÆÞÆâÆàÆÜèçÆÝÝÂÆÚÆÛàÒéÊÆáõèØÁÆîÆëÛßáªÜÎÆäÆæÆçÆíêÈÆêñýÆéä¿ÆèÝ½æëÆïÆåçùç÷ì÷òÓÆìôëòàÞ­÷¢÷èÆòÆóá¨ÆñÜ»Æôè½Æðç²ôìÆøÆýãàÆùÆúÆûÆüÆõÆöÝÝíÓÆ÷í¬ÆþÝÖÇ¡Ç¢÷ÄÇ§ÇªÚäÇ¤Ü·Ç¨ÙÝá©Ç¥Ç£ã¥Ç¦Ç«í©Ç©å¹åºå½Ç°Ý¡îÔò¯Ç®Ç¯Ç¬ÞçóéÇ±Ç­Ç³ëÉã»Ç²Ç´ç×Ç·ÜÍÜçÙ»ÇµÇ¶èýÇ¸ÇºÇ¼ãÞê¨Ç¹õÄÇ»òÞïºïÏïêÇ¿Ç½æÍÇ¾éÉÇÀôÇñßìÁÇÄíÍõÎØäÇÃÇÂÇÁçØÇÇÇÈÜñÇÅÚÛã¾÷³éÔÇÆÇÉã¸ÇÎÚ½ÇÍÇÏÇÌÇËÇÊÇÐÇÑÇÒæªÇÓÇÔêüã«óæïÆÇ×ÇÖÇÕôÀÜËÇÛÇØÇÙÇÝÇÚàºäÚàßÇÜéÕòûï·ÇÞßÄÇßÞìÇàÇâÇáÇãÇäàõÇåòßöëÇéÇçÇèÇæéÑ÷ôÜÜÇêÇëö¥ÇìóäíàóÀõ¼öÆÚöÇîñ·ÜäóÌÇíòËÇðÇñÇïòÇé±öúÇôáìÇóò°ÇöÙ´ÇõåÏÇòêäÛÏåÙôÃòø÷üôÜÇøÇúá«Ú°ÇýÇüìîÇùÇûòÐÇ÷ôð÷ñÛ¾ëÔð¶ÇþÞ¡íáè³Þ¾ë¬ñ³áéó½È¡È¢È£È¥ãÖêïÈ¤ãªÈ¦È«È¨Ú¹ÈªÜõÈ­éúÈ¬îýóÜòéÈ©÷ÜÈ§È®î°ç¹È°È¯È²È±È³È´í¨È¸È·ã×ãÚÈµÈ¶åÒÈ¹ÈºÙ¹ñûÛ§ì¥";
	pys[18] = "£Ò£òRròÅÈ»÷×È¼È½ÜÛÈ¾ìüÈ¿ð¦ÈÂÈÀÈÁÈÃÜéÈÄèãÈÅæ¬ÈÆÈÇÈÈÈËÈÊÈÉÈÌÜóïþÈÐÈÏØðÈÎÈÒÈÑéíÈÍâ¿ñÅÝØÈÓÈÔÈÕÈÖáõÈÞÈ×ÈÙÈÝáÉÈÜÈØéÅÈÛòîÈÚÈßÈáÈàôÛõå÷·ÈâÈçÈãï¨ÈåàéÈæå¦Þ¸ñàÈäò¬ÈêÈéÈèÈëä²äáçÈÝêÈìÈîëÃÈíÞ¨ÈïÜÇèÄò¸ÈñÈðî£ÈòÈóÈôÙ¼Èõóè";
	pys[19] = "£Ó£óSsæÔØ­åæë¶áëØíÈöÈ÷Ø¦ìªëÛÈøÈûÈùàçÈúÈüÈýÈþë§É¡É¢ôÖâÌÉ£É¤ÞúíßòªÉ¥É¦É§çÒëýöþÉ¨É©Ü£ðþÉ«É¬ØÄï¤Éªð£É­É®É±É³É´É²É°É¯ï¡ððôÄöèÉµßþÉ¶ì¦É·ö®É¸É¹É½É¾É¼ÜÏæ©ÉÀîÌÛïÉºô®õÇÉ¿äúëþÉÁÉÂÚ¨ÉÇðÞÉ»ØßÉÈÉÆæóÛ·ÉÉæÓÉÃÉÅÉÄóµ÷­ÉËéäÉÌõüÉÊìØÉÑÛðÉÎÉÍÉÏÉÐç´ÉÓÉÒÉÕÉÔóâô¹òÙÉ×ÉÖÜæÉØÉÙÛ¿ÉÛÉÜÉÚäûÉÝâ¦ÉÞî´ÉàÙÜÉßÉáØÇÉèÉçÉäÉæÉâÉåÉãäÜ÷êÉêÉìÉíÉëÉðÚ·ÉïÉéÉîÉñÉòÉóßÓïòÚÅÉôäÉÉöÉõëÏÉøÉ÷é©ò×ÉýÉúÉùÉüÊ¤óÏÉûÉþÊ¡íòÊ¥êÉÊ¢Ê£áÓÊ¬Ê§Ê¦Ê­Ê«Ê©Ê¨ÊªÝéõ§öõÊ®Ê²Ê¯Ê±Ê¶ÊµÊ°ìÂÊ´Ê³ÛõÝªöåÊ·Ê¸õ¹Ê¹Ê¼Ê»ÊºÊ¿ÊÏÊÀÊËÊÐÊ¾Ê½ÊÂÊÌÊÆÊÓÊÔÊÎÊÒÊÑÊÃÊÇÊÁêÛÊÊóÂéøÊÅîæß±ÚÖÊÍÊÈóßÊÄÊÉó§ÊÕÊÖÊØÊ×ô¼ÊÙÊÜá÷ÊÞÊÛÊÚç·ÊÝÊéì¯Êãç£ÊåÊàæ­Ù¿ÊâÊáÊçÝÄÊèÊæÞóë¨ÊäÊßïøÊëÊêÛÓÊìÊîÊòÊðÊóÊñÊíÊïÊõÊùÊøãðÊöÊ÷ÊúË¡ÊüÊýëòÊûÊþäøË¢à§Ë£Ë¥Ë¤Ë¦Ë§ó°ãÅË©Ë¨äÌË«Ëªæ×Ë¬Ë­Ë®Ë°Ë¯Ë±Ë³Ë´Ë²ËµåùË¸Ë·îåË¶àÊÞ÷ÝôËÔéÃÛÌË¿Ë¾Ë½ßÐË¼ð¸Ë¹çÁòÏØËïÈË»ËºäùËÀËÈËÄËÂãáËÅËÆÙîæ¦ìëãôËÇæáóÓñêËÃËÁâìËÉÚ¡áÂäÁÝ¿áÔËËã¤ËÊñµËÏËÎËÐËÍËÌà²ËÑäÑâÈì¬ïËËÒòôÛÅàÕî¤ËÓÞ´ËÕËÖöÕË×ÙíËßËàä³ËØËÙËÞËÚÚÕà¼ËÜãºËÝËÛÝøö¢óùâ¡ËáËâËãËäÝ´íõî¡å¡ËçËåËæËèËêËîÚÇËìËéËíìÝËëåäËïáøÝ¥â¸ËðËñöÀé¾Ëôæ¶êýèøËóíüàÂôÈËòËõËùßïË÷ËöËøì¨ö±Ý·Êô";
	pys[20] = "£Ô£ôTtåÁî×ËýËûËüõÁîèËúäâËþÌ¡÷£Ì¢ãËåÝé½Ì¤Ì£Ì¥Ì¨Û¢Ì§Ì¦ìÆõÌöØÞ·Ì«Ì­Ì¬ëÄîÑÌ©ÌªÌ®Ì°Ì¯Ì²Ì±Ì³ê¼Ì¸Û°ÌµïÄÌ·Ì¶Ì´ìþÌ¹Ì»îãÌºÌ¾Ì¿Ì½Ì¼ÌÀï¦ôÊïÛâ¼ÌÆÌÃÌÄÌÁÌÂäçè©éÌÌÅÌÇó¥ó«õ±àûÌÈÌÊÙÎñíÌÉÌÌÌËÌÎÌÐÌÍÌÏèº÷Òä¬ÌÓÌÒÌÕßûÌÔÌÑØ»ÌÖÌ×ìýß¯ÌØï«ÌÛÌÚÌÜëøÌÙÌÞÌÝÌàÌßÌäÌáç¾ðÃÌâÌãõ®ÌåÌëÌêÙÃã©ÌéåÑÌèÌæñÓÌçÌìÌíÌïÌñî±ÌðÌîãÙãÃéåÌóÌòÞÝÙ¬ÌôìöÌõÌöóÔö¶òè÷Øöæñ»Ì÷ôÐÌøÌùÝÆÌúÌû÷ÑÌüÍ¡ÌýÌþÍ¢Í¤Í¥ÜðÍ£æÃÝãòÑöªÍ¦èèÍ§Í¨àÌÙÚÍ¬Ù¡Í®ÜíÍ©íÅÍ­Í¯ÍªäüÍ«Í³Í±Í°Í²âúÍ´ÍµÍ·Í¶÷»Í¸Í¹ÍºÍ»Í¼Í½Í¿Ý±Í¾ÍÀõ©ÍÁÍÂîÊÍÃÜ¢ÝËÍÄÍÅÞÒî¶åèÍÆÍÇÍÈÍËìÕÍÉÍÊÍÌêÕÍÍâ½ëàÍÎÙÛØ±ÍÐÍÏÍÑÍÔÙ¢ÍÓÛçãûÍÕíÈÍÒõÉõ¢éÒö¾Í×âÕÍÖÍØèØÍÙóêÜè";
	pys[21] = "£Õ£õUu";
	pys[22] = "£Ö£öVv";
	pys[23] = "£×£÷WwåøÃ¢ÍÛÍÞÍÚÍÝæ´ÍÜÍßØôÍàëðÍááËÍâÍäØàÍåòêÍãÍèæýÜ¹ÍêÍæÍçÍéÍðÍìÍíÍñÍïçºëäÝÒçþÍîîµÍëÍòÍóÍôÍöÍõÍøÍùÍ÷Øèã¯éþ÷ÍÍýÍüÍúÍûÎ£ÍþÙËåÔÚñÝÚÎ¢ìÐÞ±Î¡àíÎªÎ¤Û×Î§àøãíÎ¥ãÇÎ¦ä¶Î¨á¡Î©Î¬áÍÎ«Î°Î±Î²Î³Î­Î¯ì¿çâä¢æ¸Î®â«ðôôºè¸öÛÎÀÎ´Î»Î¶Î·Î¸ê¦Î¾Î½Î¹Î¼â¬ÎµÎ¿ÎºÎÂÎÁÎÄÎÆÎÅÎÃãÓö©ØØÎÇÎÉÎÈÎÊãëè·ÎÌÎËÝîÎÍÞ³ÎÎÙÁÎÐÝ«ÎÑÎÏÎÒÎÖë¿ÎÔá¢ÎÕä×íÒÎÓö»ÎÚÛØÎÛÚùÎØÎ×ÎÝÎÜÎÙÎÞÎãÎâÎáÎßßíÎàä´òÚ÷ùÎåÎçØõÎéÎëåüâÐâèâäåÃÎäÎêÎæêõðÄÎèØ£ÎðÎñÎìÚãè»ÜÌÎïÎóÎòÎîìÉæÄðíæðÎíå»ðÍöÈÞÌì¶âº";
	pys[24] = "£Ø£øXxãßÙïÏ¦ÙâÏ«Î÷ÎüÏ£ÎôÎöÎùñ¶Û­ßñÞÉÏ¢ä»ÎþÏ¤Ï§ì¤äÀÏ©ÎøÝ¾ÎúÏ¬Ï¡ôÑôâô¸ÏªðªÎýÙÒÏ¨ÎõòáÎûæÒÏ¥éØìäôËó£ó¬õµêØ÷ûÏ°Ï¯Ï®êêÏ±ÚôÏ­Ï´çôáãÏ³Ï²ÝßåïÝûìûÏ·Ïµâ¾Ï¸ãÒôªÏ¶ìùßÈÏºÏ¹Ï»ÏÀáòÏ¿èÔÏÁíÌåÚÏ¾è¦Ï½Ï¼÷ïÏÂÏÅÏÄÏÃóÁÏÉÏÈÏËë¯ììôÌÝ²ÏÆõÑõ£ÏÇÏÊåßÏÐÏÒÏÍÏÌÏÑæµÏÏÏÎðïðÂÏÓÙþÏÔÏÕáýò¹óÚõÐÞºìÞÏØá­ÜÈÏÖÏßÏÞÏÜÏÝÏÚÏÛÏ×ÏÙÏçÜ¼ÏàÏãÏáÏæç½ÝÙÏäÏåæøÏâÏêâÔÏéÏèÏíÏìâÃ÷ÏÏëößÏòÏïÏîÏóÏñÏðó­èÉÏ÷ßØèÕæçÏüÏûç¯åÐÏôÏõÏúäìóïÏö÷ÌÏùáÅÏýÐ¡ÏþóãÐ¢Ð¤ÏøÐ§Ð£Ð¦Ð¥Ð©Ð¨ÐªÐ«Ð­Ð°Ð²Ð®ÙÉÐ±Ð³Ð¯ÛÄß¢çÓÐ¬Ð´Ð¹Ðºç¥Ð¶Ð¼ÐµÙôäÍÐ»é¿âÝÐ¸â³Þ¯åâÛÆå¬Ð·õóÐÄÐÃÐ¾ÐÁê¿ÐÀÐ¿ÐÂì§Ð½Ü°öÎØ¶ÐÅÐÆÐËÐÇÐÊÐÉÐÈÐÌÐÐÐÏÐÎÚêÐÍíÊÐÑß©ÐÓÐÕÐÒÐÔÜôã¬Ð×ÐÖÐÙÜºÐÚÐØÐÛÐÜÐÝÐÞßÝâÓÐßð¼õ÷âÊ÷ÛÐàÐãá¶ÐåÐäÐâäåÐçíìñãÐëçïÐéÐêÐèÐæÐìÐíÚ¼èòôÚõ¯ÐñÐòÐðÐôäªÐóÛÃÐ÷ÐøÐïÐöäÓÐõÐáìãÐîÞ£ÐùÐûÚÎÐúÞïÝæêÑìÓÙØÐþðçÐüÐýäöè¯Ñ¡Ñ¢ãùìÅÑ¤Ñ£îçäÖé¸íÛïàÑ¥Ñ¦Ñ¨Ñ§í´õ½Ñ©÷¨ÑªÚÊÑ«Û÷Ñ¬ñ¿â´Þ¹êÖõ¸Ñ°Ñ²Ñ®Ñ±Ñ¯á¾âþä­ä±Ü÷Ñ­öàÑµÑ¶Ñ´Ñ¸áßÑ·Ñ³ÙãÞ¦Üþ";
	pys[25] = "£Ù£ùYyØÖØÎé·áêÑ¾Ñ¹Ñ½ÑºÑ»èâÑ¼ÑÀØóá¬Ñ¿çðÑÁÑÂÑÄíýÑÃÑÆðéÑÅÑÇÑÈåÂÛëæ«í¼ë²ÞëÑÊâûÑÌëÙáÃÑÍÑÉÝÎÑËäÎÛ³æÌÑÓãÆÑÏåûÜ¾ÑÔÑÒÑØÑ×ÑÐÑÎÑÖóÛÑÑÑÕéÜÙðÑÙÙ²ÑÜÙÈØÉÑÚÑÛÛ±çüî»ÑÝ÷Ê÷úÑáÑåÑâÑäÑçêÌÑÞÑéÑèÑßÑæìÍÑãäÙõ¦ÚÝ÷ÐÑàØÍÑëãóÑêÑíÑì÷±ÑïÑòÑôÑîì¾ÑðÑñáàÑóìÈòÕÑöÑøÑõÑ÷âóí¦ÑùÑúçÛØ²ßºÑýÑüÑûØ³Ò¢ëÈÒ¦é÷çòÒ¤Ò¥áæÒ¡Ò£Ñþôí÷¥èÃÒ§ñºÒ¨áÊÒ©ÒªðÎê×Ò«Ò¬Ò­Ò¯Ò®ÞÞîôÒ²Ò±Ò°ÒµÒ¶Ò·Ò³ÚþÒ¹êÊìÇÒ´ÒºÚËÒ¸ØÌÒ»ÒÁÒÂÒ½ÒÀßÞâ¢Ò¿Ò¼Ò¾äôàæ÷ðÒÇÛÝÒÄÒÊÚ±ÒËâùåÆâÂß×ÒÌêÝíôÒÈôýðêÒÆÒÅÒÃÒÉáÚÒÍÒÒÒÑÒÔîÆÒÓÜÓô¯ÒÏÒÐÒÎì½ÒåÒÚØ×ÒäÒÕÒéÒàÒÙÒìß½ÒÛÒÖÒëÒØÙ«á»âøÒ×ÒïÒèæäÞÈÞÄÒßôàéóã¨ÞÚÒæÒêÛüñ´ÒîÒÝÒâÒççËÒÞÒáðùòæÒãìÚï×ØæéìÞ²ôèÒíÒÜñ¯ïîÜ²ÒòÒõÒöä¦ÒðÒñÒôÒóë³î÷à³Ü§Ò÷ÛóáþÒúÒùÒøÛ´â¹ö¯ÛÈÒüÒýßÅÒûò¾Òþñ«Ó¡ÜáØ·Ó¦Ó¢ÝºÓ¤çøàÓÞüÓ§ó¿Ó£è¬ðÐâßÓ¥Ó­ÜãÓ¯Ó«Ó¨Ó©ÓªÝÓéºäÞÝöäëÓ¬ÙøÓ®å­Û«ò£Ó±Ó°ñ¨Ó³Ó²ëôÓ´à¡Ó¶ÓµÓ¸çßÓ¹ÓºÜ­ã¼ÛÕïÞÓ·÷«÷Óà¯ÓÀð®Ó½Ó¾Ù¸ÓÂÓ¿ÓÁÓ¼Ó»ÓÃÓÅÓÇØüßÏÓÄÓÆÓÈÓÉÓÌÓÊÓÍèÖðàÝ¯ÝµÓËòÄÓÎöÏéàòöÓÑÓÐØÕÓÏÝ¬îðë»÷îÓÖÓÒÓ×ÓÓÙ§àóå¶ÓÕòÊÓÔ÷øæúÓØÓÙÓåðöÓÚÓèÓàæ¥ì£ÓÛô§ÓãÓáØ®óÄô¨ÓéáüÚÄâÅÓæÝÇÓçö§áÎÓäÞíëéÓâÓÞÓÜè¤ÓÝêìñ¾ÓßòõÓëØñÓîÓìÓðÓêÙ¶ÓíÓïàôàöâ×ðõñÁö¹ÓñÔ¦Óõí²ÓóåýâÀÓýÓôêÅÓüÓøÔ¡îÚÔ¤ÓòÓûÚÍãÐÓ÷Ô¢ÓùÔ£ÓöðÁÓúìÏÝ÷ÓþØ¹òâÔ¥ìÛðÖå÷ð°Ô©íóÔ§Ô¨óîÔªÔ±Ô°ãäÔ«ë¼Ô­Ô²Ô¬Ô®Ôµö½Ü«Ô´Ô³Ô¯éÚó¢Ô¶Ô·Ô¹ÔºÛùæÂÞòè¥Ô¸Ô»Ô¼ÔÂë¾ÔÀÔ¿ÔÃîáÔÄÔ¾ÔÁÔ½éÐÙßå®ÔÆÔÈç¡Ü¿êÀÔÇÔÅëµÔÊáñÔÉéæÔÐÔËÛ©ã¢ÔÎÔÍã³è¹ÔÏìÙÔÌ";//";
	pys[26] = "£Ú£úZzæùÙ×ÔÑßÆÞÙÔÓÔÒÔÖçÞÔÕÔÔÔ×ÔØáÌÔÙÔÚôØô¢ÔÛêÃÔÜôõÔÝÔÞöÉè¶Ôßê°æàÞÊÔàÔáÔâÔãÔäÔçÔæÔéÔèÔåÔîÔíßðÔìÔëÔïÔêÔòÔñÔóÔðåÅßõàýóÐô·óåØÓØÆê¾ÔôÔõÚÚÔøÔöÔ÷çÕîÀï­êµÔùß¸Õ¦ßîÔûÞêÔü÷þÔúÔýÔþÕ¢Õ¡Õ£íÄÕ§Õ©ßåÕ¤Õ¨ðäòÆÕ¥Õ«ÕªÕ¬Õ­Õ®íÎÕ¯ñ©Õ´Õ±ì¹Õ³Õ²ÚÞÕ°Õ¶Õ¹ÕµÕ¸ÞøÕ·Õ¼Õ½Õ»Õ¾ÕÀÕ¿ÕºÕÅÕÂÛµæÑÕÃÕÄâ¯ÕÁè°ó¯ØëÕÇÕÆÕÉÕÌÕÊÕÈÕÍÕËÕÏáÖá¤ÕÎîÈÕÐÕÑßúÕÒÕÓÕÙÕ×Ú¯ÕÔóÉèþÕÕÕÖÕØòØÕÚÕÛÕÜéüÕÝÚØß¡íÝÕÞÕßÕàô÷ñÞÕâèÏÕãÕáðÑÕêÕëÕìä¥ÕäèåÕæÕèìõÕåÕçÝèé»óðÕéÕïÕíëÓéôî³ÕîçÇð¡ÛÚÕóð²ÕñëÞêâÕòÕðÕùÕ÷Õúá¿ÕõÕøîÛÕöï£óÝÕôáçÕüÕûÕýÖ¤ÚºÖ£Ö¡ÕþÖ¢Ö®Ö§Ø´Ö­Ö¥Ö¨Ö¦ÖªÖ¯Ö«èÙìóëÕÖ¬Ö©Ö´Ö¶Ö±ÖµÛúÖ°Ö²Ö³ôêõÅÞýõÜÖ¹Ö»Ö¼Ö·Ö½ÜÆìíåëÖ¸è×éòÖºíéõ¥ÖÁÖ¾âåõôÖÆàùÖÄÖÎÖËÖÊÛ¤ÖÅèÎÚìÖ¿èäÖÈÖÂêÞéùÖÀÖÌÖÏðºåéÖÇÖÍðëòÎæïÖÉÖÃïôëùö£õÙÖÐÖÒÖÕÖÑÖÓô±ÖÔïñó®Ö×ÖÖÚ£õàÖÙÖÚÖØÖÝÖÛÖßÖÜÖÞÖàæ¨ÖáíØÖâÖãæûÖäÖæç§ÖçëÐÝ§ÖåôüÖèô¦ÖìÙªÖïÛ¥ä¨ÜïÖêÖéÖîÖíîùÖëéÆäóéÍÖñóÃÖòÖðô¶ðñõîÖ÷Öôä¾ÖóÖö÷æÖõØù×¡ÖúèÌ×¢Öü×¤ÖùìÄ×£ðæÖøÖûÖþÖýóçôã×¥×¦×§×¨×©ò§×ªßù×¬×«×­âÍ×±×¯×®×°×³×´×²×·æí×µ×¶×¹×ºã·çÄ×¸ëÆñ¸×»×¼×¿×¾Ù¾×½×ÀäÃ×Æ×Âí½×Çä·ÚÂ×Ã×Ä×Å×Áìúßªåªïí×Ð×Î×È×É×Ëêß×Ê×Íç»ÚÑæÜáÑ×ÌôÒê¢õþôôïÅö·÷Úöö×Ñ×Óæ¢ïöñèóÊè÷×Ï×Òö¤×Ö×Ôí§×Õíö×Ú×Û×Øëê×Ù×××ÜÙÌ×ÝôÕ×ÞæãÚÁÚîÛ¸öí×ß×à×á×âÝÏ×ã×ä×åïß×ç×è×éÙÞ×æõòçÚ×ë×êß¬×ì×î×ïÞ©×í×ð×ñé×÷®ß¤×ò×ó×ô×÷×øÚèâô×õìñëÑßò×ù×ö";
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
	wbs[1] = "£Á£áAa°ª°¬°°°ÅÜØÝÃ°ÐÝò°úÝáÝí÷¹±½Ý©ÜêÝÉ±Í±ÎÞµ±ÞØÒÜÐ²¤±¡²Ë²Ì²Ô²ØÜ³²Ý²ç²èÝÛÝÅÜÉ³¼ÜÝÜûÝ»Üë´ÄÜÊ´ÐÝýÝÍ÷°÷²ß°ÝÌµ´ÝÐÝ¶µÙ¶«ð´¶­ÝúÜ¶Ý­ÜÃÝàÝì·¡·ªÞ¬ÞÀ·¶ØÎ·¼·Æ·Ë·ÒÝ×Ü½ÜÀÜÞÜòÝ³ÝÊ¸ÊÜÕÞ»¸ê¸ï¸ðÝ¢¹¤¹¦¹¥¹§ÞÃ¹®¹¯¹²¹±÷¸¹¶¹½ÝÔðÙØÐºªÝÕÝïÞ¶ºÉºÊÞ¿Þ°Ý¦Þ®ºù»¨»®ÝÈ»Ä»ÆÜîÜöÞ¥»çØå»ò»ñ»óÞ½Ü¸»ùÝðÞªÜÁ¼»Ýç¼ÔÝÑÝó÷µ¼ë¼öÜü½¯½³Ü´Üú½¶½Ú½ä½æ½åÝÀÝ£½ùêî¾¥¾£Ý¼¾¯¾´ÜÚ¾Ï÷¶¾ÕÜì¾ÞÜÄÞ§¾úÝÜ¿±ê¬Ý¨¿Á¿ÖÜÒÞ¢¿àØá¿ï¿ûØÑÝÞÀ³À¶Ý¹ÝõÀÍÀÕÀÙÀòÝñÞ¼ÜÂÀóÝ°Á«ÝüÞ¤ÝþÜßÁâÜ×ÝäÂ«ÂÜÜýÂäÝ¤ò©÷´ÂûÃ¢Ã£Ã§Ã©ÜâÃ¯Ý®ÃÈÝùÞ«ÃÉÞÂÃçðÅÃêÃïÜåÜøÄ¡Ä¢ÜÔÄªÝëÄ³ÜÙÄ¼Ä¹Ä»Ä½ÄºÜµÝÁÄäØ¥ÜàÄõÞÁÅ·Å¹ê±Å¸ÅºÝâÝåÅîÜÅÆ¥ÜÖÆ»Æ¼ØÏÆÎÆÐÆÏÆÑÆßÝÂÆÚÆÛÜÎÆäÝ½ôëÞ­Ü»ÜùÝÝÝÖÜ·Ý¡ÜÍÜçÇ¾Üñ÷³ÇÉÇÌÇÊÇÐÇÑÜËÇÛÇÚÇæéÑÜÜõ¼öÆÚöÜäòËÇøÞ¡Þ¾ÜõÈ§ÈµÜÛÜéÈÇÜóÝØÈÖÈ×ÈÙÈØ÷·ÈãÞ¸ÝêÞ¨ÈïÜÇÈôÈøÉ¢É¯ÜÏÉ»ÉÖÜæÉõÝéÝªÊÀÊ½êÛÝÄÊßÊíÝôË¹Ý¿Þ´ËÕÝøËâÝ´Ý¥ËòÌ¦Þ·ÌÑß¯í«ÌÙÝÆÜðÝãÜíÝ±ÝËÜ¹Ý¸ÝÒÝÚÞ±Î­Î®ÎµÝîÞ³Ý«ÎÔÎ×ÎßÜÌÎôÝ¾ÎõêêÝßÝûÏ»Ý²ÞºÜÈÜ¼ÝÙÏïÏîÏôÐ°Ð¬Þ¯Ð¾Ý·Ð½ÜôÜºÐîÞ£ÝæÑ¥Ñ¦Þ¹Ü÷Þ¦Ñ»ÑÀÑ¿ÑÅåÂÝÎÄèÜ¾Û±Ñà÷±Ò¢Ò©Ò½ÜèÒÃÜÓß®ÒÕÞ²ôèÒðÒñÛ´ÜáÓ¢ÝºÜãÜþÓ«Ó¨Ó©ÓªÝÓÝöÝ¯ÝµÝ¬ÝÇÓóÝ÷ð°Ô·Ü¿ÔÌÔÑÔáÔåØÓÕºÕáÕåÝèÕôÖ¥ÜÆÝ§ÜïÜÑÖø×ÂÝÏÞ©";
	wbs[2] = "£Â£âBb°¢°¯ÚææßÚé±Ýåø³ÂØ©³Ðò¿³Ü³ö³ýÚï´Ïµ¢ñõÚçñô¶¸¶Ó¶é¶ú·ÀÚâ¸½Úë¸ô¹¢¹Âñøº¢º¯ÚòãÄØ½¼Ê½µ½×ÚàæÝÚáÚå¾ÛæÞ¿×ñùÁªÁÉÁÄÁËÁêñöÂ¡Â¤ÂªÂ½ÛÂÃÏÄ°ÚíÄôò¨ñ÷ÅãÚðÆ¸ÚäÛÉÈ¡È¢ÈæÈîÉÂËåËæËîËíËïÌÕôÐÍÓÚñÚóÎÀÚãÚôÏ¶ÏÕÏÞÏÝÚêÑ·ÑôÒ®Ò²ÒõÒþÓçÔºÔÉÕÏÕóÖ°Úìæï×¹×Î×ÓÚîÛ¸×èÚè";
	wbs[3] = "£Ã£ãCc°ÍÛÎÛÍæô²µ²Îæî²æ³Ò³ÛæõñååÊµ¡µËµþ¶Ôí¡æâ¹Ûº§æè»¶¼¦æ÷¼è½¾ñæ¾¢ØÙ¾±åÉ¾Ô¿¥æìÀÝæêæòÂ¿ÂâÂæÂíÃ¬òúó±î¦Ä²öÊÄÑÄÜæéÆ­æëÆïÛÏÇýÈ°åÒÈáÈþë§É£òªÉ§æóÊ¥Ê»Ë«ÛÌæáææÌ¨Û¢ìÆÍ¨ÍÔÍÕæÄæððÍÏ·æøæçÐÜÑ±ÑéÒÓæäð®ÓÂÓÁÓÖÓèÔ¦Ô¤Ô¥ðÖÔÊæàÔéæöÖè×¤æíæã";
	wbs[4] = "£Ä£äDdíÁ°­ðÆ°Ù°î°ï°õ±¯±®±²íÕ±¼±Ãí¾íÜ÷Ôì­÷Þíç²¼íå²Þ²êò²³§ñéíº³½í×³Éô©³ø´¡´º´½´À´Åõ¾´æ´èØÈÞÇ´ï´óí¸ìâíãíÆíÚµâµïµúíÖíÏíÔíâõ»í»¶á¶ò¶øð¹íÀ·¯·Çòãì³ôä·Ü·áí¿Ûº·îíÉÞÎÞÏ¸Ðí·íÑ¸û¹¨ð³¹¼¹ÅØÅ¹Ê¹Ë¹èíÞº»ºÄºñºúðÉð­÷ß»Ç»Òåç»Ûñëí¶ØÞ÷Ùí¢ê©¼ï¼îíäñð½¸íÙ¾¤÷Ý¾Â¾ÇØÊØã¿³¿Ä¿ËØÚ¿äÞÅ¿ó¿ø¿ü÷ÕíÇñìñçÀÚÀåÀúÀ÷ÀøíÂÀùÞÆðÓÞÍ÷àÁ×ÁòÁúíÃÁûÂ¢ñïÂµÂëÛ½ÂõíË÷ÖíæÃæñòÄÎÄÍíÐÄëññí¤ñî°ÒÅÕÞËÅáÅéÅðÅöÅøÆÆÆÝÆæÆõÆöíÓÇ£íÍêüÇØíá÷ÜÈ®È·÷×ÈèÈýíßÉ°ÉÝØÇÉéò×Ê¢Ê¯ÊÙÊùË£Ë¬Ë¶ØËñêËÁËéÌ«Ì¬Ì©Ì¼ñíÌ×÷ØÌüíÅíÈÍëÍòÍþíÒÎìÎùÎøÏ®íÌÏÄÏÃÏÌÏáÏõíÊÐÛ÷ÛÐçí¹íÛÑ¹í¼ÑÐÑÙØÉ÷ÊÑáÑâÑÞÑã÷ÐØÍÒ³ØÌì¥Ó²ÞÌÓÈÓÑÓÐÓÒÓôÔ­Ô¸ÔÅÔÒÔÚê°ØÆíÄÕÉíÝÕèíØ×©í½÷Úñè×××à×ó";
	wbs[5] = "£Å£åEe°®°·°¹°ò°û±ª±ìáÙë÷²±²²²É²Ê²ò³¦ëóëí´àëâµ¨õõëëëËëØ¶Çëñ·¾·Êëè·Î·ôæÚ·þÛ®¸¬¸­¸¹æØê®¸Î¸Ø¸ìëõëÅ¹ÉëûëÒë×ë½ëÜºÑ¼¡¼°ëÎëì½º½ÅëæëÂëÖöÂ¾ôëÌ¿èëÚÀ°Àßì¡Á³ì¢ëÊëÍëáÂöÃ²ëüëßÃÙëïåãÄ¤õöõøëÇÄËØ¾ëîÄÔÄåëåÅ§ÅÖëãÅßÅóÅôÅòÆ¢õùëÝÆêëÉÇ»ÇÒëÔëÀÈéëÃëÛÈùëýáêëþÉÅëÏÊ¤õ¹ÊÜëòË¦Ë´Ì¥ëÄÌÅÌÚëøÌóÍÈëàÍÑÍ×ëðëäÍóë¿ÞÉÏ¥ìÞÏØÏÙÐ²ÐÈÐØõ÷ÐëÐüëÙëçÑüÒ£ôíÒ¨ðÎÒ¸ÒÈÒÜÓ¯ëôÓ·ÓÃëéë¼ÔÂë¾ÔÐÔàëúÕÍëÓëÞÖ«ëÕÖ¬õôëùÖ×ÖâÖðÖúëÆëêëÑ";
	wbs[6] = "£Æ£æFf°£ö°ÛûÛê°Ó°ÔÛà±¢êÚê´ØÃ²ª²©ð¾²º²Å²Ã³¡³¬³¯Ûå³Ã³ÇÛôÜ¯³à³áØ¡´£´çÜ¤´÷µÌêëÛæµØµßÛãÛìÜ¦ñó¶¯Ûí¶¼¶Â¶Ñ¶Õ¶â¶þ·»ö­·Ø·â·ò¸°Ûò¸ÉÛá¸ÏÛÙÜª¹¡¹¸ì°åÜêíì±¹Äî­ØÔ¹ç¹æÛö¹ýñüÚõº«º²º¾ºÂîÁºÕÜ©ºøì²»µ»Üí£»ê»ô»÷»øêå¼ªêªö«¼Î½Ì½Ùò¡½Ø½ø¾®¾³ôñ¾Èôò¾ùÛî¿¯¿°¿²¿¼¿À¿Ç¿ÓÜ¥¿å¿é¿îÛÛ¿÷åÓÀ¤À¬ÀÏÀ×Ü¨æËÛÞö¨Ü®ÛøôóÁØÁãÛ¹ÛâÂ¶ÛäÂñö²ÂôÜ¬ë£Ã¹ÛéÄÏôöÛñÛèÄÞéýÛþÅàö¬Ü¡ÅíÅ÷ÅùÛýÜ±ÛÜÆºÆÂÆÒØÁÛßêÈÆðÇ¬Ç½ö¥íàóÀÇóåÏôÃÇ÷ôðÈ¥È¤È´í¨ÈÀÈÍò¬É¥Ü£ØÄö®ÛïÉÊÛðÉâÉùÊ®ÛõÊ¿Ê¾ó§ËªËÂË÷ËúËþÌ®Ì³Ì¹ÌÁÌËèºÌæÌîöªÍÁÜ¢ÛçÍçÎ¤Û×Î¥Î´ö©ÎÓÛØÎÞÎëÎíìäÏ²Ï¼Ï×ö±ÏöÐ¢Ð­Ü°ÐÒÐèÐæÑ©Û÷ÛëÑÎÑßÒ¼ÛÝÛüÜ²Ü§Ûóö¯Ü­ö§ÓêÓòÔªÔ«Ô¬ö½Ü«Ô¶ÛùÔ½ÔÆÔËè¹ÔÕÔÔÔØôõÔöÕÔÕßô÷ÕæÛÚÕðÖ§Ö±ÛúÖ·Ö¾Öóôã×¨ôô×ß";
	wbs[7] = "£Ç£çGgè¨°½éáåÛ°¾ñúòü÷¡æñöË°à°ß±Â±Æ±Ì±íéë±ûÚû²£åÍ²»²Ð²Ïè²²Üè¡ôùë·´Ìè®çýéãè­´õ´ø´ùçéééµ½ôîçèµåçà¶¹¶º¶¾ó¼¶ÙÛÑ¶ñØ¬çí·©çã·ñôï·ó¸¦¸±Ø¤ØªØ¨¸üçî¹åôççñº÷çú»¥»­»¹»·è«ò³çõ»ÝØ¢çáÛÔ¼¬éê¼ÐçìÛ£¼Õê§¼ß¼íê¯ôøèª½úö¦¾²¾Áè¢çå¿ªçæçûØÝÀ´êãÀµÀÅð¿Á§åÎÀíÀôÀöÛªçöéçÁ½ÁÐÁÒÁÑÁÕÁáÁðççè´çóÂêÂóè£ÃµØÂÃðçäçëÄ©éâÄÒØ«è§ÅªÅÃØ§ÚüÅýéèÆ½çêè±ÆÞçùç÷ÇÙÇàÇíÇòè³ÈÚÈðØ¦ÉªÉºéäÊÂÊâÊøËÀËØËÙËöè©ìýÌìãÃéå÷ÑÍÌÍÍéÒÍßÍáÍãÍæçþÍõçâê¦ÎáÎåÎäðÄØ£è¦ÏÂÏÖÐÌÐÏÐÎÐÍçïè¯Ñ³çðÑÇÑÉÛ³ÑÏçüÑêçòÑþÒ»ÒÄéìçøè¬ÓØÓÚì£ÓÛè¤ÓëÓñè¥éæÔÙè¶ÔâÔæÔðÕµè°ÕäÕéÕûÕýÕþÖ³ÖÁÛ¤ÖÂÖé×¸×Á";
	wbs[8] = "£È£èHhöµ±ë²·²½²Ç²ÍôÓ²ñêèö³îªí÷³Ý³òöº´Æ´ËõºíñµÉíûµã¶¢¶¦¶½¶ÃíïØ­ÛÖò®»¢ØÀíú½Þ¾¦¾Éö´¾ßåáöÄÛÇ¿¨î«î§¿Ïíî¿ôî¥íùî¬ÁäÂ¬ðµÂ­Â±Â²ÂÇÂ÷ÃÐÃßííÃéíðî¨íøÄ¿ÄÀíþÅ°ÅÎÆ¤î¢î©Æµò­ÆÄê·Æçò¯ÇÆë¬È£êïî£ÉÏÊåË¯Ë²î¤íõî¡íüìþö¶Ì÷Í«Í¹ö»Ï¹Ð©íìÐéÑ£íýÑÛíôö¸ØÕÓÝö¹Õ£íÎÕ°Õ¼Õ½ÕêÕöÖ¹Öõ×¿×Àêßõþö·×Ïö¤íö";
	wbs[9] = "£É£éIi°Äå±äºääå¨ãê±õ±ô²¨²´²³²×äî²âä¹ãâäý³¢³£³¨ë©³±³º³¾³Á³Î³Ø³ü´¾äÈ´ãí³µ­å£µ±µ³ÛÊµÎµÓµáµí¶´äÂ¶Éãçãõ¶ý·¨·ºäÇ·Ð·Úå¯ãã¸¡¸¢äææÙ¸Èãïä÷äÆ¸Û¹µ¹ÁãéäÊ¹à¹â¹öº£º­ººº¹å«ãìå©ºÆå°ºÓºÔãüºéºèÙäö×äïºþä°»¦»¬»´ä¡ä½»ÁäñäÒäê»Ôä§»ãä«»ë»ìäã»î¼¤¼³¼¹ä©¼Ãä¤¼âäÕ½§½¥½¦½­ä®½½äÐ½à½ò½þãþ¾Æ¾Ú¾Ùä¸¾õ¿£¿ÊäÛà·À£äµäþÀ½äíÀÄÀËÁÊÀÔãîÀáÀìå¢Á¤äàÁ°å¥äòÁºÁ»ÁÓä£ÁÜãöÁïä¯Á÷öÌãñÂ©ãòäËÂËäõÂºÂÐÂÙãøÂåäðÂúÂþäÝã÷Ã»äØä¼í¯ãèÃÚãæäÏíµÃìãýäéÄ­Ä®ãåÄ×ÄàÄçÄùÅ¢Å¨Å½ÅÉÅÈÅËãúäèÅÝÅæäÔÅìäÄÆ¯ÆÃÆÅå§ÆÖäßÆÙÆãÆâÆáä¿ãàÆûÆüÇ¢Ç±Ç³äÚÇßÇåÇöÇþÈ¸È¾ÈÜå¦Èêä²äáÈóÈ÷É¬É³ôÄöèäúÉÇÉÑÉÍÉÐÉÙäûÉæäÜÉîÉòäÉÉøäÅÊ¡ÊªÊçãðÊþäøäÌãßË®äùãáãôäÁäÑä³ËÝå¡æ¶êýäâÌ­Ì²Ì¶ÌÀÌÃÌÄäçÌÊÌÌÌÎÌÏä¬ÌÓÌÔØ»ÌéÌíÍ¡äüÍ¿ÍÄãûÍÝÍåÍôãíä¶Î«ä¢Î¼ÎÂãëÎÐÎÖä×ÎÛä´öÈÏ«ä»äÀÏªÏ´ÏÑÏæÏ÷ÏûåÐäìÏýÐ¡Ð¤Ð¹ÐºäÍå¬ÐËÐÚäåäªäÓäöãùäÖÑ§í´ä­ä±Ñ´ÑÄÑÍäÎÑØÑÝäÙãóÑóÑúÒ«ÒºäôÒÊÒçä¦ÒùäÞäëå­Ó¾Ó¿ÓÍÓÎÓÙÓåÓæÔ¡ÓþÔ¨ãäÔ´å®ÔèÔóÔüÕ´å¤Õ¿ÕÄÕÇÕÆÕÓÕ×Õãä¥Ö­ÖÎÖÍÖÞä¨äóä¾×¢äÃ×Çä·åª×Í×Ì×Ò×Õ";
	wbs[10] = "£Ê£êJjêÓ°µ°º°ö±©òùêÎó©²õó¸²ý³©êË³¿òÉó¤³×³æòÜòíµ©ØÖê­µçµûò½¶ê¶ô·äò¶òÝòðòóêºê½¸òò´ò¼òÁ¹Æ¹éêÐêÁòå¹ûòäòÀêÏºµòºê»ò«êÂòÂºçºû»Èó¨»ÎêÍ»×»Þó³â·ó¶ò±òÌ¼á¼à¼øòÔò»½ô¾§¾°¿Åòò¿õêÒòñÀ¥òÒê¹À¯ÀÀòëòÛÀïòÃó¹ÁÀÁ¿ÁÙòÈò÷ÂÝó¡ÂìòýÂüòþòÖêÄÃ°ÃÁòµÃËòìó·ÃáóºÃ÷êÔÃøòïêÙòÍêÇÅ¯ó´ó¦ó²ò·òçóªÆØòÓòàòÞòûòßÇçòÇò°òøÇùòÐó½òéòÅÈÕòîÈäò¸É¹óµÉÎòÙÉßÉêÉöêÉÊ¦Ê±ÊÇÊîÊïÊúÊûË§ó°òÏòôåÝê¼ó¥ó«ÌÞÌâòèòÑÍÉêÕÍÜòêÍíÍúè¸ÎÃÎÏòÚÎîÎúòáó£ó¬êØÏºÏ¾åßÏÍÏÔò¹ó­ÏþÐªÐ«ê¿ÐÇÛÃìãêÑêÖÑÁÑÑêÌòÕê×Ò°Ò·êÊÒÏÒ×òæò¾Ó¬Ó°Ó³Ó¼òÄòöòÊØ®ÓÞòõêÅÓöòâó¢Ô»êÀÔÎÔçê¾òÆó¯ÕÑÕÕÖ©òÎÖëÖû×î×ò";
	wbs[11] = "£Ë£ëKkß¹°¡àÄ°¥°¦àÈàÉà»°È°É°ÏßÂõÀàÔ±ÄßÁ±ÉßÙõÏ±ðà£õÛõËß²²¸àê²ÈàÐàá²äõð³ª³°³³àÁ³Ê³Ñ³ÔßêàÍõØß³³ì³ùõéà¨àÜõß´¨´­´®´µõÖßÚõí´ÚßýõãßÕàª´ôß¾à¢ß¶µ¸àâµÅàÖàÇõÚµðµõµøà©õÞ¶£à¤ßËà½¶Ö¶×ßÍ¶ßõâßá¶åßÀ¶õðÊò¦õì·È·Í·Ôßôß»õÃõÆß¼¸À¸Â¸ÁàÃ¸úßçßì¹¾ßÉ¹ÐßÛ¹ó¹òßÃ¹þàËº°àãàÆº¿ºÅºÇºÈàÀºÙºßºåºíºðºôßü»£»©õ×»½»¼ßÔßÜà¹àëß´ßÒßóõÒê«ßâõÕõÊõÂ¼ùõÝõÓ½ÐàÝà®àµàäà±¾×õá¾à¾á¾éàÙàåõê½ÀßÇ¿§¿¦¿Èà¾¿Ð¿Ô¿Úßµ¿Þ¿çßàßÑà­õÍà°À²À®à¥ßëß·àÏà¬Á¨ß¿à¦õÈõÔàÚßÖõñßøõïÁíßÊ¿©Áüà¶ààÂ·ðØÂÀÂîßéÂðÂïßäà×ö¼ß÷ßãÃùßèÄÄà«àìßÎÄÅÄØàÅÄöà¿õæßÌßæßöàÞÅ¶Å»Å¿Å¾ßßõçÅØÅÜÅÞÅçàØàèÆ¡õäàÑÆ·àÛõëàÒõèÆ÷Ç²ÇºõÄõÎàºàßßÄÈÂõåàéàçÉ¤ßþÉ¶õÇÉÚÉëßÓÊ·ÊÈÊÉà§Ë±Ë³àÊËÔßÐË»ËÃà²àÕà¼ËäËôàÂßïõÁÌ¤Ì£õÌÌ¾÷ÒßûÌßÌäÌãÌçÌøÌýàÌÍÂõÉö¾ÍÙÍÛÎ¨Î¶Î¹ÎÇÎËà¸ÎØÎâßíÎüßñÎûßÈÏÅõÑõÐÏìßØÏùÏøÐ¥õóÐÖßÝÐêÐáÐúÑ«Ñ½ÑÆÑÊÑäßºÒ§Ò­Ò¶ßÞàæß×ÒÅß½ÒØà³Ò÷ßÅàÓÛ«Ó´à¡à¯Ó½Ó»ßÏÓõÓ÷Ô±Ô¾ÔÇßÆÔÛßðÔëÔêßõß¸Õ¦ßîÔûßåßúÖ¨õÅõÜÖ»ÖºõÙÖÐÖÒÖÑõàÖäõîÖößù×Ä×Ù×ãõò×ìßò";
	wbs[12] = "£Ì£ìLl÷ö°Õ°ìî¯±ß÷õ³µ³ë÷íê¡ê£÷ò¶Úéî¶÷·£î²î··ø¸¨î¸ÛÁéïî¹¹Ì¹ì¹õ¹úºØºÚºäéõàñ»Ø»ûî¿¼­¼ÓåÈôÂ¼×¼Ý¼Üàî½Î½Ï½çéðÀ§î½ÀÛî¾Á¦éöîºÁ¬Á¾ê¥àòéñéûê¤ÂÔàðÂÖÂÞÂßÃóÄ«Ä¬àïÄÐæÕÅÏÅþî¼ÆÔÆèÇ­ÇµèýÇáàõ÷ôÇô÷ñÈ¦éúî°éíÈíéøÊäÊðÊñË¼ËÄÌïî±î®Í¼ÍÅî¶îµéþàíÎ§Î·Î¸Ï½÷ïÛÄÐùÑ¼î»é÷÷ðéóÒò÷îàóàôàöÔ°Ô²Ô¯à÷ÔÝöÉîÀÔþÕ¶Õ·ÕÖéüÕÞéôî³éòéùÖÃÖá×ªê¢×ï";
	wbs[13] = "£Í£íMm°¶°»°¼á±°Ü±´±À÷Â±áì©ì®÷Æ²Æ²áá¯³çàüå×´Í´ÞáÏµ¤áØµÏ÷¾áÛµäµñá´á¼÷Ç¶Ä¶ä¶ç¶ë·«á¦·²···ç·å·ï·ùá¥¸³êçêà¸Ô¸Õ¸Ú÷Àá¸¹º÷½¹ÇáÄØÛáÆàþº¡÷¿á²»Ë»Ï»ßá§¼¸áÕêéáµ¼û¼úá½÷º½íêáØçåÄì«áÈ¾þ¿­ØÜ÷Áá³áÇ÷¼÷ÅêÜ¿ùáÁá°áÀá×Áë÷ÃáÐÂ¸á£á¹Ã±áÒáºÄÚÅÁÅâàúáªÆéá¨Æñ÷Äá©Ç¶ÇÍêäÇúá«È½áÉÈâÉ½É¾ÉÄÉÞáÓì¯ÊêÙîáÂáÔì¬ÙíËèËêÌ¿êæÌùÌûÍ¬Í®÷»áËÍøØèÎ¡àøá¡áÍá¢Ï¿á­áÅá¶á¾á¬ÑÂáÃÑÒÑëÑìáÊêÝáÚÒÙá»Ó¤ó¿ðÐÓÉÓÊáÎÓìÓøáÌÔßÔòàýÔôÔùÕ¸ÕÊÕËáÖá¤êâá¿Ö¡àùÖÄÖÅÖÜëÐÖüò§×¬´±áÑ";
	wbs[14] = "£Î£îNn°Ãã£öÍ±Øã¹±Ù±ÚæÔ±Ü±ÛèµôÅâíë¢éÞ²À²Ñ²Òâü²ãåîâãåñã®âêâ÷³À³Ù³ßâçã¿ã°³óâðãÀâë´Áã²´äâââòµ¬µ°âáµ¼µ¿µëµîµó¶®¶²¶èåíãµ·¢·Éã­·ßâö¸Ä¸Ò¹Ö¹ßº©º·º¶ºÞºãã±âï»³»Å»Ì»Ð»Ö»Úåì¼º¼É¼Â½ì¾¡¾ªã½¾Ó¾Ö¾ç¾ååðâý¿®âé¿¶åêã¡¿ìã¦ã´À¢ã§ÀÁã¶Á¯ãÁðÒÂ¾ÂÅÂÄÂòÂýÃ¦Ã¼ðÌãÂØ¿ÃñÃõíªÄÕÄáâõÄòâîÅ³âæÅÂãÝâñÅüÆ¨ê¶Æ©ÆÁÇ¡ã¥ã»ãÞÇÄã¾ã¸ÇÓã«ÇéÇüãªÉåÉ÷Ê¬Ê­ÊºÊÑÊÕÊéÊèË¢Ë¾ËÈâìã¤ãºÌëã©ÌèÌñâúÍÀÍÎÍïã¯Î©Î²Î¾Î¿ÎÝâèâäÎòÏ§Ï¬Ï°åïåÚÐ¼Ð¸âàÐÄÐÃÐÊÐÔã¬ñãÐôâþÑ¸ÙãñââûâóâùÒÒÒÑÒÔÒäÒìâøôàã¨ÒîÒíã¼ÓÇÓäÓðÔÃã¢ã³ìÙÞÊÔ÷µÔÕ¹ÕúåëâåÖçÊôã·âô";
	wbs[15] = "£Ï£ïOoôÎ±¬±ºìÔìá±þ²Ó²ÚìÌ³´³ã´¶ôÙ´Ö´âµÆ¶ÏìÑìÀ·³ìÜ·Û·à·éíêíë¸âìÊº¸ºæô×ìÃìÎºý»À»Í»â»ðôÝ½ý¾¬¾«¾¼¾æìß¿·¿»¿¾ÀÃÀÓÀàÁ£ôÏÁ¶Á¸ÁÇÁÏôÔåàìÖÂ¦Â¯ì×ÃºìËÃÔÃ×ôÍÅ´ÅÚÆÉìÁôÜÈ²È¼ÈÛôÛôÖÉ¿ØßìØÉÕìÂÊýË¸ìÝÛ°ÌÇÌþìÕÍéìÐì¿ìÉÏ©ôÑÏ¨ôÌÛÆôÚìÓìÅÑÌÑ×ÑæìÍì¾ìÈÒµÚþìÇìÚìÏìÛôØÔãÔäÔîÔïÕ¨Õ³íéÖòìÄ×Æ×ÑôÕ";
	wbs[16] = "£Ð£ðPp°²°¸°À±¦ñÙ±»ñØñÔñ¹ñÛñÑ±ö²¹²ìñÃìøå·³ÄñÎñÝ³è³õñÒ´©´°åÁìô´Üñ×ñÉå´µ»¶¨ñ¼ñÖ¶îìð¸¤¸£¸»ñË¸î¹¬¹Ñ¹Ó¹Ù¹Úå³º¦º®º±ºÖº×ºêìïå¾»ÂåÕ»í»ö¼Å¼Ä¼ÒñÊñÐåÀå¿½ÑñÆ½ó¾½¾¿ñÕñÀ¾üñäñ½¿ÍñÌ¿Õ¿Ü¿ß¿ã¿í¿úñÜÀÎÀñÁ±ñÍñÏÁÈå¼ÁþÂ»ñÚÂãñÇÃÂìòÚ¢åµÃÜÃÝÃÛå²Ú¤Ä¯ñÄÄþå¸Å©ñÈñáÅÛÆîÆíì÷å¹åºå½ñßÇÏÇÔÇÞÇîñ·ìîÈ¹ìüñÅÈÝÈßñàÈìÈûÈüÉÀÉçÉñÉóÊµìêÊÓÊÒÊØìëËÎËÞåäËüÌ»ñÓìöñ»Í»ÍÊÍàØàÍêÍðÎÑå»ñ¶ìûìùììÏÜÏéÏüÐ´ÐäÐûÑ¨ñ¿ÑçÒ¤ñºñÂÒËÒúÛÈå¶ñ¾ÓîñÁÔ¢Ô£Ô©Û©ÔÖÔ×Õ¬Õ­Õ¯ñÞìõð²Ö®ìóìíÖÏÚ£Öæ×£ñ¸ìú×Ö×Ú×æìñ";
	wbs[17] = "£Ñ£ñQqï¹ïÍï§áíîÙöÑîÓ°÷Ùè°ü±¥±«±·±µï¼áùîéöýïÚïð÷§ïÙ±ý²§âÄîà²¬îßîÐ²ÂâÇïÊâªïïîÎ²öïâ²ù²þöðÛË³®îõîñð·âÁï¥Û»³ú³û´¥â¶îË´¸´Òâ§ïéï±´íµºï½ïëïáµÒØµÛ¡µéîäöôµöîööø¶¤¶§îû¶µî×¶À¶Æ¶Íïæ¶Û¶àîìï°¶öïÉöù¶ùöÜ¶ûåÇ¶üîï·°·¸·¹îÕöÐöîáôïÐö÷·æ·õÙìÙë¸ºöÖöûîÅ¸Æ¸Ö¸äï¯ïÓ¸õöáö¡¹´¹³¹·¹»õýîÜïÀöñ÷¤¹ÝîÂáî¹ä¹êöÙ÷¬öç¹øâ£îþºÝÙêºïºöºüõúâ©ð×îü»«âµÛ¨ïÌÛ¼öéöü»èâÆïÁîØïì¼¢¼±öÝöêïØîò¼Øöäïµ½¤¼üöÞ½Ç½Æ½È½ÂèîöÚ½âîÄ½ð½õâË¾¨â°¾µ¾Ã¾Ä¾Ñï¸¾äîÒ¾âïÔïÃáúõûâ±ïã¾ûï´îøïÇîÖîíîÝï¾ï¬áö¿ñÀ¡ï¿öïïªïçÀÇï¶ï©îîÀÖ÷¦ÀØÀêöâï®Àð÷¯áûöãÁ­Á´â²ÁÍîÉÁÔÁÛÁåöìÁôåÞÁóïÖï³ïÎöÔÂ³ïåÂÁÂÑï²â¤ÂàïÝáïÂø÷©ïÜÃ¨ÃªÃ®Ã­Ã³â­ïÑÃ¾îÍÃÍÃÌâ¨ÃâÃãÃûÃúâÉïÒîâïÕÄÆâÎîóâ®ÄÙîêâ¥öòöÓöóÄñôÁÄ÷ÄøÄüáðÅ¥îÏï»ÅÙáóïÂîëöÒîÇîÞÆÌÙéïäïè÷¢Ç¥Ç¦îÔÇ®Ç¯Ç·ïºïÏïêÇÂïÆÇÕï·ÇäöëöúáìÛ¾ð¶îýáëÈ»ÈÄâ¿áõï¨ÈñÈúâÌöþÉ«ï¤É±É²ï¡É·îÌ÷­õüÉ×â¦Ê¨öõâ»Ê´öåÊÏÊÎîæß±á÷îåïÈËÇâÈïËöÕö¢â¡áøâ¸ËøîèÌ¡÷£öØîÑïÄîãï¦ïÛâ¼ï«ÌàåÑöæï¢ÌúîúÍ­îÊÍÃâ½ÍÒÍâÎ£â«öÛâ¬ØØÎÚÚùÎÙÎðÏ¦Ï£Û­ì¤ÎýçôÏ³â¾Û§áòÏÁÏÇÏÊáýÏÚÏââÃÏóèÉÏúâ³åâÐ·Ð¿öÎÐÉÐ×ÐÙâÊÐâîçïà÷¨â´Ñ®öàØ³ëÈ÷¥îôâ¢Ò¿âÂîÆØ×ÒÝï×ïîî÷áþÒøâ¹ÒûÓ¡Ó­ïÞ÷«ÓÌÓËöÏîðÓãáüâÅâÀÓüîÚíóÔ§Ô³Ô¹Ô¿îáÔÈáñï­Õ¡Õ²â¯îÈÕàÕëÕòÕùÕøîÛï£ÖËö£ÖÓïñÖåÖíîùéÍÖýâÍ×¶ïíïÅöö×Þöíïß×ê÷®";
	wbs[18] = "£Ò£òRr°¤Þß°¨°±Þî°´°¿ÞÖ°Ç°Æ°Î÷É°Ñêþ°×Þã°Ú°Ý°â°á°ç°è±¨±§±°ðÇÞÕ±÷±øÞð²¦²¥²¯²«²¶²Á²Ù²å²ë²ð²ô²ó³­³¶³¸³·ÞÓ³Å÷Î³Ö³â³é´¤Þõ´§ë°´·ß¥´Ý´ê´é´ì´ë´î´òµ£µ§µªµ²ë®µ·µÄµÖµàµæµôµüð¬Þéë±¶¶¶Ü¶Ý¶Þ¶óÞô·´·µ·Õó¾·ö·÷·ú¸§ÞÔß¦¸×¸Þ¸ã¸éë¡¹°¹Ï¹Ò¹ÕÞè¹Þð§¹íÞâº¤º´Þþº³ð©ºóåË»¤»»ß§»ÊåØ»Óß«¼·Þá¼¼Þö¼ð¼ñÞØð¨½Áë¸½Ó½ÒÞ×½Ý½ï½ü¾¾¾ÐÞä¾Ü¾Ý¾è¾ï¾ñ¾ò¾ðÞÜ¿«¿´¿¸¿¹¿½ë´¿Ø¿Ù¿Û¿æÞñ¿ýÀ¦À©À¨À­À¹À¿ÀÌÀÞ÷ËÁÃÁÌÞæÁàÂ£Â§ß£Â°ÂÈÂÓÂÕÞÛÞû÷ÈÞÑÃèÃòÃþÄ¨Ä´ÞàÄÊß­ÄÓÄâÄéÄêÄíÄìÄóÅ¡Å£Å¤Å²ÞùÅÀÅÄÅÅÅÒÅ×ÅêÅõÅúÅûÛ¯ß¨ë­Æ²Æ´Æ¹ð«ÆÈÆÇÞåÆËñýÆøÆþÇ¤ÞçÇÀÇËÇÜÞìÇâÇèÇðÇñÈªÈ±ÈÁÈÅÈÈÈÓÈàÈöÞúÉ¦É¨ÉÃÉÓÉãÊ§Ê°ÊÆÊÃÊÅÊÄÊÖÞÐÊÚÊãÞóË¤Ë©Þ÷ËºËÑËÓËðËùÌ¢Ì§Ì¯Ì½ÌÂÌÍÌáÞÝÌôÍ¦Í±Í¶ÞÒÍÆÍÐÍÏÍØÍÚÍìÍî÷ÍÎÎÎÕÎæÎèóÁë¯ÏÆ÷ÌÐ®Ð¯ß¢Ð¶ÐÀß©Þïõ½Ñºë²ÞëÑÚÑïÑõÑûÒ¡ÞÞÒ´Ò¾ÒÖÞÚÒóë³ÞüÓµÞíÔ®ÞòÔÀëµÞÙÔÜÔíÔñÞêÔúÕªÞøÕÐÕÒòØÕÛÕÜÕÝß¡ÕñÕõÕüØ´Ö´ôêÞýÖ¸ÖÆÖÊÖ¿êÞÖÀðºÖìÛ¥Öô×¥×¦×§×«×²×¾×½ßª×áß¬ß¤";
	wbs[19] = "£Ó£óSsèñ°Ø°å°ð°ñ°ô±­±¾è¼±ê±òéÄ±úõ³²Ä²Ûè¾²éé¶éß³»é´èßèÇõ¨³È³êéË³÷èÆèú³þ´ªé¢é³´»´¼èÈé¨õ¡´×éÁ´åµµèÜé¦¶¡ôú¶¥¶°èü¶Åé²·®èóèÊé¼·Óèû·Ù·ãèõ¸²¸Å¸Ë¸ÌôûéÏ¸ÜéÀéÂ¸ç¸è¸ñ¸ù¹£èÛ¹¹ôþèô¹×èæ¹ñ¹ð¹÷é¤õ°º¨º¼ºËèìºáéÎõ­èë»±»¸èí»ú¼«é®¼Ï¼ÖèÅ¼ìé¥¼÷½·½Íõ´½ÜéÈ½ûèÑèêé§½ÛéÙé·õ¶Û²èöéÓ¿¬èà¿Â¿Ã¿É¿Ý¿á¿òõ«èéÀ¸À·é­ÀÆõ²èáÀÒéÛõªÀâÀãÀîõ·èÀèÝÀõé¬é£ÁÖéÝèÚèùÁñÁøèÐÂ¥èÓéÖÂ´éµé¡è¿í®Ã¶Ã·é¹Ã¸ÃÊÃÎÃÑÃÞèÂõ¤Ä£Ä¾èÍéªÄðÄûèËÅÊõ¬ÅäÅïèÁØâÆ®Æ°Æ±é¯èÒÆÓÆÜèçéÊÆåè½Ç¹éÉÇÁÇÅéÔéÕé±È¨È©È¶èãéÅèÄÉ­É¼ÉÒé©õ§ÊÁÊàÊáÊõÊöÊ÷Ë¨ËÉËÖËÚËáé¾èøËóé½ÌªñûÌ´éÌõ±ÌÒÌÝõ®èèÍ©ÍªÍ°õ©èÞõ¢ÍÖèØÍ÷Î¦Îàè»Î÷ÎöðªéØõµÏ­èÔõ£ÏàÏëÏðèÕÐ£Ð¨ÐµéÇé¿ÐÑÐÓÐàèòõ¯Ðïé¸õ¸èâéÜõ¦ÑîÑùèÃÒªÒ¬ôýÒÎÒáÓ£éºèÖÓÏÓÜéÚéÐÔÍé«ÔýÕ¤Õ¥Õ»ÕÁÕÈèþèÏèåÕçé»ÕíÖ¦èÙÖ²è×õ¥èÎèäôüÖêéÆèÌÖù×®×µ×Ãè÷×Ø×íé××õ";
	wbs[20] = "£Ô£ôTt°«á®°Â°Ê°Þ°ã°æô²±¸±¹±¿±Ç±Ëïõ±Êô°±ÒóÙóëó÷óÖ±ü²°²­ô¤²¾²Õô½²ß³¤áä³¹³Æ³Ë³Í³Ì³Óó×óøáÜô¾³î³í³ï³ô´¦ô­´¬´Ñ´¹´ÇáÞ´ØÙà´Ûë¥ïóóÎ´ð´ýóìµ¾µÃµÂô£µÈÙáµÐµÑµÚô¡ëº¶ª¶¬óûë¹¶¿óÆ¶Ìóý¶ã¶æ¶ì·¦·¤·¬·­·±áÝô³óõ·êïû·û¸´ð¥¸Í¸ÑóàØº¸Ý¸å¸æÛ¬ô´¸÷¹ªóôóÑ¹¿êôðÀêö¹Îð»¹Ô¹Üóþ÷ýº½ºÌºÍºÜºâóóááºõóË»²áåóò»É»Õ»à»ýóÇïúê÷»þ»üóÅ¼®¼¾ð¢óÕ¼Ú¼ãêùóÈ¼ò½¢ë¦¼ý½Ãáè½Õ½Ö½î¾¶¾Ì¾Øé°êøóÞêû¿¿¿ÆïýóíóØ¿ê¿ðóñáâô¥ÀºïüÀæÀçÀèÀé÷óÀûóÒóöÁýÂ¨ôµóüëªïùÂÉÂÒÂáöÃÃ«êóÃ´Ã¿ô¿ô»ÃØÃëóúÃô÷ªï÷ë¤ÄµÄÁÄÂð¤ô«ô¬óáÅÇÅÆÅÌÅÍåÌÅñÆ¬êúÆªØ¯êòÛ¶óÍë¶ë«ÆòÆùí¬Ç§Ç¨í©Ç©óéÇÇóæóäóÌÇï÷üÇûáéóÜð¦ÈÉïþÈëóèð£ì¦É¸ô®ÉÔóâô¹ÉàÉäÉíïòÉýÉúÉüóÏÉûíòÊ£Ê¸ÊÊóÂÊÍóßô¼ïøÊòË°Ë½óÓËÒóùËãËëËñÌºÌÉÌØÌðÌòÌõóÔÍ¢Í§Í²Í¸ÍºÍ½ÍÇØ±óêÍùåÔÎ¢Î¯ôºÎºÎÈÎÒÎçåÃêõÎñÎïÏ¢ÎþÏ¤Ï¡ô¸áãÏµÏÈÏÏÏÎóÚÏãÏäÏòóïóãÐ¦Ø¶ÐÆÐÐÐãÐìÑ¡ÑªÑ¬Ñ­áßÑÃÑÓóÛÑÜÑíáàØ²áæåÆÒÆô¯ÒÛØæØ·ë»ÓÔóÄÓíÓùØ¹óîÔÁô¢êÃÔÞÔìåÅóÐô·óåÔõ÷þÕ§Õ±óÉóðð¡Õ÷óÝáçÖªâºÖÈÖÇÖÉïôô±ó®ÖÖÖØÖÛô¦ÖñóÃô¶Öþóç×­ïöóÊ×Ô×â×ë";
	wbs[21] = "£Õ£õUu°©°Ìñ£ñ­°ë°ê±±Úý±³±Å±Õ±Ö±Ô±×±æ±ç±èñ¦±ï±îõ¿±ñÙû±ù²¢²¡²¿ê³²îðû²ú²ûÙæãÑ´³³Õà´ñ¡³åñ¬´¯´Ã´É´ÈðË´Î´Õ´áðî´ñµ¥µ¦ð÷ðãµÁµÀôÆµÜµÛµÝñ²µìñ°µòðÛ¶³¶·¶»¶Ë¶ÒãÕ·§ðò·è·ë¸Çðá¸Óí°¸á¸í¸ó¸þðó¹Ø¹ëÙòÙåºÒãØºÛãÈðúÙü»¾»¿ñ¥ãÔ¼²ñ¤¼½ðèðý¼ä¼æ¼åðÏ¼õ¼ôôå½ª½«½¬½±½°½´½»½¼ðÜ½ßôÉ½ê¾»¾·¾º¾¹¾¸ãÎ¾Î¾ÒîÃ¾íèð¾ì¾ö¿¢ãÛãÊðâ¿öÙçãÍÀ«ðøÀ±ñ®À¼À»ãÏðìÀäÁ¢ðÝðßÁ¡Á¹ÁÆÙýÁÝÁèÁçÁöÁùñªðüãÌñ§ÃÀÃÅÃÆãÉÃöñ¢ÄÖðÚÄæÄýÅ±ÅÐÅÑÅÔðåÆ£Æ¦ñ±Æ³Æ¿ÆÊÆÕÆàÇ°Ç¸Ç¼ôÇæªÇ×ÇõåÙñ³ãÖÈ­È¬È¯È³ã×ãÚÈòìªðþððÉÁðÞÉÆÛ·ÉÌÉØÊ×ÊÞÊÝãÅË·éÃÚ¡ñµËÍËÜËìôÈãËÌ±ÌµôÊÌÛÌÜðÃÌêãÙÍ¯Í´Í·ãÇðôÎÁÎÅãÓÎÊðíôËãÒÏÐðïðÂÙþÏÛÏèößÐ§ÐÁÐÂì§ÐßðçÑ¢Ñ¾ðéÑËãÆÑÖÑÕÙðÑåÑòÑñÑøÑ÷í¦Ò±ðêÒßÒæñ´ÒâðùÒãñ¯Òôñ«ñ¨Ó¸ðàéàðöðõãÐÔÄÔÏÔøêµÕ¢ðäñ©Õ¾ÕÂÛµÕÃÕÎÕîÖ£Ö¢ÖÌðëðñðæ×±×°ãÜ×³×´×¼×Å×È×É×Ë×ÊæÜôÒí§×Ü×ð×ñ";
	wbs[22] = "£Ö£öVvæÈæÁåþæ¾æ»°þæ±æ¿æ½æÏ³²æÊçÝæ§´þµ¶µÕæ·¶Ê¶ðæ¹·Áåú÷÷¸¾ê¸ôÞæÅ¹Ãæ£ºÃ»Ù»é¼§¼´¼µåæ¼Ë¼Èôß¼Þ¼é½¨æ¯½¿½Ëæ¼Ëý½ãæ¡æºð¯¾Å¾Ê¾Ë¾ê¾ý¿¤¿Ñ¿ÒØ¸ååÀÑæÐæ²Á¥ÁéÂ¼åÖÂèæÖÃ½ÃÃÃÄÃäÃîæÆÄ·ÄÇÄÈÄÌÄÛÄÝÄïí±æ¤Å«æÛæåÅ¬åóæÀÅ­Å®æÇæÎæ°æÉæ³æÍÈºæ¬ÈÌÈÐÈÑÈçÉ©æ©æÓÛ¿ÉÛÉïÉôÊ¼æ­ÊóË¡æ×åùæ¦ÛÅËààûÌöæÃÍËÍÞæ´ÍèÍñæ¸÷ùåüæÒ÷ûÏ±ôªæµÏÓÐÕÐñÐöÐõÑ°Ñ²æ«æÌåû÷úÑýÒ¦ÒÌÒöÒüçß÷øæ¥ô§ô¨Óéí²åýæÂÔÓçÞæÑÕÙæ¨Öãæ¢";
	wbs[23] = "£×£÷Ww°³°Á°Ë°Ö°Û°ä°é°øìÒ±£±¤±¶ÛÐÙÂ±ãÙÏ²®²ÖØ÷²à²íÙ­Øö³¥³«³ÞÙÑ³ðÙ±öÅ´¢´«´´´Ó´Ô´Ùìà´ß´ö´úá·´û´ü÷ìÙÙµ«µ¹µÇµÊµÍµèµùØê¶±¶Î¶íÙ¦·¥ÛÒ·Â·Ö·Ý·ÞÙÇÙº·ð·ü·ý¸«¸©¸ª¸¸¸¶¸·¸µÙ¤¸ë¸ö¹«¹©Øþ¹À¹ÈÙÄ¹ï¹ôº¬ò¥ºÏºÎºÐò¢ºîºò»ª»¯»á»ï»õÙ¥¼¯¼¿ÙÊ¼À¼Ñ¼Û¼Ù¼ó¼þ½£êð½¡ÙÔ½©½¹ÙÕðÔÙ®½Ä½é½è½ñ½öÙÓÙÖ¾ãÙÆ¾ëöÁ¾ó¿¡ØûíèÙ©ØøÙÅÙ¨¿ëÛ¦¿þÀÐØìÀÜÙµÀýÀþÙ³ÀüÁ©Á²ÁÅÁÚÁÞÁæê²ôáÁìÁîÙÍÂÂÂØÂ×ÙÀÃÇÃüÙ°ØïÄÃÄßÙ£ÄãÄîÄúØúÙ¯ÙÐÅ¼Ù½ÅåÅèØòÆ§Æ«Æ¶Ù·Æ¾ÆÍÆóÇªÙÝÙ»ê¨ØäÇÈÇÎÇÖôÀÇÝÇãÙ´È«ÈËØéÈÊØðÈÎí¥ÈÔÈåÙ¼ØíÉ¡É®ÉµÉËî´ÙÜÉáÉìÊ²Ê³Ê¹ÊËÊÌÊÛÙ¿Êæë¨ËÅËÆÙ¹ËËËÊËÌË×ËÛöÀËûÌ°ÌÈÙÎÌåÙÃÙ¬Í£ÙÚÙ¡Ù×ÍµÍ¾ÙÛÙ¢ØôÙËÎ°Î±Î»è·ÎÌÎÍÙÁØõÎéÎêÙâôâÙÒì¨ÏÀÏÉÏñÙÉÐ±ÐÅÐÝÐÞð¼ÐðÙØØóÙ²ÙÈÑðÑöÒ¯ÒÁÒÀÒÇÒÐÒÚØîØýÙ«Ó¶Ù¸ÓÅØüÓÆÓÓÙ§ÓàÓáÓâêìÓßØñÙ¶ÓûðÁÓúÙßÕ®ØëÕÌÕìÖ¶ÖµÖÙÖÚÙªØù×¡ö¿×·Ù¾×ÐÙÌÙÞ×ô×÷×ø×ö";
	wbs[24] = "£Ø£øXx°í°óð±±ÁØ°±È±Ï±Ñ±Ðåö±àçÂçÍ²ø³Ú³ñç©´¿´Âçªµ¯µÞ¶Ðç¶·Äç³·Ñ·×·ì¸¥ç¦ç¨åõ¸¿ç¤¸ÙçÉæü¸øç®¹­çÃ¹áçµç¬ºëºì»¡çÙ»º»Ã»æçÀ¼¨¼©çÜ¼¶¼Í¼Ì¼êçÌçÖ½®ç­êñ½Ê½É½Ô½áçÆ¾­åò¾À¾î¾øç¼ç«æþÀÂçÐçÊó»Á·çÔç±ç¸ÂÆÂÌÂÚÂççÏÃÖåôôéÃàÃåç¿çÅçÑÄ¸ÄÉÅ¦àÎç¢çÎç²ç×Ç¿çØÇêç¹ÈÆÈÒÈÞçÈÈõçÒÉ´ÉÉç´ÉÜÉðÉþç·ç£æùË¿ð¸çÁËçËõÌÐç°ç¾Í³åèæýçºÎ¬Î³ÎÆÎãÏ¸ÏËÏÒÏßÏçç½÷Ïç¯çÓç¥ÐåÐ÷ÐøÑ¤çÛÒÉÒÍÒïçËÒÞÒýÓ§ò£Ó±ÓÄÓ×æúå÷ÔµÔ¼ç¡çÕÕÀÕÅçÇÖ¯Ö¼Ö½åéÖÕÖàæûç§×ºçÄç»×Û×Ý×éçÚ";
	wbs[25] = "£Ù£ùYy°§âÖÚÏâÚ÷é°ù°ý±ÓâØ±â±å±ä±é±óÙ÷Ùñ²ï²÷âÜÚÆ²üêÆÚÈÚß³Ï³ä´²ðÈ´Êµ®ÚÔÚ®µ×ÚÐµêµ÷µý¶©¶Á¶Èí­¶Ø¶ïÚÌ·½Úú·¿·Ã·Åìé·Ì·Ï·í¸®¸¯¸¼¸Ã¸ß¸àÚ¾¸ýâÙÚ¸Ú¬¹ÍÚ´¹ãâÑ¹î¹ù¹üº¥ñþºÁºÀÚ­ÛÀºàÚ§»§ìæìè»°ëÁ»ÑÚ¶÷â»ä»åÚ»¼¥¼£ì´÷ä¼Æ¼Ç¼Á¼çÚÙÚÉ½²Ú¦Úµ½ë½÷âÛ¾©ìºìç¾ÍðÕÚª¾÷ÚÜ÷å¿µ¿ºò¤¿Ì¿Î¿âÚ²Ú¿Ú÷ÀªÀ¾ìµÀÉÀÈÀÊÙúÚ³ÀëìåÁ®æ®ÁµÁ¼ÁÁÁÂÁÎ÷ëâÞÁßÁõì¼Â®Â¹ÂÃëöÂÊÂÏÂÍÂÎèïð½ÙõöÇÂÛÙùÂéÂùÃ¡ÚøÃ¤ì¸ÙóÃ¥ÃÕÃÓ÷ã÷çÃÒÚ×ÃíÃýÚÓ÷áÄ¦Ä¥Ä§Ä±Ä¶Ú«ì»ÅµÚ©ÅÓâÒì·ÅëâÏôæÚÒÆÀÙöÆ×ÆëÆì÷èÆôôìÆýÆúÇ«Ç´ÇÃÚÛÚ½ÇëÇìÚ°Ú¹È¿ÈÃÈÏÚ¨ÉÈÉè÷êÚ·ÚÅÊ«Ê©Ê¶ÊÐÊÔÚÖÊëÛÓÊìÊüË¥Ë­ËµËÏËÐËßÚÕÚÇÌ¸Ì·ÌÆÌÖÍ¤Í¥ÙïâÕÍäÍöÍýÍüÍûÎªÚÃÎ½ÎÄÎÉÎÜâÐÎóÚÀÏ¯ÏåÏêâÔÏíÐ³ÙôÐ»âÝâÓÐíÚ¼ÐòÐóÚÎÐþÐýÚÊÑ¯ÑµÑ¶ÑÈÚ¥ÑÔÑèÚÝÒ¥Ò¹ÚËÒÂÚ±ì½ÒåÒéÒàÒëÒèÞÈÞÄÒêÓ¦âßÓ¥ÙøÓ®Ó¹ÓºÛÕ÷ÓÓÀÓÕì¶ÚÄÓïâ×ÓýÚÍÚÚÕ©Õ«ì¹ÚÞÚ¯ÕØÕÚÚØÕâðÑÕïÖ¤ÚºÖÔÖÝÖßÖïÖîØ¼Ö÷÷æ×¯×»ÚÂÚÑÚÁ×ä×å×ç×ù";
	wbs[26] = "£Ú£úZz";
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
// 	result = S; // ³õÊ¼»¯½á¹û×Ö·û´®
// 	for(i = 0; i < (int)S.length(); i++) // ÒÀ´Î¶Ô×Ö·û´®ÖÐ¸÷×Ö·û½øÐÐ²Ù×÷
// 	{
// 		result[i] = S[i] ^ (char)(Key >> 8); // ½«ÃÜÔ¿ÒÆÎ»ºóÓë×Ö·ûÒì»ò
// 		Key = ((BYTE)result[i] + Key) * STRENCDEC_C1 + STRENCDEC_C2; // ²úÉúÏÂÒ»¸öÃÜÔ¿
// 	}
// 	S = result; // ±£´æ½á¹û
// 	result.clear(); // Çå³ý½á¹û
// 	for(i = 0; i < (int)S.length(); i++) // ¶Ô¼ÓÃÜ½á¹û½øÐÐ×ª»»
// 	{
// 		j = (BYTE)S[i]; // ÌáÈ¡×Ö·û
// 		// ½«×Ö·û×ª»»ÎªÁ½¸ö×ÖÄ¸±£´æ
// 		str = "12"; // ÉèÖÃstr³¤¶ÈÎª2
// 		str[0] = 65 + j / 26;//ÕâÀï½«65¸Ä´óµãµÄÊýÀýÈç256£¬ÃÜÎÄ¾Í»á±äÂÒÂë£¬Ð§¹û¸üºÃ£¬ÏàÓ¦µÄ£¬½âÃÜ´¦Òª¸ÄÎªÏàÍ¬µÄÊý
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
// 	result.clear(); // Çå³ý½á¹û
// 	for(i = 0; i < (int)S.length() / 2; i++) // ½«×Ö·û´®Á½¸ö×ÖÄ¸Ò»×é½øÐÐ´¦Àí
// 	{
// 		j = ((BYTE)S[2 * i] - 65) * 26;//ÏàÓ¦µÄ£¬½âÃÜ´¦Òª¸ÄÎªÏàÍ¬µÄÊý
// 
// 		j += (BYTE)S[2 * i + 1] - 65;
// 		str = "1"; // ÉèÖÃstr³¤¶ÈÎª1
// 		str[0] = j;
// 		result += str; // ×·¼Ó×Ö·û£¬»¹Ô­×Ö·û´®
// 	}
// 	S = result; // ±£´æÖÐ¼ä½á¹û
// 	for(i = 0; i < (int)S.length(); i++) // ÒÀ´Î¶Ô×Ö·û´®ÖÐ¸÷×Ö·û½øÐÐ²Ù×÷
// 	{
// 		result[i] = (BYTE)S[i] ^ (char)(Key >> 8); // ½«ÃÜÔ¿ÒÆÎ»ºóÓë×Ö·ûÒì»ò
// 		Key = ((BYTE)S[i] + Key) * STRENCDEC_C1 + STRENCDEC_C2; // ²úÉúÏÂÒ»¸öÃÜÔ¿
// 	}
 	return result;
}