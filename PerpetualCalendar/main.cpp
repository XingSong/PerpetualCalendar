
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
		cout << "������������:\n";
		while (cin >> year >> month >> day)
		{
			int num = caculateDay(year, month, day);
			const char* strTip = "��������";
			switch (num)
			{
			case Monday:
				cout << strTip << "һ";
				break;
			case Tuesday:
				cout << strTip << "��";
				break;
			case Wednesday:
				cout << strTip << "��";
				break;
			case Thursday:
				cout << strTip << "��";
				break;
			case Friday:
				cout << strTip << "��";
				break;
			case Saturday:
				cout << strTip << "��";
				break;
			case Sunday:
				cout << strTip << "��";
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
		cout << "���������:\n";
		while (cin >> year)
		{
			if (isLeapYear(year) != 0)
				cout << year << "��������" << endl;
			else
				cout << year << "����ƽ��" << endl;
		}
	}
	//������ɵ�֧
	void testcaculateHeavenlyStemsAndEarthlyBranches()
	{
		CPerpetualCalendar obj;
		int year;
		cout << "���������:\n";
		while (cin >> year)
			cout << "���� " << obj.caculateYearOfHeavenlyStemsAndEarthlyBranches(year) << "��" << endl;
	}

	void testLunar()
	{
		CPerpetualCalendar obj;
		int year, month, day;
		cout << "������������:\n";
		while (cin >> year >> month >> day)
		{
			Solar solar;
			solar.solarYear = year;
			solar.solarMonth = month;
			solar.solarDay = day;
			Lunar lunar;
			lunar = SolarToLunar(solar);
			//cout << "ũ��:" << lunar.lunarYear << "��" << obj.convertLunarMonthDayToCharacter(lunar.lunarMonth, lunar.lunarDay) << endl;
		}
	}

	void test12ChineseZodiacSigns()
	{
		CPerpetualCalendar obj;
		int year, month, day;
		cout << "������������:\n";
		while (cin >> year >> month >> day)
		{
			cout << "����" << obj.caculate12ChineseZodiacSigns(year, month, day) << "��" << endl;
		}
	}

	void testcaculateDayOfHeavenlyStemsAndEarthlyBranches()
	{
		CPerpetualCalendar obj;
		int year, month, day;
		cout << "������������:\n";
		while (cin >> year >> month >> day)
		{
			cout << "����" << obj.caculateDayOfHeavenlyStemsAndEarthlyBranches(year, month, day) << endl;
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
	cout << "������������:\n";
	while (cin >> year >> month >> day)
	{
		cout << "������ " << obj.caculateYearOfHeavenlyStemsAndEarthlyBranches(year) << "�� " << obj.caculateMonthOfHeavenlyStemsAndEarthlyBranches(year, month, day) << "��  " << obj.caculateDayOfHeavenlyStemsAndEarthlyBranches(year, month, day) << "��" << " [" << obj.caculate12ChineseZodiacSigns(year, month, day) << "��] " << obj.convertLunarMonthDayToCharacter(year, month, day) << endl;
	}
	system("pause");
}