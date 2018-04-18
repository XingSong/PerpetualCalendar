
#include "PerpetualCalendar.h"
#include "CommonDefine.h"
#include "LunarSolarConverter.h"

#include <iostream>
#include <cstdlib>
using namespace std;
namespace MyTestSpace
{
	void testTheDayOfWeek()
	{
		int year, month, day;
		cout << "请输入年月日:\n";
		while (cin >> year >> month >> day)
		{
			int num = caculateDay(year, month, day);
			const char* strTip = "这是星期";
			switch (num)
			{
			case Monday:
				cout << strTip << "一";
				break;
			case Tuesday:
				cout << strTip << "二";
				break;
			case Wednesday:
				cout << strTip << "三";
				break;
			case Thursday:
				cout << strTip << "四";
				break;
			case Friday:
				cout << strTip << "五";
				break;
			case Saturday:
				cout << strTip << "六";
				break;
			case Sunday:
				cout << strTip << "日";
				break;
			default:
				break;
			}
			cout << endl;
		}
	}

	void testIsLeapYear()
	{
		int year;
		cout << "请输入年份:\n";
		while (cin >> year)
		{
			if (isLeapYear(year) != 0)
				cout << year << "年是闰年" << endl;
			else
				cout << year << "年是平年" << endl;
		}
	}
	//计算天干地支
	void testcaculateHeavenlyStemsAndEarthlyBranches()
	{
		CPerpetualCalendar obj;
		int year;
		cout << "请输入年份:\n";
		while (cin >> year)
			cout << "这是 " << obj.caculateYearOfHeavenlyStemsAndEarthlyBranches(year) << "年" << endl;
	}

	void testLunar()
	{
		CPerpetualCalendar obj;
		int year, month, day;
		cout << "请输入年月日:\n";
		while (cin >> year >> month >> day)
		{
			Solar solar;
			solar.solarYear = year;
			solar.solarMonth = month;
			solar.solarDay = day;
			Lunar lunar;
			lunar = SolarToLunar(solar);
			//cout << "农历:" << lunar.lunarYear << "年" << obj.convertLunarMonthDayToCharacter(lunar.lunarMonth, lunar.lunarDay) << endl;
		}
	}

	void test12ChineseZodiacSigns()
	{
		CPerpetualCalendar obj;
		int year, month, day;
		cout << "请输入年月日:\n";
		while (cin >> year >> month >> day)
		{
			cout << "这是" << obj.caculate12ChineseZodiacSigns(year, month, day) << "年" << endl;
		}
	}

	void testcaculateDayOfHeavenlyStemsAndEarthlyBranches()
	{
		CPerpetualCalendar obj;
		int year, month, day;
		cout << "请输入年月日:\n";
		while (cin >> year >> month >> day)
		{
			cout << "这是" << obj.caculateDayOfHeavenlyStemsAndEarthlyBranches(year, month, day) << endl;
		}
	}
}
void main()
{
//	testTheDayOfWeek();
	//testIsLeapYear();
	//testcaculateHeavenlyStemsAndEarthlyBranches();
	//testLunar();
	
	//test12ChineseZodiacSigns();
//	testcaculateDayOfHeavenlyStemsAndEarthlyBranches();
	CPerpetualCalendar obj;
	int year, month, day;
	cout << "请输入年月日:\n";
	while (cin >> year >> month >> day)
	{
		cout << "当日是 " << obj.caculateYearOfHeavenlyStemsAndEarthlyBranches(year) << "年 " << obj.caculateMonthOfHeavenlyStemsAndEarthlyBranches(year, month, day) << "月  " << obj.caculateDayOfHeavenlyStemsAndEarthlyBranches(year, month, day) << "日" << " [" << obj.caculate12ChineseZodiacSigns(year, month, day) << "年] " << obj.convertLunarMonthDayToCharacter(year, month, day) << endl;
	}
	system("pause");
}