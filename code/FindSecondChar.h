#pragma once
#include<iostream>
#include<string.h>
using namespace std;

char FindSecondChar(char* str)
{
	int len = strlen(str);
	char arr[256] = { 0 };
	memset(arr, '0', 256);
	//����str��ÿ���ַ����ֵĸ���
	for (int i = 0; i < len; ++i)
	{
		//����str1��ÿһλ���ַ�����Ӧ��ASCII����λ��+1
		arr[*(str + i)] += 1;
	}
	//���ҵ�һ��ֻ�������ε��ַ�
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