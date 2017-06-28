#pragma once
#include<stdlib.h>
#include<stdio.h>
//打印1000-1000年之间的闰年
int Print()
{
	int count=0;
	for (int i = 1000; i <= 2000; ++i)
	{
		if ((i % 400==0) || (i % 4 == 0 && i % 100 != 0))
		{
			printf("%d\t", i);
			count++;
		}
	}
	printf("\n");
	printf("一共有%d年\n", count);
}

void Test3()
{
	Print();
}
