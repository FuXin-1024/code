#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//反转链表，三个指针
struct ListNode
{
	int _value;
	ListNode* _next;

	ListNode(int x)
		:_value(x)
		, _next(NULL)
	{}
};

ListNode* ReverseList(ListNode* phead)
{
	assert(phead);

	ListNode* Rhead = NULL;
	ListNode* cur = phead;
	ListNode* prev = NULL;
	ListNode* next = NULL;

	while (cur)
	{
		ListNode* next = cur->_next; //提前保存cur的下一个节点
		if (next == NULL)
			Rhead = cur;
		cur->_next = prev;
		
		prev = cur;
		cur = next;
	}
	return Rhead;
}

ListNode* getLastNode(ListNode* pHead) {
	while (NULL != pHead->_next)
		pHead = pHead->_next;
	return pHead;
}
ListNode* swapListByK(ListNode* pHead, int k) 
{
	if (k <= 1)
		return pHead;
	int pos;
	ListNode* pNode = pHead;
	ListNode* pNewHead;
	ListNode* pNextNode;
	ListNode* pLastNode = NULL;;
	pHead = NULL;
	while (pNode) {
		pos = 0;
		pNewHead = pNode;
		while (pNode && pos < k - 1) {
			pNode = pNode->_next;
			pos++;
		}
		if (pNode) {
			pNextNode = pNode->_next;
			pNode->_next = NULL;
			if (NULL != pLastNode) {
				pLastNode->_next = NULL;
			}
			pNewHead = ReverseList(pNewHead);
			if (NULL == pHead) {
				pHead = pNewHead;
			}
			else {
				pLastNode->_next = pNewHead;
			}
			pNode = getLastNode(pNewHead);
			pNode->_next = pNextNode;
			pLastNode = pNode;
			pNode = pNextNode;
		}
		else {
			break;
		}
	}
	return pHead;
}
//1->2->3->4   1->3->2->4   1->4->3->2  4->3->2->1
ListNode* ReverseList1(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->_next;
	ListNode* next = NULL;
	while (cur && cur->_next)
	{
		next = cur->_next;
		cur->_next = next->_next;
		next->_next = phead->_next;
		phead->_next = next;
	}
	if (cur && cur->_next)
	{
		cur->_next = phead;
		phead = cur->_next->_next;
		cur->_next->_next = NULL;
	}
	
	return phead;
}

void RListTest()
{

	ListNode* phead1 = new ListNode(1);
	ListNode* Node1 = new ListNode(2);
	phead1->_next = Node1;
	ListNode* Node2 = new ListNode(3);
	Node1->_next = Node2;
	ListNode* Node3 = new ListNode(4);
	Node2->_next = Node3;
	ListNode* Node4 = new ListNode(5);
	Node3->_next = Node4;
	ListNode* Node5 = new ListNode(6);
	Node4->_next = Node5;
	Node5->_next = NULL;
	ListNode* head = swapListByK(phead1,3);
}

