#include "PerpetualCalendar.h"
#include "LunarSolarConverter.h"
#include "CommonDefine.h"

using namespace std;
#define BEING_YEAR 1900
#define TIANGAN 10
#define DIZHI 12

CPerpetualCalendar::CPerpetualCalendar()
{
	//ʮ��� Heavenly Stems(H-S)
	//��	��	��	��	��	��	��	��	��	��
	mapHeavenlyStems.insert(pair<int, string>(1, "��"));
	mapHeavenlyStems.insert(pair<int, string>(2, "��"));
	mapHeavenlyStems.insert(pair<int, string>(3, "��"));
	mapHeavenlyStems.insert(pair<int, string>(4, "��"));
	mapHeavenlyStems.insert(pair<int, string>(5, "��"));
	mapHeavenlyStems.insert(pair<int, string>(6, "��"));
	mapHeavenlyStems.insert(pair<int, string>(7, "��"));
	mapHeavenlyStems.insert(pair<int, string>(8, "��"));
	mapHeavenlyStems.insert(pair<int, string>(9, "��"));
	mapHeavenlyStems.insert(pair<int, string>(10, "��"));

	//ʮ����֧ Earthly Branches (E-B)
	//��	��	��	î	��	��	��	δ	��	��	��	��
	mapEarthlyBranches.insert(map<int, string>::value_type(1, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(2, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(3, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(4, "î"));
	mapEarthlyBranches.insert(map<int, string>::value_type(5, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(6, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(7, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(8, "δ"));
	mapEarthlyBranches.insert(map<int, string>::value_type(9, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(10, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(11, "��"));
	mapEarthlyBranches.insert(map<int, string>::value_type(12, "��"));

	//��Ԫǰ����
	//ʮ��� Heavenly Stems(H-S)
	//��	��	��	��	��	��	��	��	��	��
	mapBCHeavenlyStems.insert(pair<int, string>(7, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(6, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(5, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(4, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(3, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(2, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(1, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(10, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(9, "��"));
	mapBCHeavenlyStems.insert(pair<int, string>(8, "��"));
	//ʮ����֧ Earthly Branches (E-B)
	//��	��	��	î	��	��	��	δ	��	��	��	��
	mapBCEarthlyBranches.insert(map<int, string>::value_type(9, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(8, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(7, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(6, "î"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(5, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(4, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(3, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(2, "δ"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(1, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(12, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(11, "��"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(10, "��"));

	//ʮ����Ф
	str12ChineseZodiacSigns[0]  = "��";
	str12ChineseZodiacSigns[1]  = "ţ";
	str12ChineseZodiacSigns[2]  = "��";
	str12ChineseZodiacSigns[3]  = "��";
	str12ChineseZodiacSigns[4]  = "��";
	str12ChineseZodiacSigns[5]  = "��";
	str12ChineseZodiacSigns[6]  = "��";
	str12ChineseZodiacSigns[7]  = "��";
	str12ChineseZodiacSigns[8]  = "��";
	str12ChineseZodiacSigns[9]  = "��";
	str12ChineseZodiacSigns[10] = "��";
	str12ChineseZodiacSigns[11] = "��";

	//��������
	mapLunarMonth.insert(pair<int, string>(1, "����"));
	mapLunarMonth.insert(pair<int, string>(2, "����"));
	mapLunarMonth.insert(pair<int, string>(3, "����"));
	mapLunarMonth.insert(pair<int, string>(4, "����"));
	mapLunarMonth.insert(pair<int, string>(5, "����"));
	mapLunarMonth.insert(pair<int, string>(6, "����"));
	mapLunarMonth.insert(pair<int, string>(7, "����"));
	mapLunarMonth.insert(pair<int, string>(8, "����"));
	mapLunarMonth.insert(pair<int, string>(9, "����"));
	mapLunarMonth.insert(pair<int, string>(10, "ʮ��"));
	mapLunarMonth.insert(pair<int, string>(11, "ʮһ��"));
	mapLunarMonth.insert(pair<int, string>(12, "����"));

	//��������
	mapLunarDay.insert(pair<int, string>(1, "��һ"));
	mapLunarDay.insert(pair<int, string>(2, "����"));
	mapLunarDay.insert(pair<int, string>(3, "����"));
	mapLunarDay.insert(pair<int, string>(4, "����"));
	mapLunarDay.insert(pair<int, string>(5, "����"));
	mapLunarDay.insert(pair<int, string>(6, "����"));
	mapLunarDay.insert(pair<int, string>(7, "����"));
	mapLunarDay.insert(pair<int, string>(8, "����"));
	mapLunarDay.insert(pair<int, string>(9, "����"));
	mapLunarDay.insert(pair<int, string>(10, "ʮ"));
	mapLunarDay.insert(pair<int, string>(11, "ʮһ"));
	mapLunarDay.insert(pair<int, string>(12, "ʮ��"));
	mapLunarDay.insert(pair<int, string>(13, "ʮ��"));
	mapLunarDay.insert(pair<int, string>(14, "ʮ��"));
	mapLunarDay.insert(pair<int, string>(15, "ʮ��"));
	mapLunarDay.insert(pair<int, string>(16, "ʮ��"));
	mapLunarDay.insert(pair<int, string>(17, "ʮ��"));
	mapLunarDay.insert(pair<int, string>(18, "ʮ��"));
	mapLunarDay.insert(pair<int, string>(19, "ʮ��"));
	mapLunarDay.insert(pair<int, string>(20, "��ʮ"));
	mapLunarDay.insert(pair<int, string>(21, "إһ"));
	mapLunarDay.insert(pair<int, string>(22, "إ��"));
	mapLunarDay.insert(pair<int, string>(23, "إ��"));
	mapLunarDay.insert(pair<int, string>(24, "إ��"));
	mapLunarDay.insert(pair<int, string>(25, "إ��"));
	mapLunarDay.insert(pair<int, string>(26, "إ��"));
	mapLunarDay.insert(pair<int, string>(27, "إ��"));
	mapLunarDay.insert(pair<int, string>(28, "إ��"));
	mapLunarDay.insert(pair<int, string>(29, "إ��"));
	mapLunarDay.insert(pair<int, string>(30, "��ʮ"));


}


CPerpetualCalendar::~CPerpetualCalendar()
{
}
//������ɵ�֧����
int CPerpetualCalendar::indexOfHeavenlyStemsAndEarthlyBranches(int year, int tag)
{
	if (year<0)
		year = year*(-1);
	int iTmp = year%tag;
	if (iTmp > 3)
	{
		return (iTmp - 3);

	}
	else
	{
		return iTmp + tag - 3;
	}
}
//ʮ���
std::string CPerpetualCalendar::caculateHeavenlyStems(int year)
{
	string  strTianGan;
	int iTianGan = indexOfHeavenlyStemsAndEarthlyBranches(year, TIANGAN);
	map<int, string>::iterator iter;
	if (year < 0)
	{
		for (iter = mapBCHeavenlyStems.begin(); iter != mapBCHeavenlyStems.end(); ++iter)
		{
			if (iTianGan == iter->first)
			{
				strTianGan = iter->second;
				break;
			}
		}
	}
	else
	{
		for (iter = mapHeavenlyStems.begin(); iter != mapHeavenlyStems.end(); ++iter)
		{
			if (iTianGan == iter->first)
			{
				strTianGan = iter->second;
				break;
			}
		}
	}
	return strTianGan;
}
//ʮ����֧
std::string CPerpetualCalendar::caculateEarthlyBranches(int year)
{
	string  strDiZhi;
	int iDiZhi = indexOfHeavenlyStemsAndEarthlyBranches(year, DIZHI);
	if (year < 0)
	{
		for (map<int, string>::reverse_iterator iter = mapBCEarthlyBranches.rbegin(); iter != mapBCEarthlyBranches.rend(); iter++)
		{
			if (iDiZhi == iter->first)
			{
				strDiZhi = iter->second;
				break;
			}
		}
	}
	else
	{
		for (map<int, string>::reverse_iterator iter = mapEarthlyBranches.rbegin(); iter != mapEarthlyBranches.rend(); iter++)
		{
			if (iDiZhi == iter->first)
			{
				strDiZhi = iter->second;
				break;
			}
		}
	}
	
	return  strDiZhi;
}
//��֧����
std::string CPerpetualCalendar::caculateYearOfHeavenlyStemsAndEarthlyBranches(int year)
{
	string strTianGan = caculateHeavenlyStems(year);
	string strDiZhi = caculateEarthlyBranches(year);
	return strTianGan + strDiZhi;
}
//��֧����
std::string CPerpetualCalendar::caculateMonthOfHeavenlyStemsAndEarthlyBranches(int year, int month,int day)
{
	Solar solar;
	Lunar lunar;
	solar.solarYear = year;
	solar.solarMonth = month;
	solar.solarDay = day;
	lunar = SolarToLunar(solar);
	month = lunar.lunarMonth;
	day = lunar.lunarDay;

	//��֧���ǹ̶���,ֻ���ж����֧
	map<int, string> mapDiZhiMonth;
	mapDiZhiMonth.insert(pair<int, string>(1, "��"));
	mapDiZhiMonth.insert(pair<int, string>(2, "î"));
	mapDiZhiMonth.insert(pair<int, string>(3, "��"));
	mapDiZhiMonth.insert(pair<int, string>(4, "��"));
	mapDiZhiMonth.insert(pair<int, string>(5, "��"));
	mapDiZhiMonth.insert(pair<int, string>(6, "δ"));
	mapDiZhiMonth.insert(pair<int, string>(7, "��"));
	mapDiZhiMonth.insert(pair<int, string>(8, "��"));
	mapDiZhiMonth.insert(pair<int, string>(9, "��"));
	mapDiZhiMonth.insert(pair<int, string>(10, "��"));
	mapDiZhiMonth.insert(pair<int, string>(11,"��"));
	mapDiZhiMonth.insert(pair<int, string>(12, "��"));

	//��֧����������Ϊһ������,�ܶ���ʼ ����б�����
	string str1[12] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" }; //�ס���
	string str2[12] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" }; //�ҡ���
	string str3[12] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" }; //������
	string str4[12] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" }; //������
	string str5[12] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" }; //�졢��

	map<int, string>::iterator iter;
	string strGanZhiJiYue;
	string strTianGan = caculateHeavenlyStems(year);
	
	for (iter = mapDiZhiMonth.begin(); iter != mapDiZhiMonth.end(); iter++)
	{
		if (month == iter->first)
		{
			if (strTianGan == "��" || strTianGan == "��")
			{
				strGanZhiJiYue = str1[iter->first - 1] + iter->second;
				break;
			}
			else if (strTianGan == "��" || strTianGan == "��")
			{
				strGanZhiJiYue = str2[iter->first - 1] + iter->second;
				break;
			}
			else if (strTianGan == "��" || strTianGan == "��")
			{
				strGanZhiJiYue = str3[iter->first - 1] + iter->second;
				break;
			}
			else if (strTianGan == "��" || strTianGan == "��")
			{
				strGanZhiJiYue = str4[iter->first - 1] + iter->second;
				break;
			}
			else if (strTianGan == "��" || strTianGan == "��")
			{
				strGanZhiJiYue = str5[iter->first - 1] + iter->second;
				break;
			}
		}
	}
	return strGanZhiJiYue;
}
//��֧����
std::string CPerpetualCalendar::caculateDayOfHeavenlyStemsAndEarthlyBranches(int year, int month, int day)
{	
	if (month == January || month == February)
	{
		month += December;
		--year;
	}
	int s = year % 100;
	int u = s % 4;
	int m = getMonthlyBase(month);
	int d = day;
	int x = getCenturyConstant(year / 100 + 1);
	int r = s / 4 * 6 + 5 * (s / 4 * 3 + u) + m + d + x;	//����������ʽ
	int sunpillar = r % 60;

	string strTianGanRi,strDiZhiRi;
	for (map<int, string>::iterator iter = mapHeavenlyStems.begin(); iter != mapHeavenlyStems.end(); iter++)
	{
		if (0 == sunpillar % TIANGAN)
		{
			strTianGanRi = mapHeavenlyStems[10];
			break;
		}
		else if (sunpillar % TIANGAN == iter->first)
		{
			strTianGanRi = iter->second;
			break;
		}
	}

	for (map<int, string>::iterator iter = mapEarthlyBranches.begin(); iter != mapEarthlyBranches.end(); iter++)
	{
		if (0 == sunpillar % DIZHI)
		{
			strDiZhiRi = mapEarthlyBranches[12];
			break;
		}		
		else if(sunpillar % DIZHI == iter->first)
		{
			strDiZhiRi = iter->second;
			break;
		}
	}
	return strTianGanRi + strDiZhiRi;
}
//���ͳ���
int CPerpetualCalendar::getCenturyConstant(int century)
{
	int X = 44 * (century - 1) + (century - 1) / 4 + 9;	//����������ʽ�ĸ�����ʽ
	return X % 60;
}
//�»��� ǰ�����µ������ܺͳ���60������
int CPerpetualCalendar::getMonthlyBase(int month)
{
	map<int, int> mapMonthlyBase;
	mapMonthlyBase.insert(pair<int, int>(3, 0));
	mapMonthlyBase.insert(pair<int, int>(4, 31));
	mapMonthlyBase.insert(pair<int, int>(5, 1));
	mapMonthlyBase.insert(pair<int, int>(6, 32));
	mapMonthlyBase.insert(pair<int, int>(7, 2));
	mapMonthlyBase.insert(pair<int, int>(8, 33));
	mapMonthlyBase.insert(pair<int, int>(9, 4));
	mapMonthlyBase.insert(pair<int, int>(10, 34));
	mapMonthlyBase.insert(pair<int, int>(11, 5));
	mapMonthlyBase.insert(pair<int, int>(12, 35));
	mapMonthlyBase.insert(pair<int, int>(13, 6));
	mapMonthlyBase.insert(pair<int, int>(14, 37));

	map<int, int>::iterator iter;
	int iRet;
	for (iter = mapMonthlyBase.begin(); iter != mapMonthlyBase.end(); iter++)
	{
		if (month == iter->first)
			iRet= iter->second;
	}
	return iRet;
}

//������Ф
std::string CPerpetualCalendar::caculate12ChineseZodiacSigns(int year, int month, int day)
{
	string strZodiacSigns;
	Solar solar;
	solar.solarYear = year;
	solar.solarMonth = month;
	solar.solarDay = day;
	Lunar lunar;
	lunar = SolarToLunar(solar);
	for (size_t i = 0; i < CountArray(str12ChineseZodiacSigns); i++)
	{
		if (i == (year - BEING_YEAR) % 12)
		{
			if (convertLunarMonthDayToCharacter(lunar.lunarYear, lunar.lunarMonth, lunar.lunarDay) < convertLunarMonthDayToCharacter(lunar.lunarYear, 1, 1))
			{
				if (i == 0)
					strZodiacSigns = str12ChineseZodiacSigns[12 - 1 - i];
				else
					strZodiacSigns = str12ChineseZodiacSigns[i - 1];
			}
			else
				strZodiacSigns = str12ChineseZodiacSigns[i];
		}

	}
	return strZodiacSigns;
}
//��������ת��Ϊ����
std::string CPerpetualCalendar::convertLunarMonthToCharacter(int month)
{
	string strMonth;
	for (map<int, string>::iterator iter = mapLunarMonth.begin(); iter != mapLunarMonth.end(); iter++)
	{
		if (month == iter->first)
		{
			strMonth = iter->second;
			break;
		}
	}
	return strMonth;
}
//��������ת��Ϊ����
std::string CPerpetualCalendar::convertLunarDayToCharacter(int day)
{
	string strDay;
	for (map<int, string>::iterator iter = mapLunarDay.begin(); iter != mapLunarDay.end(); iter++)
	{
		if (day == iter->first)
		{
			strDay = iter->second;
			break;
		}
	}
	return strDay;
}
//�������º���ת��Ϊ����
std::string CPerpetualCalendar::convertLunarMonthDayToCharacter(int year,int month, int day)
{
	Solar solar;
	Lunar lunar;
	solar.solarYear = year;
	solar.solarMonth = month;
	solar.solarDay = day;
	lunar = SolarToLunar(solar);
	month = lunar.lunarMonth;
	day = lunar.lunarDay;

	string strMonth, strDay;
	strMonth = convertLunarMonthToCharacter(month);
	strDay = convertLunarDayToCharacter(day);
	return strMonth + strDay;
}
