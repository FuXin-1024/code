#pragma once
#include<iostream>
#include<vector>
using namespace std;

//һ��m*n�ľ��󣬴����Ҵ��ϵ��¶��ǵ����ģ���һ����x���ж�x�Ƿ��ھ����С�Ҫ��Ч�ʾ����ܵĸߡ�

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