#include "CommonDefine.h"

//�ж�����һ�������ڼ�
int caculateDay(int y, int m, int d)
{
	if (m == January || m == February)
	{
		m += December;
		--y;
	}
	int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7 + 1;	//���չ�ʽ
	return Week;
}