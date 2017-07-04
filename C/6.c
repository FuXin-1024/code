/*************************************************************************
	> File Name: 6.c
	> Author: fx
	> Mail: 1007160080qq.com 
	> Created Time: Tue 04 Jul 2017 09:25:15 AM PDT
 ************************************************************************/
//写一个函数返回参数二进制中1的个数
// 例如： 15 0000 1111   4个1
#include<stdio.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	while(value != 0)
	{
		if(value % 2 == 1)
			count++;
		value/=2;
	}
	return count;

}

int main()
{
	int value = 15;
	int ret = 0;
	ret = count_one_bits(value);
	printf("The one counts is:%d\n",ret);
	return 0;
}
