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
void  RemoveZero(string& str)
{
	if (str.empty())
		return ;
	char symbol =str[0];
	char *p = (char*)str.c_str();
	p++;
	while (*p == '0')
		p++;
	string ret;
	ret.resize(strlen(p) + 1);
	ret[0] = symbol;
	int count = 1;
	while (*p != '\0')
	{
		ret[count++] = *p;
		p++;
	}
	str = ret;
}
string mul(string left, char right)
{
	if (right == '0')
		return "+0";
	int l = left.size();
	int r = 1;

	string strRes;
	strRes.resize(l + 1, '0');
	int idx;
	int step = 0;//进位
	for (idx = 1; idx < l; idx++)
	{
		int tmp = (left[l - idx] - '0')*(right - '0');
		step = tmp / 10;
		tmp = tmp % 10;

		strRes[l - idx + 1] = tmp + (strRes[l - idx + 1] - '0') + '0';
		strRes[l - idx] = step + '0';
	}
	return strRes;
}
string StrMul(string left, string right)
{
	int l = left.size();
	int r = right.size();
	if (l < r)
	{
		left.swap(right);
		swap(l, r);
	}

	string strRes;
	strRes.resize(1);

	int idx = 1;
	for (; idx < l; idx++)
	{
		string tmp = mul(right, left[l - idx]);
		for (int i = idx; i>1; i--)
		{
			tmp.append("0");
		}
		strRes = StrAdd(tmp, strRes);
	}
	if (left[0] != right[0])
		strRes[0] = '-';
	else
		strRes[0] = '+';
	/*string ret = RemoveZero(strRes);*/
	RemoveZero(strRes);
	return strRes;
}

string StrDiv(string left, string right)
{
	int l = left.size();
	int r = right.size();
	string strRes;
	strRes.resize(l);
	char symbol = '+';
	if (left[0] != right[0])
		symbol = '-';

	//符号统一
	left[0] = '+';
	right[0] = '+';

	int ret = 1;
	int idx = 1;
	string data("+");
	for (; idx < l; idx++)
	{
		data.push_back(left[idx]);
		if (!IsLeftBig(data, right))
		{
			strRes[ret++] = '0';
			continue;
		}
		int count = 0;
		while (1)
		{
			if (!IsLeftBig(data, right))  //左操作数小
			{
				break;
			}
			count++;
			data = StrSub(data, right);
			RemoveZero(data);
		}
		//走到这，确定了商的一位;
		strRes[ret++] = count + '0';
		if (data == "+0")  //处理掉，余数是零的情况，"+0" -->"+"  达到重置Ldata 的作用;
			data.resize(1);
	}
	strRes[0] = symbol;
	RemoveZero(strRes);
	return strRes;
}
int main()
{
	string left = "-3456";
	string right = "+89";
	string ret = StrDiv(left, right);
	

	system("pause");
	return 0;
}