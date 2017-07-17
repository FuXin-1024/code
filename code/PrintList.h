#pragma once
#include<iostream>
#include<stack>
using namespace std;

//从尾到头打印单链表
struct ListNode
{
	int _value;
	ListNode* _next;

	ListNode(const int x)
		:_value(x)
		, _next(NULL)
	{}
};
void PrintTtoH(ListNode* phead)
{
	if (phead != NULL)
	{
		PrintTtoH( phead->_next);
		cout << phead->_value << " ";
	}
}

void PrintTtoH1(ListNode* phead)
{
	if (phead == NULL)
		return;
	stack<ListNode*> s;
	while (phead)
	{
		s.push(phead);
		phead = phead->_next;
	}
	while (!s.empty())
	{
		cout << s.top()->_value << " ";
		s.pop();
	}
}

void PrintTtoHTest()
{
	ListNode* phead1 = new ListNode(1);
	ListNode* Node1 = new ListNode(3);
	phead1->_next = Node1;
	ListNode* Node2 = new ListNode(5);
	Node1->_next = Node2;
	ListNode* Node3 = new ListNode(7);
	Node2->_next = Node3;
	Node3->_next = NULL;

	PrintTtoH1(phead1);
}