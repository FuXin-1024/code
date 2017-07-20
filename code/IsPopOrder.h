#pragma once
#include<iostream>
#include<stack>
using namespace std;

bool IsPopOrder(const int dataPush[], int len1, const int dataPop[], int len2)
{
	if (dataPush == NULL || dataPop == NULL || len1 != len2 || len1 <= 0)
		return false;
	int len = len1;
	const int* cur = dataPop;
	stack <int> stackData;
	for (int i = 0; i < len; ++i)
	{
		stackData.push(dataPush[i]);
		while (stackData.size() != 0 && stackData.top() == *cur)
		{
			stackData.pop();
			++cur;
		}
	}
	if (stackData.empty())
		return true;
	return false;
}

void IsPopOrderTest()
{
	int dataPush[] = { 1, 2, 3, 4, 5 };
	int dataPop[] = { 4, 5, 2, 3, 1, };
	int len1 = sizeof(dataPush) / sizeof(dataPush[0]);
	int len2 = sizeof(dataPop) / sizeof(dataPop[0]);

	cout << IsPopOrder(dataPush, len1, dataPop, len2);
}