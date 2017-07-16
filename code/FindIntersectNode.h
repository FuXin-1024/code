#pragma once
#include<iostream>
using namespace std;

struct ListNode
{
	int _value;
	ListNode* _next;

	ListNode(const int x)
		:_value(x)
		, _next(NULL)
	{}
};

//不带环
ListNode* FindIntersectNode(ListNode* phead1, ListNode* phead2)
{
	if (phead1 == NULL || phead2 == NULL)
		return NULL;
	int len1 = 1; //链表1的长度
	int len2 = 1; //链表2的长度
	ListNode* node1 = phead1;
	ListNode* node2 = phead2;

	while (node1->_next)
	{
		node1 = node1->_next;
		len1++;
	}

	while (node2->_next)
	{
		node2 = node2->_next;
		len2++;
	}

	if (node1 != node2) //相交的链表，尾节点一定相同
		return NULL;
	int n = abs(len1 - len2); //两个链表的程度的差
	node1 = phead1;
	node2 = phead2;
	if (len1 > len2)   //让长的链表先走n步
	{
		for (int i = 0; i < n; i++)
			node1 = node1->_next;
	}
	else
	{
		for (int i = 0; i < n; i++)
			node2 = node2->_next;
	}

	while (node1 != node2)
	{
		node1 = node1->_next;
		node2 = node2->_next;
	}
	return node1;
}

void FindIntersectNodeTest()
{
	ListNode* phead1 = new ListNode(1);
	ListNode* Node1 = new ListNode(3);
	phead1->_next = Node1;
	ListNode* Node2 = new ListNode(5);
	Node1->_next = Node2;
	ListNode* Node3 = new ListNode(7);
	Node2->_next = Node3;
	Node3->_next = NULL;
	

	ListNode* phead2 = new ListNode(2);
	ListNode* Node4 = new ListNode(4);
	phead2->_next = Node4;
	ListNode* Node5 = new ListNode(6);
	Node4->_next = Node5;
	ListNode* Node6 = new ListNode(8);
	Node5->_next = Node6;
	Node6->_next = Node2;
	ListNode* node = FindIntersectNode(phead1, phead2);
	cout << node->_value << endl;
}