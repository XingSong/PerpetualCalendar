#include "CommonDefine.h"

//判断任意一天是星期几
int caculateDay(int y, int m, int d)
{
	if (m == January || m == February)
	{
		m += December;
		--y;
	}
	int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7 + 1;	//蔡勒公式
	return Week;
}