#pragma once
#include<stdlib.h>
#include<stdio.h>

//编写程序数⼀下 1到 100 的所有整数中出现多少次数字9

void count_nine()
{
	int num = 1;
	int count = 0;
	for (; num <= 100; num++)
	{
		if (num % 10 == 9)
			count++;
		if (num / 10 == 9)
			count++;
	}
	printf("count = %d\n", count);
}

void Test9()
{
	count_nine();
}