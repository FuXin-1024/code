#pragma once
#include<stdlib.h>
#include<stdio.h>

//不允许创建临时变量，交换两个数的内容
void Swap(int* a, int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

void Test4()
{
	int a = 1;
	int b = 4;
	printf("before: a = %d, b = %d\n", a, b);
		Swap(&a, &b);
	printf("after: a = %d, b = %d\n", a, b);
}