
//��������ĳ���
#define CountArray(a)	sizeof((a))/sizeof((a)[0])
typedef const char* c_ch;

//�ж�ƽ�껹������
#define  isLeapYear(year) (year) % 4 == 0 && (year) % 100 != 0 || (year) % 400 == 0		//���Ϊ0 ��ƽ�꣬��Ȼ������

enum WeekEnum
{
	NoneWeek,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

enum monthEnum
{
	NoneMonth,
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

//�ж�����һ�������ڼ�
int caculateDay(int y, int m, int d);