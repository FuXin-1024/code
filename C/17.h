#pragma once
#include<stdlib.h>
#include<stdio.h>

//  2/1+3/2+5/3+8/5+13/8+…
void Test17()
{
	double i = 2;//分子 = 上个数的分子加分母
	double j = 1;//分母 = 上个数的分子
	int n = 0;
	double sum = 0.0;
	for (; n < 20; n++) //前20项的和
	{
		sum += i / j;
		int tmp = i;
		i = i + j;
		j = tmp;
	}
	printf("前 %d 和为 %f;\n", n, sum);
}
