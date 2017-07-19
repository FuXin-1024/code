#pragma once
#include<iostream>
#include<string.h>
using namespace std;

char FindSecondChar(char* str)
{
	int len = strlen(str);
	char arr[256] = { 0 };
	memset(arr, '0', 256);
	//计算str中每个字符出现的个数
	for (int i = 0; i < len; ++i)
	{
		//遍历str1，每一位的字符给相应的ASCII码中位置+1
		arr[*(str + i)] += 1;
	}
	//查找第一个只出现两次的字符
	for (int j = 0; j < 256; ++j)
	{
		if (arr[*(str + j)] == '2')
			return *(str + j);
	}
	return NULL;
}

void FindSecondCharTest()
{
	char str[] = "abcdefabcdefabc";
	cout << FindSecondChar(str) << endl;
}