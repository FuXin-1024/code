#pragma once
#include<stdlib.h>
#include<stdio.h>

//����1!+2!.....+n!
//����C���Կ����⣡������������������������������

const int N = 4;
void Test13()
{
	int sum = 1;
	int sum1 = 0;
	int i = 1;
	for (; i <= N; i++)
	{
		sum *= i;
		sum1 += sum;
	}
	printf("%d != %d\n", N, sum1);
}