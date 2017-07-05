#pragma once
#include<stdlib.h>
#include<stdio.h>

//¼ÆËã1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ¡­¡­ + 1 / 99 - 1 / 100 µÄÖµ¡£

void Sum()
{
	float i = 1.0;
	float sum = 0.0;
	int flag = 1.0;
	for (; i <= 100; i++)
	{
		sum += flag / i;
		flag = -flag;
	}
	printf("sum = %f\n", sum);
}

void Test8()
{
	Sum();
}