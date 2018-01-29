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
	/* �ַ�������                                                           */
	/************************************************************************/	

	//��charָ�뿽��һ��������string��ע��������ֵ����
	static string StrConvert(char* srcPchar);
	//��ȡstring��charָ�룬ע�������ǵ�ַ����
	static char* StrConvert(string &srcStr);

	//��ȡ�ַ�������
	static int StrLen(string str);
	static int StrLen(char* pchar);

	//��ȡ�ַ���
	static string StrSub(string str, int index);
	static string StrSub(char* pchar, int index);
	static string StrSub(string str, int index, int count);
	static string StrSub(char* pchar, int index, int count);
	static string StrLeft(string str, int count);
	static string StrLeft(char* pchar, int count);
	static string StrRight(string str, int count);
	static string StrRight(char* pchar, int count);
	static string StrLeftL(string str, int leftLeaveCount);//ȡ�ַ�����ߣ������ұ�
	static string StrLeftL(char* pchar, int leftLeaveCount);
	static string StrRightL(string str, int rightLeaveCount);//ȡ�ַ����ұߣ��������
	static string StrRightL(char* pchar, int rightLeaveCount);

	//��ȡ�ַ���λ��
	static int StrPos(string str1, string str2, int index = 0);
	static int StrPos(char* pchar1, string str2, int index = 0);
	static int StrPos(char* pchar1, char* pchar2, int index = 0);
	static int StrPos(string str1, char* pchar2, int index = 0);
        
	//���ַ���strs��ȡ��startpλ�ÿ�ʼ���������һ��subs���ڵ�λ�ã��ú�����ʵ��ȡsubs���ұ߿�ʼ��λ�á�startp��ʾstrs�������Ч���ַ�λ�ã����λ��һ��С�ڵ���startp
	static int StrPosDown(string strs, string subs, int startp);
	static int StrPosDown(char* pchar, char* subPchar, int startp);
	static int StrPosDown(string strs, string subs);
	static int StrPosDown(char* pchar, char* subPchar);

	//�ظ��ַ���
	static string StrRepeat(string str, int repeatCount);
	static string StrRepeat(char* pchar, int repeatCount);

	//�ַ�����Сдת��
	static string StrUpper(char* pchar);
	static string StrUpper(string str);
	static string StrLower(char* pchar);
	static string StrLower(string str);

	//�ַ�����ȡ�ո�
	static string StrTrim(string str);
	static string StrTrim(char* pchar);
	static string StrLTrim(string str);
	static string StrLTrim(char* pchar);
	static string StrRTrim(string str);
	static string StrRTrim(char* pchar);

	//�ַ����Ƚϣ����ǰ��һ���Ⱥ���һ�����򷵻�1����ȷ���0�����򷵻�-1
	static int StrComp(string str1, string str2);
	static int StrComp(char* pchar1, string str2);
	static int StrComp(char* pchar1, char* pchar2);
	static int StrComp(string str1, char* pchar2);

	//�ַ����滻
	static string StrReplace(string str, int index, int count, string dstStr);
	static string StrReplace(string str, int index, int count, char* dstPchar);
	static string StrReplace(char* pchar, int index, int count, char* dstPchar);
	static string StrReplace(char* pchar, int index, int count, string dstStr);
	static string StrReplaceAll(string str, string searchFor, string replaceAs, int index = 0);
	static string StrReplaceAll(char* pchar, char* searchFor, char* replaceAs, int index = 0);

	//���ַ���strs����dptsΪ�ָ�����ȡ��nos���ָ��
	static string StrDepart(string strs, string dpts, int nos);//strs�ĸ�ʽΪ��<str>[<dpts><str>]��strs�е�һ���ָ��nosΪ0
	static string StrDepart(string strs, int nos);//strs�ĸ�ʽΪ��<str>[;<str>]��strs�е�һ���ָ��nosΪ0
	static string StrDepart(char* pchar, char* dptPchar, int nos);
	static string StrDepart(char* pchar, int nos);

	//���ַ���strs��ȡ����ʶΪids��ֵ������dptsΪ�ָ�����equsΪ��ֵ�����ַ���strs�ĸ�ʽΪ��<name><equs><value>[<dpts><name><equs><value>]
	static string GetParmStr(string strs, string dpts, string equs, string ids);
	//���ַ���strs��ȡ����ʶΪids��ֵ������dptsΪ�ָ�������ֵ��Ϊ"="���ַ���strs�ĸ�ʽΪ��<name>=<value>[<dpts><name>=<value>]
	static string GetParmStr(string strs, string dpts, string ids);
	//���ַ���strs��ȡ����ʶΪids��ֵ�����зָ���Ϊ";"����ֵ��Ϊ"="���ַ���strs�ĸ�ʽΪ��<name>=<value>[;<name>=<value>]
	static string GetParmStr(string strs, string ids);
	//���ַ���srs�б�ʶΪids��ֵ����Ϊvals������dptsΪ�ָ�����equsΪ��ֵ�����ַ���strs�ĸ�ʽΪ��<name><equs><value>[<dpts><name><equs><value>]
	static string SetParmStr(string strs, string dpts, string equs, string ids, string vals);
	//���ַ���srs�б�ʶΪids��ֵ����Ϊvals������dptsΪ�ָ�������ֵ��Ϊ"="���ַ���strs�ĸ�ʽΪ��<name>=<value>[<dpts><name>=<value>]
	static string SetParmStr(string strs, string dpts, string ids, string vals);
	//���ַ���srs�б�ʶΪids��ֵ����Ϊvals�����зָ���Ϊ";"����ֵ��Ϊ"="���ַ���strs�ĸ�ʽΪ��<name>=<value>[;<name>=<value>]
	static string SetParmStr(string strs, string ids, string vals);
	//���ַ���srs�б�ʶΪids��ֵɾ��������dptsΪ�ָ�����equsΪ��ֵ�����ַ���strs�ĸ�ʽΪ��<name><equs><value>[<dpts><name><equs><value>]
	static string DelParmStr(string strs, string dpts, string equs, string ids);
	//���ַ���srs�б�ʶΪids��ֵɾ��������dptsΪ�ָ�������ֵ��Ϊ"="���ַ���strs�ĸ�ʽΪ��<name>=<value>[<dpts><name>=<value>]
	static string DelParmStr(string strs, string dpts, string ids);
	//���ַ���srs�б�ʶΪids��ֵɾ�������зָ���Ϊ";"����ֵ��Ϊ"="���ַ���strs�ĸ�ʽΪ��<name>=<value>[;<name>=<value>]
	static string DelParmStr(string strs, string ids);

	//����ֵת��Ϊ�ַ���
	static string StrConvertFromLong(long long ival);
	static string StrConvertFromInt(int ival);
	static string StrConvertFromShort(short ival);
	static string StrConvertFromByte(char ival);
	static string StrConvertFromDouble(double dval, int dec);
	static string StrConvertFromFloat(float fval, int dec);
	//���ַ���ת��Ϊ��ֵ
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

	//Ϊ�ַ����ӵ�����
	static string StrExpr(string strs);
	//����ָ���ָ������ַ�����ֳ�һ������
	static vector<string> StrSplite(string strs, string dpts, bool noEmptyStr = false);
	//�ж��Ƿ��Ǳ��ַָ�����С�ַ����������������ո񡢻س���TAB�ȷָ������򷵻�false
	static bool StrIsNoSplitted(string sStr);
	//��ȡ�������ָ����ַ����ĵ�ʵ�����ݺ���ʼλ��
	static string StrGetSplittedPos(string sSrc, string sFirst, string sSecond, int &iPos);
	//����ֵ�����ַ���codestrǰ�����"0"ʹ��ﵽcodelen���ַ����Ⱥ���������codestr�ĳ��ȴ��ڵ���codelen��ֱ�����codestr��restrictLenҪ���Ƿ��ȡָ���ĳ���
    static string StrFillCode(string codestr, int codelen, bool restrictLen);
    static string StrFillCode(long long codelong, int codelen, bool restrictLen);
	//���ַ���sText��ǰ����ַ�cPadChar��bUntilWidth��ʾ���ַ��ĳ���iWidth��Ҫ�ﵽ�ĳ��ȣ�����Ҫ���ĳ��ȣ�bPadTail��ʾ�Ƿ��ַ�����sText�ĺ���
	static string StrPadChar(string sText, char cPadChar, int iWidth, bool bUntilWidth, bool bPadTail);
	//���ַ���sText��ǰ���ո�bUntilWidth��ʾ���ַ��ĳ���iWidth��Ҫ�ﵽ�ĳ��ȣ�����Ҫ���ĳ��ȣ�bPadTail��ʾ�Ƿ��ַ�����sText�ĺ���
	static string StrPadSpace(string sText, int iWidth, bool bUntilWidth, bool bPadTail);
	//�������ַ���hzsת��Ϊƴ����ƴ������м��зǺ�����ֱ�����
	static string GetHzPY(string hzs);
	//�������ַ���hzsת��Ϊ�������ĸ������м��зǺ�����ֱ�����
	static string GetHzWB(string hzs);

	//�ַ�����ʽ��
	static string StrFormat(const char *fmt, ...);
	static string StrFormat(const char *fmt, va_list argptr);

	//MB UTF8 ת��Ϊ Unicode
	static wstring StrConvertUTF8ToUnicode(const string& src);
	//Unicode ת��Ϊ MB UTF8
	static string StrConvertUnicodeToUTF8(const wstring& src);
	//MB  ת��Ϊ Unicode
	static wstring StrConvertMBToUnicode(const string& src);
	//Unicode ת��Ϊ MB
	static string StrConvertUnicodeToMB(const wstring& src);
	//UTF8 ת��Ϊ GBK
	static string StrConvertUtf8ToGbk(char* utf8);
	static string StrConvertUtf8ToGbk(string utf8);
	//GBK ת��Ϊ UTF8
	static string StrConvertGbkToUtf8(char* gb2312);
	static string StrConvertGbkToUtf8(string gb2312);

	//��ȡ�ַ�����HashCode
	static int StrGetHashCode(string s);
	static int StrGetHashCode(char* pchar);

	//���ܺ���
	static string StrEncrypt(string S, long long Key);
	//���ܺ���
	static string StrDecrypt(string S, long long Key);

};

#endif