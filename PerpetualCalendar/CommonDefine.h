
//计算数组的长度
#define CountArray(a)	sizeof((a))/sizeof((a)[0])
typedef const char* c_ch;

//判断平年还是闰年
#define  isLeapYear(year) (year) % 4 == 0 && (year) % 100 != 0 || (year) % 400 == 0		//结果为0 是平年，不然是闰年

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

//判断任意一天是星期几
int caculateDay(int y, int m, int d);