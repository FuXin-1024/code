#pragma once
#include<stdlib.h>
#include<stdio.h>

//  2/1+3/2+5/3+8/5+13/8+��
void Test17()
{
	double i = 2;//���� = �ϸ����ķ��Ӽӷ�ĸ
	double j = 1;//��ĸ = �ϸ����ķ���
	int n = 0;
	double sum = 0.0;
	for (; n < 20; n++) //ǰ20��ĺ�
	{
		sum += i / j;
		int tmp = i;
		i = i + j;
		j = tmp;
	}
	printf("ǰ %d ��Ϊ %f;\n", n, sum);
}
