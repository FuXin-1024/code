#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

char* ReplaceBlank(char* str)
{
	char* front = str;
	int count = 0; //统计空格字数
	while (*front != '\0')
	{
		if (*front == ' ')
			count++;
		++front;   //front指向数组的最后一个元素'\0'
	}
	char* back = front + count*(3 - 1);
	//开始进行从后往前替换
	while (back > front)
	{
		//遇到空格替换，front往前走一步，back往前走三步
		if (*front == ' ')
		{
			*back-- = '$';
			*back-- = '$';
			*back-- = '$';
			--front;
		}
		else
		{
			//没遇到空格，依次复制
			*back-- = *front--;
		}
	}
	return str;
}
void ReplaceBlankTest()
{
	char str1[50] = "We are happy.";
	cout << ReplaceBlank(str1) << endl;
}