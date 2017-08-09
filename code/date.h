#pragma once
#include<iostream>

using namespace std;

void Time(int n)
{
	int second = 0;
	int min = 0;
	int hour = 0;
	int day = 1;
	int month = 1;
	int year = 1970;

	second = n % 60;

	min = n / 60;
	while (min > 60)
	{
		min = min % 60;
	}

	hour = n / (60 * 60);
	while (hour > 24)
	{
		hour %= 24;
	}

	day =day + n / (24 * 60 * 60);
	while (day > 30)
	{
		day = day % 30;
	}

	month = month + n / (30 * 24 * 60 * 60);
	while (month > 12)
	{
		month = month % 30;
	}

	year = year + n / (12 *30 * 24 * 60 * 60);

	cout << year << "年" << month << "月" << day << "日" << " ";

	
	cout <<hour<<"时"<< min << "分" << second << "秒" << endl;
}

void TimeTest()
{
	int n = 10;
	Time(n);
}