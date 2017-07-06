#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<Windows.h>
//编写代码，演⽰多个字符从两端移动，向中间汇聚

void Print()
{
	char buf[80] = "################";
	char src[] = "Hello everyone!!";
	int i, j;
	printf("%s\n", buf);
	for (i = 0, j = strlen(src) - 1; i <= j; i++, j--)
	{
		buf[i] = src[i];
		buf[j] = src[j];
		Sleep(1000);
		printf("%s\n", buf);
	}
}

void Test10()
{
	Print();
}