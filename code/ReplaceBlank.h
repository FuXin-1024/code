#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

char* ReplaceBlank(char* str)
{
	char* front = str;
	int count = 0; //ͳ�ƿո�����
	while (*front != '\0')
	{
		if (*front == ' ')
			count++;
		++front;   //frontָ����������һ��Ԫ��'\0'
	}
	char* back = front + count*(3 - 1);
	//��ʼ���дӺ���ǰ�滻
	while (back > front)
	{
		//�����ո��滻��front��ǰ��һ����back��ǰ������
		if (*front == ' ')
		{
			*back-- = '$';
			*back-- = '$';
			*back-- = '$';
			--front;
		}
		else
		{
			//û�����ո����θ���
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