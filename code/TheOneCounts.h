#pragma once
#include<iostream>
using namespace std;

int TheOneCounts(int num)
{
	int count = 0;
	unsigned int flag = 1;
	while(flag)
	{
		if (num & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}
void TheOneCountsTest()
{
	int num = -7;
	cout << TheOneCounts(num) << endl;
}