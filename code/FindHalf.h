#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�

int FindHalf(int* arr, int len)
{
	assert(arr);
	assert(len > 0);
	int count = 0;
	int cur = 0;
	for (int i = 0; i < len; ++i)
	{
		if (count == 0)
		{
			cur = arr[i];
			count = 1;
		}
		else if (arr[i] == cur)
			count++;
		else
			count--;
	}
	return cur;
}

void FindHalfTest()
{
	int arr[] = { 1, 2, 2, 2, 3, 2, 6, 2, 7, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << FindHalf(arr, len) << endl;
}