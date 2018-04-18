#pragma once
#include <string>
#include <map>
class CPerpetualCalendar
{
public:
	CPerpetualCalendar();
	~CPerpetualCalendar();
	
	//计算天干地支索引
	int indexOfHeavenlyStemsAndEarthlyBranches(int year, int tag);
	
	//十天干 Heavenly Stems(H-S)
	//甲	乙	丙	丁	戊	己	庚	辛	壬	癸
	std::string caculateHeavenlyStems(int year);
	
	//十二地支 Earthly Branches (E-B)
	//子	丑	寅	卯	辰	巳	午	未	申	酉	戌	亥
	std::string caculateEarthlyBranches(int year);
	
	//干支纪年
	std::string caculateYearOfHeavenlyStemsAndEarthlyBranches(int year);
	
	//干支纪月
	std::string caculateMonthOfHeavenlyStemsAndEarthlyBranches(int year, int month, int day);

	//干支纪日
	std::string caculateDayOfHeavenlyStemsAndEarthlyBranches(int year, int month,int day);

	//世纪常数
	int getCenturyConstant(int century);

	//月基数
	int getMonthlyBase(int month);

	//计算生肖
	std::string caculate12ChineseZodiacSigns(int year, int month, int day);

	//阴历的月转化为汉字
	std::string convertLunarMonthToCharacter(int month);

	//阴历的日转化为汉字
	std::string convertLunarDayToCharacter(int day);

	//阴历的月和日转化为汉字
	std::string convertLunarMonthDayToCharacter(int year, int month, int day);
private:
	//十天干 Heavenly Stems(H-S)
	//甲	乙	丙	丁	戊	己	庚	辛	壬	癸
	std::map<int, std::string> mapHeavenlyStems;

	//十二地支 Earthly Branches (E-B)
	//子	丑	寅	卯	辰	巳	午	未	申	酉	戌	亥
	std::map<int, std::string> mapEarthlyBranches;

	//公元前纪年
	//十天干 Heavenly Stems(H-S)
	//甲	乙	丙	丁	戊	己	庚	辛	壬	癸
	std::map<int, std::string> mapBCHeavenlyStems;
	//十二地支 Earthly Branches (E-B)
	//子	丑	寅	卯	辰	巳	午	未	申	酉	戌	亥
	std::map<int, std::string> mapBCEarthlyBranches;

	//十二生肖
	std::string str12ChineseZodiacSigns[12];

	//阴历的月
	std::map<int, std::string> mapLunarMonth;

	//阴历的日
	std::map<int, std::string> mapLunarDay;
};

