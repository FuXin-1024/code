#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

//实现一个栈，要求Push（入栈），Pop（出栈），Min（返回最小值的操作）的时间复杂度为O（1）

//思路：使用一个栈。元素x入栈时，执行一次push（x），再push（min），min表示当前栈顶到栈底元素最小值；
//元素出栈时，执行两次pop（） 
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

//使用两个栈s1和s2，s2做为辅助栈（每次压入s2的都是s1的最小值）。元素x入栈时，将x和s2栈顶元素做比较，如果x小于等于s2.top（），将x分别push到s1和s2，否则x只push到s1 
//元素出栈时，将s1栈顶元素和s2栈顶元素做比较，如果s1.top（）等于s2.top（），s1和s2都执行pop操作，否则只执行s1.pop（）

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