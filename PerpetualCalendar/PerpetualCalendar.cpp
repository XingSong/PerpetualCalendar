#include "PerpetualCalendar.h"
#include "LunarSolarConverter.h"
#include "CommonDefine.h"

using namespace std;
#define BEING_YEAR 1900
#define TIANGAN 10
#define DIZHI 12

CPerpetualCalendar::CPerpetualCalendar()
{
	//十天干 Heavenly Stems(H-S)
	//甲	乙	丙	丁	戊	己	庚	辛	壬	癸
	mapHeavenlyStems.insert(pair<int, string>(1, "甲"));
	mapHeavenlyStems.insert(pair<int, string>(2, "乙"));
	mapHeavenlyStems.insert(pair<int, string>(3, "丙"));
	mapHeavenlyStems.insert(pair<int, string>(4, "丁"));
	mapHeavenlyStems.insert(pair<int, string>(5, "戊"));
	mapHeavenlyStems.insert(pair<int, string>(6, "己"));
	mapHeavenlyStems.insert(pair<int, string>(7, "庚"));
	mapHeavenlyStems.insert(pair<int, string>(8, "辛"));
	mapHeavenlyStems.insert(pair<int, string>(9, "壬"));
	mapHeavenlyStems.insert(pair<int, string>(10, "癸"));

	//十二地支 Earthly Branches (E-B)
	//子	丑	寅	卯	辰	巳	午	未	申	酉	戌	亥
	mapEarthlyBranches.insert(map<int, string>::value_type(1, "子"));
	mapEarthlyBranches.insert(map<int, string>::value_type(2, "丑"));
	mapEarthlyBranches.insert(map<int, string>::value_type(3, "寅"));
	mapEarthlyBranches.insert(map<int, string>::value_type(4, "卯"));
	mapEarthlyBranches.insert(map<int, string>::value_type(5, "辰"));
	mapEarthlyBranches.insert(map<int, string>::value_type(6, "巳"));
	mapEarthlyBranches.insert(map<int, string>::value_type(7, "午"));
	mapEarthlyBranches.insert(map<int, string>::value_type(8, "未"));
	mapEarthlyBranches.insert(map<int, string>::value_type(9, "申"));
	mapEarthlyBranches.insert(map<int, string>::value_type(10, "酉"));
	mapEarthlyBranches.insert(map<int, string>::value_type(11, "戌"));
	mapEarthlyBranches.insert(map<int, string>::value_type(12, "亥"));

	//公元前纪年
	//十天干 Heavenly Stems(H-S)
	//甲	乙	丙	丁	戊	己	庚	辛	壬	癸
	mapBCHeavenlyStems.insert(pair<int, string>(7, "甲"));
	mapBCHeavenlyStems.insert(pair<int, string>(6, "乙"));
	mapBCHeavenlyStems.insert(pair<int, string>(5, "丙"));
	mapBCHeavenlyStems.insert(pair<int, string>(4, "丁"));
	mapBCHeavenlyStems.insert(pair<int, string>(3, "戊"));
	mapBCHeavenlyStems.insert(pair<int, string>(2, "己"));
	mapBCHeavenlyStems.insert(pair<int, string>(1, "庚"));
	mapBCHeavenlyStems.insert(pair<int, string>(10, "辛"));
	mapBCHeavenlyStems.insert(pair<int, string>(9, "壬"));
	mapBCHeavenlyStems.insert(pair<int, string>(8, "癸"));
	//十二地支 Earthly Branches (E-B)
	//子	丑	寅	卯	辰	巳	午	未	申	酉	戌	亥
	mapBCEarthlyBranches.insert(map<int, string>::value_type(9, "子"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(8, "丑"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(7, "寅"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(6, "卯"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(5, "辰"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(4, "巳"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(3, "午"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(2, "未"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(1, "申"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(12, "酉"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(11, "戌"));
	mapBCEarthlyBranches.insert(map<int, string>::value_type(10, "亥"));

	//十二生肖
	str12ChineseZodiacSigns[0]  = "鼠";
	str12ChineseZodiacSigns[1]  = "牛";
	str12ChineseZodiacSigns[2]  = "虎";
	str12ChineseZodiacSigns[3]  = "兔";
	str12ChineseZodiacSigns[4]  = "龙";
	str12ChineseZodiacSigns[5]  = "蛇";
	str12ChineseZodiacSigns[6]  = "马";
	str12ChineseZodiacSigns[7]  = "羊";
	str12ChineseZodiacSigns[8]  = "猴";
	str12ChineseZodiacSigns[9]  = "鸡";
	str12ChineseZodiacSigns[10] = "狗";
	str12ChineseZodiacSigns[11] = "猪";

	//阴历的月
	mapLunarMonth.insert(pair<int, string>(1, "正月"));
	mapLunarMonth.insert(pair<int, string>(2, "二月"));
	mapLunarMonth.insert(pair<int, string>(3, "三月"));
	mapLunarMonth.insert(pair<int, string>(4, "四月"));
	mapLunarMonth.insert(pair<int, string>(5, "五月"));
	mapLunarMonth.insert(pair<int, string>(6, "六月"));
	mapLunarMonth.insert(pair<int, string>(7, "七月"));
	mapLunarMonth.insert(pair<int, string>(8, "八月"));
	mapLunarMonth.insert(pair<int, string>(9, "九月"));
	mapLunarMonth.insert(pair<int, string>(10, "十月"));
	mapLunarMonth.insert(pair<int, string>(11, "十一月"));
	mapLunarMonth.insert(pair<int, string>(12, "腊月"));

	//阴历的日
	mapLunarDay.insert(pair<int, string>(1, "初一"));
	mapLunarDay.insert(pair<int, string>(2, "初二"));
	mapLunarDay.insert(pair<int, string>(3, "初三"));
	mapLunarDay.insert(pair<int, string>(4, "初四"));
	mapLunarDay.insert(pair<int, string>(5, "初五"));
	mapLunarDay.insert(pair<int, string>(6, "初六"));
	mapLunarDay.insert(pair<int, string>(7, "初七"));
	mapLunarDay.insert(pair<int, string>(8, "初八"));
	mapLunarDay.insert(pair<int, string>(9, "初九"));
	mapLunarDay.insert(pair<int, string>(10, "十"));
	mapLunarDay.insert(pair<int, string>(11, "十一"));
	mapLunarDay.insert(pair<int, string>(12, "十二"));
	mapLunarDay.insert(pair<int, string>(13, "十三"));
	mapLunarDay.insert(pair<int, string>(14, "十四"));
	mapLunarDay.insert(pair<int, string>(15, "十五"));
	mapLunarDay.insert(pair<int, string>(16, "十六"));
	mapLunarDay.insert(pair<int, string>(17, "十七"));
	mapLunarDay.insert(pair<int, string>(18, "十八"));
	mapLunarDay.insert(pair<int, string>(19, "十九"));
	mapLunarDay.insert(pair<int, string>(20, "二十"));
	mapLunarDay.insert(pair<int, string>(21, "廿一"));
	mapLunarDay.insert(pair<int, string>(22, "廿二"));
	mapLunarDay.insert(pair<int, string>(23, "廿三"));
	mapLunarDay.insert(pair<int, string>(24, "廿四"));
	mapLunarDay.insert(pair<int, string>(25, "廿五"));
	mapLunarDay.insert(pair<int, string>(26, "廿六"));
	mapLunarDay.insert(pair<int, string>(27, "廿七"));
	mapLunarDay.insert(pair<int, string>(28, "廿八"));
	mapLunarDay.insert(pair<int, string>(29, "廿九"));
	mapLunarDay.insert(pair<int, string>(30, "三十"));


}


CPerpetualCalendar::~CPerpetualCalendar()
{
}
//计算天干地支索引
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
//十天干
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
//十二地支
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
//干支纪年
std::string CPerpetualCalendar::caculateYearOfHeavenlyStemsAndEarthlyBranches(int year)
{
	string strTianGan = caculateHeavenlyStems(year);
	string strDiZhi = caculateEarthlyBranches(year);
	return strTianGan + strDiZhi;
}
//干支纪月
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

	//地支月是固定的,只需判断天干支
	map<int, string> mapDiZhiMonth;
	mapDiZhiMonth.insert(pair<int, string>(1, "寅"));
	mapDiZhiMonth.insert(pair<int, string>(2, "卯"));
	mapDiZhiMonth.insert(pair<int, string>(3, "辰"));
	mapDiZhiMonth.insert(pair<int, string>(4, "巳"));
	mapDiZhiMonth.insert(pair<int, string>(5, "午"));
	mapDiZhiMonth.insert(pair<int, string>(6, "未"));
	mapDiZhiMonth.insert(pair<int, string>(7, "申"));
	mapDiZhiMonth.insert(pair<int, string>(8, "酉"));
	mapDiZhiMonth.insert(pair<int, string>(9, "戌"));
	mapDiZhiMonth.insert(pair<int, string>(10, "亥"));
	mapDiZhiMonth.insert(pair<int, string>(11,"子"));
	mapDiZhiMonth.insert(pair<int, string>(12, "丑"));

	//干支纪月以五年为一个周期,周而复始 天干列表如下
	string str1[12] = { "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸", "甲", "乙", "丙", "丁" }; //甲、己
	string str2[12] = { "戊", "己", "庚", "辛", "壬", "癸", "甲", "乙", "丙", "丁", "戊", "己" }; //乙、庚
	string str3[12] = { "庚", "辛", "壬", "癸", "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛" }; //丙、辛
	string str4[12] = { "壬", "癸", "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸" }; //丁、壬
	string str5[12] = { "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸", "甲", "乙" }; //戊、癸

	map<int, string>::iterator iter;
	string strGanZhiJiYue;
	string strTianGan = caculateHeavenlyStems(year);
	
	for (iter = mapDiZhiMonth.begin(); iter != mapDiZhiMonth.end(); iter++)
	{
		if (month == iter->first)
		{
			if (strTianGan == "甲" || strTianGan == "己")
			{
				strGanZhiJiYue = str1[iter->first - 1] + iter->second;
				break;
			}
			else if (strTianGan == "乙" || strTianGan == "庚")
			{
				strGanZhiJiYue = str2[iter->first - 1] + iter->second;
				break;
			}
			else if (strTianGan == "丙" || strTianGan == "辛")
			{
				strGanZhiJiYue = str3[iter->first - 1] + iter->second;
				break;
			}
			else if (strTianGan == "丁" || strTianGan == "壬")
			{
				strGanZhiJiYue = str4[iter->first - 1] + iter->second;
				break;
			}
			else if (strTianGan == "戊" || strTianGan == "癸")
			{
				strGanZhiJiYue = str5[iter->first - 1] + iter->second;
				break;
			}
		}
	}
	return strGanZhiJiYue;
}
//干支纪日
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
	int r = s / 4 * 6 + 5 * (s / 4 * 3 + u) + m + d + x;	//高氏日柱公式
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
//世纪常数
int CPerpetualCalendar::getCenturyConstant(int century)
{
	int X = 44 * (century - 1) + (century - 1) / 4 + 9;	//高氏日柱公式的辅助公式
	return X % 60;
}
//月基数 前几个月的日数总和除以60的余数
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

//计算生肖
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
//阴历的月转化为汉字
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
//阴历的日转化为汉字
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
//阴历的月和日转化为汉字
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
