#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

//ʵ��һ��ջ��Ҫ��Push����ջ����Pop����ջ����Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO��1��

//˼·��ʹ��һ��ջ��Ԫ��x��ջʱ��ִ��һ��push��x������push��min����min��ʾ��ǰջ����ջ��Ԫ����Сֵ��
//Ԫ�س�ջʱ��ִ������pop���� 
template<class T>
class Stack
{
public:
	void Push(const int x)
	{
		int min = x;
		if (s.empty())
		{
			s.push(x);
			s.push(min);
		}
		else
		{
			if (x < s.top())
				min = x;
			else
				min = s.top();
			s.push(x);
			s.push(min);
		}
	}

	void Pop()
	{
		if (s.empty())
			return;
		s.pop();
		s.pop();
	}

	T Min()
	{
		return s.top();
	}
private:
	stack<T> s;
};

//ʹ������ջs1��s2��s2��Ϊ����ջ��ÿ��ѹ��s2�Ķ���s1����Сֵ����Ԫ��x��ջʱ����x��s2ջ��Ԫ�����Ƚϣ����xС�ڵ���s2.top��������x�ֱ�push��s1��s2������xֻpush��s1 
//Ԫ�س�ջʱ����s1ջ��Ԫ�غ�s2ջ��Ԫ�����Ƚϣ����s1.top��������s2.top������s1��s2��ִ��pop����������ִֻ��s1.pop����

template <class T>
class Stack1
{
public:
	void Push(const int x)
	{
		s1.push(x);
		if (s2.empty() || x <= s2.top())
		{
			s2.push(x);
		}
	}

	void Pop()
	{
		if (s1.top() == s2.top())
			s2.pop();
		s1.pop();
	}

	T  Min()
	{
		return s2.top();
	}
private:
	stack<T> s1;
	stack<T>s2;
};
void StackTest()
{
	Stack<int> s;
	s.Push(5);
	s.Push(2);
	s.Push(4);
	s.Push(1);
	cout << s.Min() << endl;
	s.Pop();
	cout << s.Min() << endl;
}