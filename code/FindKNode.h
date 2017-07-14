#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//查找单链表倒数第k个节点
//使用快慢指针
struct ListNode
{
	int _value;
	ListNode* _next;

	ListNode(const int x)
		:_value(x)
		, _next(NULL)
	{}
};
int ListSize(ListNode* phead)
{
	int size = 0;
	if (phead == NULL)
		return size;
	
	ListNode* cur = phead;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

ListNode* FindKNode(ListNode* phead, int k)
{
	assert(phead);
	assert(k <= ListSize(phead));

	ListNode* slow = phead;
	ListNode* fast = phead;
	while (k)
	{
		fast = fast->_next;
		k--;
	}
	while (fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	return slow;
}

void FindKNodeTest()
{
	ListNode* phead1 = new ListNode(1);
	ListNode* Node1 = new ListNode(3);
	phead1->_next = Node1;
	ListNode* Node2 = new ListNode(5);
	Node1->_next = Node2;
	ListNode* Node3 = new ListNode(7);
	Node2->_next = Node3;
	Node3->_next = NULL;
	ListNode* head = FindKNode(phead1, 6);
}