#include<iostream>
using namespace std;

//数组中只出现一次的数字

//整数num的二进制中找到最右边是1的位
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

//判断num的二进制表示中从右边数起的indexBit是不是1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void FindNumAppearOnce(int *data, int len, int& num1, int& num2)
{
	if (data == NULL || len < 2)
		return;

	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret ^= data[i];
	}
	unsigned int indexOf1 = FindFirstBitIs1(ret);
	num1 = num2 = 0;

	for (int j = 0; j < len; j++)
	{
		if (IsBit1(data[j], indexOf1))
			num1 ^= data[j];
		else
			num2 ^= data[j];
	}
}

void Test()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int num1, num2;
	FindNumAppearOnce(data, sizeof(data) / sizeof(data[0]), num1, num2);
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

}