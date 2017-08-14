#include<assert.h>  
#pragma once 
#include<iostream>  
using namespace std;

enum Status
{
	valid = 1,
	invalid = 0
};

int flag = valid;
int StrToInt(const char* str)
{
	assert(str);
	long long ret = 0;

	int symbol = 1;//ÓÃÓÚÅĞ¶Ï·ûºÅ
	if (*str == '\0')
	{
		flag = invalid;
		return 0;
	}

	//È¥µô¿Õ¸ñ£¬ÖÆ±í·û
	while (isspace(*str))
	{
		str++;
	}

	//ÅĞ¶Ï·ûºÅ
	if (*str == '-')
	{
		symbol = -1;
		str++;

		if ((*str < '0') || (*str>'9'))
		{
			flag = invalid;
			return 0;
		}
	}
	else if (*str == '+')
	{
		str++;
	}
	else if ((*str<'0') || (*str >'9'))
	{
		flag = invalid;
		return 0;
	}
	while ((*str != '\0') && (*str >= '0') && (*str <= '9'))
	{
		ret = ret * 10 + *str - '0';
		str++;
	}

	if (((ret > 0x7fffffff) && (symbol)) ||
		(ret < (signed int)0x00000000) && (symbol == -1))
	{
		flag = invalid;
		return 0;
	}
	flag = valid;
	return ret;
}