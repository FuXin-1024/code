#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
//折半查找

int binsearch(int x, int arr[], int left,int right)
{
	int mid;//中间位置
	assert(left < right);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (x == arr[mid])
			return mid;
		else if (arr[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
//递归
int R(int x, int arr[], int left, int right)
{
	if (left > right)
		return -1;
	int mid = (left + right) / 2;
	if (x == arr[mid])
		return mid;
	else if (arr[mid] < x)
		R(x, arr, mid + 1, right);
	else
		R(x, arr, left, mid-1);
}
void Test14()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
	int ret0 = R(0, arr, 0, 9);
	int ret1 = R(1, arr, 0, 9);
	int ret2 = R(2, arr, 0, 9);
	int ret3 = R(3, arr, 0, 9);
	int ret4 = R(4, arr, 0, 9);
	int ret5 = R(5, arr, 0, 9);
	int ret6 = R(6, arr, 0, 9);
	int ret7 = R(7, arr, 0, 9);
	int ret8 = R(8, arr, 0, 9);
	int ret9 = R(9, arr, 0, 9);
	int ret = R(-7, arr, 0, 9);

	printf("ret0 = %d\n", ret0);
	printf("ret1 = %d\n", ret1);
	printf("ret2 = %d\n", ret2);
	printf("ret3 = %d\n", ret3);
	printf("ret4 = %d\n", ret4);
	printf("ret5 = %d\n", ret5);
	printf("ret6 = %d\n", ret6);
	printf("ret7 = %d\n", ret7);
	printf("ret8 = %d\n", ret8);
	printf("ret9 = %d\n", ret9);
	printf("ret = %d\n", ret);


}