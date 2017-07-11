#pragma once
#include<stdlib.h>
#include<stdio.h>

/*猴⼦吃桃问题。猴⼦第⼀天摘下若⼲个桃⼦，当即吃了⼀半，好不
过瘾，又多吃了⼀个。第⼆天早上又吃了剩下的桃⼦的⼀半，又多吃
了⼀个。以后每天都吃了前⼀天剩下的⼀半零⼀个，到第 10 天早上想
再吃的时候，就剩下⼀个桃⼦。求第⼀天共摘多少个桃⼦。*/

void Test18()
{
	int day = 9;//第九天后就剩了1个桃子
	int sum = 0;
	int x = 1;
	while (day)
	{
		sum = (x + 1) * 2;
		x = sum;
		day--;
	}
	printf("The total is %d\n", sum);
}