#pragma once
#include<iostream>
#include<vector>
using namespace std;

//请你实现一个简单的字符串替换函数。原串中需要替换的占位符为"%s",请按照参数列表的顺序一一替换占位符。若参数列表的字符数大于占位符个数。则将剩下的参数字符添加到字符串的结尾。
//给定一个字符串A，同时给定它的长度n及参数字符数组arg和它的大小m，请返回替换后的字符串。保证参数个数大于等于占位符个数。保证原串由大小写英文字母组成，同时长度小于等于500。

string formatString(string str, int n, vector<char> arg, int m)
{
	string ret;
	int cur = 0;
	if (str.empty() == true || arg.empty() == true) 
		return ret;
	while (str.find("%s") != string::npos)
	{
		ret += str.substr(0, str.find("%s"));
		ret += arg[cur++];
		str = str.substr(str.find("%s") + 2);
	}
	ret += str;
	for (; cur < arg.size(); cur++)
	{
		ret += arg[cur];
	}

	return ret;
}

void Test()
{
	string str("A%sC%sE");
	vector<char> s;
	s.push_back('B');
	s.push_back('D');
	s.push_back('F');
	
	string ret = formatString(str, str.size(), s, s.size());

}