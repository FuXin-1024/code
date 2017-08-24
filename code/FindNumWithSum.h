#include<iostream>
using namespace std;

//输入一个数组和一个数s，在数组中查找两个数，使得他们的和为s.

bool FindNumWithSum(int* data, int len, int sum, int& num1, int& num2)
{
	bool found = false;
	if (data == NULL || len < 1)
		return found;
	int  start = 0;
	int last = len - 1;

	while (start < last)
	{
		long long tmp = data[start] + data[last];
		if (tmp == sum)
		{
			num1 = data[start];
			num2 = data[last];
			found = true;
			break;
		}
		else if (tmp < sum)
			start++;
		else
			last--;
	}
	return found;
}

//输入一个正数s，打印出所有和为s的连续正数序列。
//输入15，  1+2+3+4+5=4+5+6=7+8=15

void PrintFindSeq(int samll, int big)
{
	for (int i = samll; i <= big; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}


void FindSeq(int sum)
{
	if (sum < 3)
		return;
	int small = 1;
	int big = 2;
	int mid = (1 + sum) / 2;
	int curSum = small + big;

	while (small < mid)
	{
		if (curSum == sum)
			PrintFindSeq(small, big);
		while (curSum>sum && small < mid)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
				PrintFindSeq(small, big);
		}
		big++;
		curSum += big;
	}
}

void Test()
{
	int data[] = { 1, 2, 4, 7, 11, 15 };
	int num1, num2;
	if (FindNumWithSum(data, sizeof(data) / sizeof(data[0]), 15, num1, num2))
	{
		cout << "num1 = " << num1 << endl;
		cout << "num2 = " << num2 << endl;
	}
	else
		cout << "Not found!" << endl;

	int sum = 15;
	FindSeq(sum);
}