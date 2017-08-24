#include<iostream>
using namespace std;

//数字在排序数组中出现的次数

int GetFirstK(int* a, int len, int k, int start, int end)
{
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	int midData = a[mid];

	if (midData == k)
	{
		if ((mid > 0 && a[mid - 1] != k) || (mid == 0))
			return mid;
		else
			end = mid - 1;
	}
	else if (midData > k)
		end = mid - 1;
	else
		start = mid + 1;

	return GetFirstK(a, len, k, start, end);
}

int GetLastK(int* a, int len, int k, int start, int end)
{
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	int midData = a[mid];

	if (midData == k)
	{
		if ((mid < len - 1 && a[mid + 1] != k) || mid == len - 1)
			return mid;
		else
			start = mid + 1;
	}
	else if (midData < k)
		start = mid + 1;
	else
		end = mid - 1;

	return GetLastK(a, len, k, start, end);
}

int GetNumOfK(int* a, int len, int k)
{
	int ret = 0;
	if (a != NULL && len > 0)
	{
		int first = GetFirstK(a, len, k, 0, len - 1);
		int last = GetLastK(a, len, k, 0, len - 1);

		if (first > -1 && last > -1)
			ret = last - first + 1;
	}
	return ret;
}

void Test()
{
	int a[] = { 1, 2, 3, 3, 3, 4, 5 };
	int ret = 0;
	ret = GetNumOfK(a, sizeof(a) / sizeof(a[0]), 4);
	cout << ret << endl;
}