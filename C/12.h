#pragma once
#include<stdlib.h>
#include<stdio.h>

//¼ÆËãNµÄ½×³Ë

int  Print(int n)
{
	int sum = 1;
	int i = 1;
	for (; i <= n; i++)
		sum *= i;
	return sum;
}

void Test12()
{
	int n = 4;
	int ret = Print(n);
	printf("%d! = %d\n", n, ret);
}