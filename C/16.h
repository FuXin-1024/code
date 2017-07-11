#pragma once
#pragma warning(disable:4996)
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

//从 src 数组起始位置向后偏移 start个字符的位置开始，最多
//复制 len 个非NULL字符到 dst数组。在复制完毕之后， dst 数组必须以
//NUL字节结尾。函数的返回值是存储于 dst 数组中的字符串的长度。
int substr(char dst[], char src[], int start, int len)
{
	char* sc = src + start;
	int i = 0;
	int ret = 0;
	int n = strlen(sc);
	if (n < len)
		len = n;
	while (len)
	{
		dst[i] = sc[i];
		len--;
		i++;
		
	}
	dst[i] = '\0';
	ret = strlen(dst);
	return ret;
}

void Test16()
{
	char dst[100];
	char src[] = "1234 56789";
	int ret = substr(dst, src, 3, 5);
	printf("%d\n", ret);
	printf("%d\n", strlen(dst));
	printf("%s\n", dst);
}