#pragma once
#include<stdlib.h>
#include<stdio.h>

//输出一个整数的每一位

void Print(int n)
{
	int res = 0;
	printf("%d 的每一位为:  ", n);
	while (n != 0)
	{
		res = n % 2;
		n = n / 2;
		printf("%d ", res);
	}
	printf("\n");
}

void Test7()
{
	int n = 8;
	Print(n);
}