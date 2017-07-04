/*************************************************************************
	> File Name: 5.c
	> Author: fx
	> Mail: 1007160080qq.com 
	> Created Time: Tue 04 Jul 2017 09:05:53 AM PDT
 ************************************************************************/
//求10个数中的最大值
#include<stdio.h>
#include<stdlib.h>

int Max(int* a,int len)
{
	int tmp = a[0];
	int i = 1;
	for(;i<len;i++)
	{
		if(tmp <  a[i])
			tmp = a[i];
	}
	return tmp;
}
int main()
{
	int a[] = {3,6,2,1,9,7,8,4,10,15};
	int i = 0;
	int len = sizeof(a)/sizeof(a[0]);
	int ret = 0;
	for( i = 0;i<len;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	ret = Max(a,len);
	printf("The max is:%d\n",ret);
	return 0;
}
