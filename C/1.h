#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

//��100-200֮�������
int Prime(int n)
{
	int i = 2;
	for (; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void Test1()
{
	int count = 0;
	for (int i = 100; i <= 200; ++i)
	{
		if (Prime(i))
		{
			printf("%d\t", i);
			count++;
		}	
	}
	printf("\n");
	printf("100-200֮�乲��%d������\n", count);
}
