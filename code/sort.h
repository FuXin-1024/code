#include<iostream>
#include<assert.h>
using namespace std;

//直接插入排序
void InsertSort(int* arr, int len)//升序排列
{
	assert(arr);
	assert(len > 0);
	for (int i = 1; i <len; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		
		while (j>=0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void ShellSort(int* arr, int len)
{
	assert(arr);
	assert(len);

	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < len; i++)
		{
			int end = i - gap;
			int temp = arr[i];

			while (end >= 0)
			{
				if (arr[end] < temp)
					break;

				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = temp;
		}
	}
}
void Test()
{
	int arr[] = { 5 ,8, 9, 4 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	int arr1[] = { 3, 1, 5, 2, 8, 7, 9, 0, 6, 4 };
	ShellSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
}