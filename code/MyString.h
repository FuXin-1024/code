#pragma once
#pragma warning(disable:4996)
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(const char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//S3(S1)
	//传统写法
	/*MyString(const MyString& s)
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}
*/
	//现代写法
	MyString(const MyString& s)
		:_str(NULL)//f
	{
		MyString tmp(s._str);
		swap(_str, tmp._str);
	}
	//S3=S1   传统写法
	/*MyString& operator==(const MyString& s)
	{
		if (this != &s)
		{
			delete _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
	}*/

	//现代写法
	MyString& operator=(MyString s)
	{
		swap(_str, s._str);
		return *this;
	}

	~MyString()
	{
		delete[] _str;
	}

	char* GetChar()
	{
		return _str;
	}
private:
	char* _str;
};