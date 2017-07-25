#pragma once
#include<iostream>
#include<vector>
using namespace std;

//一个m*n的矩阵，从左到右从上到下都是递增的，给一个数x，判断x是否在矩阵中。要求效率尽可能的高。

bool FindX(int arr[][4],int n, int x)
{
	int row = 0;
	int col = n - 1;
	while (row >= 0 && col >= 0)
	{
		if (x < arr[row][col])
			col--;
		else if (x>arr[row][col])
			row++;
		else
			return true;
	}
	return false;
}

void FindXTest()
{
	int arr[][4] = { { 1, 3, 5, 7 }, 
					{ 2, 4, 8, 16 }, 
					{ 4, 9, 10, 20 }, 
					{ 8, 11, 15, 21 } };
	cout << FindX(arr,4,4) << endl;
}