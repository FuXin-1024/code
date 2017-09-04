#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int evalRPN(vector<string> &tokens)
{
	stack<int> s;//¸¨ÖúÕ»
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i] == "+")
		{
			int l = s.top();
			s.pop();
			int r = s.top();
			s.pop();
			s.push(l + r);
		}
		else if (tokens[i] == "-")
		{
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();
			s.push(l - r);
		}
		else if (tokens[i] == "*")
		{
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();
			s.push(l * r);
		}
		else if (tokens[i] == "/")
		{
			int r = s.top();
			s.pop();
			int l = s.top();
			s.pop();
			s.push(l / r);
		}
		else
		{
			s.push(atoi(tokens[i].c_str()));
		}
	}
	return s.top();
}

int main()
{
	system("pause");
	return 0;
}