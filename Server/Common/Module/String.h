#ifndef _String_Defined_
#define _String_Defined_
#include <iostream>
#include <string.h>
#include <vector>
#include <stdarg.h>

#ifdef WIN32
#include <Windows.h>
#endif

using namespace std;

class  String
{
public:

	/************************************************************************/
	/* 字符串处理                                                           */
	/************************************************************************/	

	//从char指针拷贝一份来返回string，注意这里是值传递
	static string StrConvert(char* srcPchar);
	//获取string的char指针，注意这里是地址传递
	static char* StrConvert(string &srcStr);

	//获取字符串长度
	static int StrLen(string str);
	static int StrLen(char* pchar);

	//截取字符串
	static string StrSub(string str, int index);
	static string StrSub(char* pchar, int index);
	static string StrSub(string str, int index, int count);
	static string StrSub(char* pchar, int index, int count);
	static string StrLeft(string str, int count);
	static string StrLeft(char* pchar, int count);
	static string StrRight(string str, int count);
	static string StrRight(char* pchar, int count);
	static string StrLeftL(string str, int leftLeaveCount);//取字符串左边，抛弃右边
	static string StrLeftL(char* pchar, int leftLeaveCount);
	static string StrRightL(string str, int rightLeaveCount);//取字符串右边，抛弃左边
	static string StrRightL(char* pchar, int rightLeaveCount);

	//获取字符串位置
	static int StrPos(string str1, string str2, int index = 0);
	static int StrPos(char* pchar1, string str2, int index = 0);
	static int StrPos(char* pchar1, char* pchar2, int index = 0);
	static int StrPos(string str1, char* pchar2, int index = 0);
        
	//从字符串strs中取从startp位置开始遇到的最后一个subs所在的位置，该函数其实是取subs从右边开始的位置。startp表示strs中左边有效的字符位置，结果位置一定小于等于startp
	static int StrPosDown(string strs, string subs, int startp);
	static int StrPosDown(char* pchar, char* subPchar, int startp);
	static int StrPosDown(string strs, string subs);
	static int StrPosDown(char* pchar, char* subPchar);

	//重复字符串
	static string StrRepeat(string str, int repeatCount);
	static string StrRepeat(char* pchar, int repeatCount);

	//字符串大小写转换
	static string StrUpper(char* pchar);
	static string StrUpper(string str);
	static string StrLower(char* pchar);
	static string StrLower(string str);

	//字符串截取空格
	static string StrTrim(string str);
	static string StrTrim(char* pchar);
	static string StrLTrim(string str);
	static string StrLTrim(char* pchar);
	static string StrRTrim(string str);
	static string StrRTrim(char* pchar);

	//字符串比较，如果前面一个比后面一个大则返回1，相等返回0，否则返回-1
	static int StrComp(string str1, string str2);
	static int StrComp(char* pchar1, string str2);
	static int StrComp(char* pchar1, char* pchar2);
	static int StrComp(string str1, char* pchar2);

	//字符串替换
	static string StrReplace(string str, int index, int count, string dstStr);
	static string StrReplace(string str, int index, int count, char* dstPchar);
	static string StrReplace(char* pchar, int index, int count, char* dstPchar);
	static string StrReplace(char* pchar, int index, int count, string dstStr);
	static string StrReplaceAll(string str, string searchFor, string replaceAs, int index = 0);
	static string StrReplaceAll(char* pchar, char* searchFor, char* replaceAs, int index = 0);

	//从字符串strs中以dpts为分隔符读取第nos个分割串。
	static string StrDepart(string strs, string dpts, int nos);//strs的格式为：<str>[<dpts><str>]，strs中第一个分割串的nos为0
	static string StrDepart(string strs, int nos);//strs的格式为：<str>[;<str>]，strs中第一个分割串的nos为0
	static string StrDepart(char* pchar, char* dptPchar, int nos);
	static string StrDepart(char* pchar, int nos);

	//从字符串strs中取出标识为ids的值，其中dpts为分隔符，equs为等值符，字符串strs的格式为：<name><equs><value>[<dpts><name><equs><value>]
	static string GetParmStr(string strs, string dpts, string equs, string ids);
	//从字符串strs中取出标识为ids的值，其中dpts为分隔符，等值符为"="，字符串strs的格式为：<name>=<value>[<dpts><name>=<value>]
	static string GetParmStr(string strs, string dpts, string ids);
	//从字符串strs中取出标识为ids的值，其中分隔符为";"，等值符为"="，字符串strs的格式为：<name>=<value>[;<name>=<value>]
	static string GetParmStr(string strs, string ids);
	//将字符串srs中标识为ids的值设置为vals，其中dpts为分隔符，equs为等值符，字符串strs的格式为：<name><equs><value>[<dpts><name><equs><value>]
	static string SetParmStr(string strs, string dpts, string equs, string ids, string vals);
	//将字符串srs中标识为ids的值设置为vals，其中dpts为分隔符，等值符为"="，字符串strs的格式为：<name>=<value>[<dpts><name>=<value>]
	static string SetParmStr(string strs, string dpts, string ids, string vals);
	//将字符串srs中标识为ids的值设置为vals，其中分隔符为";"，等值符为"="，字符串strs的格式为：<name>=<value>[;<name>=<value>]
	static string SetParmStr(string strs, string ids, string vals);
	//将字符串srs中标识为ids的值删除，其中dpts为分隔符，equs为等值符，字符串strs的格式为：<name><equs><value>[<dpts><name><equs><value>]
	static string DelParmStr(string strs, string dpts, string equs, string ids);
	//将字符串srs中标识为ids的值删除，其中dpts为分隔符，等值符为"="，字符串strs的格式为：<name>=<value>[<dpts><name>=<value>]
	static string DelParmStr(string strs, string dpts, string ids);
	//将字符串srs中标识为ids的值删除，其中分隔符为";"，等值符为"="，字符串strs的格式为：<name>=<value>[;<name>=<value>]
	static string DelParmStr(string strs, string ids);

	//从数值转换为字符串
	static string StrConvertFromLong(long long ival);
	static string StrConvertFromInt(int ival);
	static string StrConvertFromShort(short ival);
	static string StrConvertFromByte(char ival);
	static string StrConvertFromDouble(double dval, int dec);
	static string StrConvertFromFloat(float fval, int dec);
	//从字符串转换为数值
	static long long StrConvertToLong(string str);
	static long long StrConvertToLong(char* pchar);
	static int StrConvertToInt(string str);
	static int StrConvertToInt(char* pchar);
	static short StrConvertToShort(string str);
	static short StrConvertToShort(char* pchar);
	static unsigned char StrConvertToByte(string str);
	static unsigned char StrConvertToByte(char* pchar);
	static double StrConvertToDouble(string str);
	static double StrConvertToDouble(char* pchar);
	static float StrConvertToFloat(string str);
	static float StrConvertToFloat(char* pchar);

	//为字符串加单引号
	static string StrExpr(string strs);
	//根据指定分隔符将字符串拆分成一个数组
	static vector<string> StrSplite(string strs, string dpts, bool noEmptyStr = false);
	//判断是否是被分分隔的最小字符串。如果里面包含空格、回车、TAB等分隔符，则返回false
	static bool StrIsNoSplitted(string sStr);
	//获取两个被分隔的字符串的的实际内容和起始位置
	static string StrGetSplittedPos(string sSrc, string sFirst, string sSecond, int &iPos);
	//将数值代码字符串codestr前面添加"0"使其达到codelen个字符长度后输出，如果codestr的长度大于等于codelen则直接输出codestr，restrictLen要求是否截取指定的长度
    static string StrFillCode(string codestr, int codelen, bool restrictLen);
    static string StrFillCode(long long codelong, int codelen, bool restrictLen);
	//在字符串sText的前或后补字符cPadChar。bUntilWidth表示补字符的长度iWidth是要达到的长度，还是要补的长度；bPadTail表示是否将字符补到sText的后面
	static string StrPadChar(string sText, char cPadChar, int iWidth, bool bUntilWidth, bool bPadTail);
	//在字符串sText的前补空格。bUntilWidth表示补字符的长度iWidth是要达到的长度，还是要补的长度；bPadTail表示是否将字符补到sText的后面
	static string StrPadSpace(string sText, int iWidth, bool bUntilWidth, bool bPadTail);
	//将汉字字符串hzs转化为拼音首拼，如果中间有非汉字则直接输出
	static string GetHzPY(string hzs);
	//将汉字字符串hzs转化为五笔首字母，如果中间有非汉字则直接输出
	static string GetHzWB(string hzs);

	//字符串格式化
	static string StrFormat(const char *fmt, ...);
	static string StrFormat(const char *fmt, va_list argptr);

	//MB UTF8 转换为 Unicode
	static wstring StrConvertUTF8ToUnicode(const string& src);
	//Unicode 转换为 MB UTF8
	static string StrConvertUnicodeToUTF8(const wstring& src);
	//MB  转换为 Unicode
	static wstring StrConvertMBToUnicode(const string& src);
	//Unicode 转换为 MB
	static string StrConvertUnicodeToMB(const wstring& src);
	//UTF8 转换为 GBK
	static string StrConvertUtf8ToGbk(char* utf8);
	static string StrConvertUtf8ToGbk(string utf8);
	//GBK 转换为 UTF8
	static string StrConvertGbkToUtf8(char* gb2312);
	static string StrConvertGbkToUtf8(string gb2312);

	//获取字符串的HashCode
	static int StrGetHashCode(string s);
	static int StrGetHashCode(char* pchar);

	//加密函数
	static string StrEncrypt(string S, long long Key);
	//解密函数
	static string StrDecrypt(string S, long long Key);

};

#endif