#pragma once
#include<iostream>
#include<vector>
using namespace std;

//����ʵ��һ���򵥵��ַ����滻������ԭ������Ҫ�滻��ռλ��Ϊ"%s",�밴�ղ����б��˳��һһ�滻ռλ�����������б���ַ�������ռλ����������ʣ�µĲ����ַ���ӵ��ַ����Ľ�β��
//����һ���ַ���A��ͬʱ�������ĳ���n�������ַ�����arg�����Ĵ�Сm���뷵���滻����ַ�������֤�����������ڵ���ռλ����������֤ԭ���ɴ�СдӢ����ĸ��ɣ�ͬʱ����С�ڵ���500��

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