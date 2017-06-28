#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//打印乘法口诀表
void Print()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d * %d = %d  ", j, i, i*j);
		}
		printf("\n");
	}
}

void Test2()
{
	Print();
}