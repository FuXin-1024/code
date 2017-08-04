#include<iostream>
using namespace std;

#define SIZE 65536

void RangeSort(int* arr, int len)
{
	int data[SIZE];
	memset(data, 0, SIZE*sizeof(int));

	for (int i = 0; i < len; i++)
	{
		data[arr[i]]++;
	}
	int i = 0;
	int j = 0;
	int count= 0;
	for (; j < SIZE; j++)
	{
		if (data[j] != 0)
		{
			arr[i++] = j;
			count++;
		}
		if (count == len)
			return;
	}
}


void RangeSortTest()
{
	int arr[] = { 3, 1, 5, 2, 8, 7, 9, 0, 6, 4 };
	RangeSort(arr, sizeof(arr) / sizeof(arr[0]));
}