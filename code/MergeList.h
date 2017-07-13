#pragma once
#include<iostream>
using namespace std;

//合并两个有序链表
struct ListNode
{
	int _value;
	ListNode* _next;
	ListNode(int x)
		:_value(x)
		, _next(NULL)
	{}
};

ListNode* MergeList(ListNode* phead1, ListNode* phead2)
{
	if (phead1 == NULL)
		return phead2;
	if (phead2 == NULL)
		return phead1;
	ListNode* newhead = NULL;

	if (phead1->_value < phead2->_value)
	{
		newhead = phead1;
		newhead->_next = MergeList(phead1->_next, phead2);
	}
	else
	{
		newhead = phead2;
		newhead->_next = MergeList(phead1, phead2->_next);
	}
	return newhead;
}

void MergeListTest()
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
	Node6->_next = NULL;

	ListNode* phead = MergeList(phead1, phead2);
	
}