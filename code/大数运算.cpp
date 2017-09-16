#include<iostream>
#include<string>
using namespace std;

//同号相加
string StrAdd(string left, string right)
{
	int l = left.size();
	int r = right.size();

	//长度长的为左操作数
	if (l < r)
	{
		left.swap(right);
		swap(l, r);
	}
	string ret;
	ret.resize(l + 1);
	ret[0] = left[0];//同号相加，符号位相同
	int index = 0;
	char step = 0;//进位

	for (index = 1; index < l; index++)
	{
		char tmp = left[l - index] + step - '0';
		if (index < r)
			tmp = tmp + (right[r - index] - '0');
		step = 0;
		while (tmp >= 10)
		{
			step++;
			tmp -= 10;
		}
		ret[l - index + 1] = tmp + '0';
	}
	ret[1] = step + '0';
	return ret;
}

//判断左操作数是否大
bool IsLeftBig(string left, string right)
{
	if (left[0] == '+'&&right[0] == '-')
		return true;
	if (left[0] == '-'&&right[0] == '+')
		return false;

	int l = left.size();
	int r = right.size();

	if (left[0] == '+'&&right[0] == '+')
	{
		if (l > r)
			return true;
		else if (l == r)
		{
			if (left.compare(right) < 0)
				return false;
			else
				return true;
		}
		return false;
	}
	if (left[0] == '-'&&right[0] == '-')
	{
		if (l > r)
			return false;
		else if (l == r)
		{
			if (left.compare(right) < 0)
				return true;
			else
				return false;
		}
		return true;
	}
}

string Sub(string left, string right)
{
	char symbol = '-';
	if (IsLeftBig(left, right))
		 symbol = '+';

	int l = left.size();
	int r = right.size();
	
	//大的操作数为左操作数
	if (l < r)
	{
		left.swap(right);
		swap(l, r);
	}

	char ret = 0;//保存相减结果
	for (int idx = 1; idx < l; idx++)
	{
		char leftData = left[l - idx] - '0';
		char rightData = right[r - idx] - '0';
		char src = left[l - idx - 1];//借位
		if (idx < r&&leftData < rightData)
		{
			left [ l - idx - 1] = src - 1;
			ret = leftData + 10 - rightData + '0';
			left[l - idx] = ret;
		}
		else
		{
			if (idx < r)
				left[l - idx] = leftData - rightData + '0';
			else
				break;
		}
	}
	left[0] = symbol;
	return left;
}

string StrSub(string left, string right)
{
	if (left[0] == '-'&&right[0] == '+')// -8-7 = -15;
	{
		left[0] = '+';
		
		string ret = StrAdd(left, right);
		ret[0] = '-';
		return ret;
	}
	if (left[0] == '+'&&right[0] == '-')// 8-(-7) = 15;
	{
		right[0] = '+';

		string ret = StrAdd(left, right);
		ret[0] = '+';
		return ret;
	}
	else
	{
		string ret = Sub(left, right);//同号相减
		return ret;
	}
}
int main()
{
	string left = "-345";
	string right = "-89";
	string ret = StrSub(left, right);
	

	system("pause");
	return 0;
}