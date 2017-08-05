#include<iostream>
#include<assert.h>
using namespace std;

//将N个字符的数组，循环右移K位。时间复杂度O(N)。 
void Reverse(int* arr, int start, int end)
{
	int temp = 0;
	for (int i = 0; i < (end - start + 1) / 2; i++)
	{
		temp = arr[start + i];
		arr[start + i] = arr[end - i];
		arr[end - i] = temp;
	}
}

void RightShift(int *arr, int len, int k)
{
	Reverse(arr, 0, len - k - 1); //将数组前n - k个数逆置（0~n - k）
	Reverse(arr, len - k, len - 1);//将数组后k个数逆置（n-k~n-1）
	Reverse(arr, 0, len - 1);//将整个数组逆置
}

void RightShiftTest()
{
	int arr[] = { 3, 1, 5, 2, 8, 7, 9, 6, 4, 0 };
	RightShift(arr, sizeof(arr) / sizeof(arr[0]),3);
}