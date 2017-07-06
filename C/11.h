#pragma warning(disable:4996)
#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//编写代码实现，模拟⽤户登录情景，并且只能登录三次。
//只允许输⼊三次密码，如果密码正确则提⽰登录成，如果三次均输⼊错
//误，则退出程序。

void Test11()
{
	char psw[10] = "";
	int i = 0;
	int j = 0;
	for (; i < 3; i++)
	{
		printf("Please input:");
		gets(psw);
		if (strcmp(psw, "123456") == 0)
			break;
	}
	if (i == 3)
	{
		printf("psw is error\n");
		return;
	}
		
	else
		printf("log in\n");
}
