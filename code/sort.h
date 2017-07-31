#include<iostream>
using namespace std;

void InsertSort(int* arr, int len)//ÉıĞòÅÅÁĞ
{
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
void Test()
{
	int arr[] = { 5 ,8, 9, 4 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
}