#pragma once
#include<stdlib.h>
#include<stdio.h>

//���һ��������ÿһλ

void Print(int n)
{
	int res = 0;
	printf("%d ��ÿһλΪ:  ", n);
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