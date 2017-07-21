#pragma once
#include<iostream>
using namespace std;

int countFactorialZero(int N)
{
	int ret = 0;
	int j = 0;
	for (int i = 1; i <= N; ++i)
	{
		 j = i;
		 while (j % 5 == 0)
		 {
			 ret++;
			 j /= 5;
		 }
	}
	return ret;
}

void countFactorialZeroTest()
{
	int n = 10;
	cout << countFactorialZero(n);
}