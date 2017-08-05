#include<iostream>
#include<vector>
using namespace std;

char* Remove(char str[], int len)
{
	vector<int> v;
	int flag = 1;
	int in[10];
	int k = 0;
	char *ret=new char[len];
	int m = 0;

	for (int i = len - 1; i > 0;i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (str[i] == str[j])
			{
				in[k++] = j;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (in[j] == i)
			{
				flag = 1;
				break;
			}
			else
				flag = 0;
		}
		if (!flag)
		{
			ret[m] = str[i];
			m++;
		}
	}
	ret[m++] = '\0';

	return ret;
	/*int index1 = 0; int index2 = 0;
	while (*ret != '\0')
	{
		str[index1] = ret[index2];
		index1++;
		index2++;
	}
		
	str[index1++] = '\0';*/
}

void RemoveTest()
{
	char* arr = { "bbcacdww" };
	int len = strlen(arr);
	arr=Remove(arr, len);
}