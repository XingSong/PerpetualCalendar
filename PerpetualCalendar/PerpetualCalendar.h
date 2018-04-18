#pragma once
#include <string>
#include <map>
class CPerpetualCalendar
{
public:
	CPerpetualCalendar();
	~CPerpetualCalendar();
	
	//������ɵ�֧����
	int indexOfHeavenlyStemsAndEarthlyBranches(int year, int tag);
	
	//ʮ��� Heavenly Stems(H-S)
	//��	��	��	��	��	��	��	��	��	��
	std::string caculateHeavenlyStems(int year);
	
	//ʮ����֧ Earthly Branches (E-B)
	//��	��	��	î	��	��	��	δ	��	��	��	��
	std::string caculateEarthlyBranches(int year);
	
	//��֧����
	std::string caculateYearOfHeavenlyStemsAndEarthlyBranches(int year);
	
	//��֧����
	std::string caculateMonthOfHeavenlyStemsAndEarthlyBranches(int year, int month, int day);

	//��֧����
	std::string caculateDayOfHeavenlyStemsAndEarthlyBranches(int year, int month,int day);

	//���ͳ���
	int getCenturyConstant(int century);

	//�»���
	int getMonthlyBase(int month);

	//������Ф
	std::string caculate12ChineseZodiacSigns(int year, int month, int day);

	//��������ת��Ϊ����
	std::string convertLunarMonthToCharacter(int month);

	//��������ת��Ϊ����
	std::string convertLunarDayToCharacter(int day);

	//�������º���ת��Ϊ����
	std::string convertLunarMonthDayToCharacter(int year, int month, int day);
private:
	//ʮ��� Heavenly Stems(H-S)
	//��	��	��	��	��	��	��	��	��	��
	std::map<int, std::string> mapHeavenlyStems;

	//ʮ����֧ Earthly Branches (E-B)
	//��	��	��	î	��	��	��	δ	��	��	��	��
	std::map<int, std::string> mapEarthlyBranches;

	//��Ԫǰ����
	//ʮ��� Heavenly Stems(H-S)
	//��	��	��	��	��	��	��	��	��	��
	std::map<int, std::string> mapBCHeavenlyStems;
	//ʮ����֧ Earthly Branches (E-B)
	//��	��	��	î	��	��	��	δ	��	��	��	��
	std::map<int, std::string> mapBCEarthlyBranches;

	//ʮ����Ф
	std::string str12ChineseZodiacSigns[12];

	//��������
	std::map<int, std::string> mapLunarMonth;

	//��������
	std::map<int, std::string> mapLunarDay;
};

