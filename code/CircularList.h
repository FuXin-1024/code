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

//判断是否有环，定义快慢两个指针，如果相遇就有环
bool IsExitLoop(ListNode* phead)
{
	ListNode* fast = phead;
	ListNode* slow = phead;

	while (fast && fast->_next)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast == slow)
			break;
	}
	return !((fast == NULL) || (fast->_next == NULL));
}

void CircularListTest()
{
	ListNode* phead1 = new ListNode(1);
	ListNode* Node1 = new ListNode(3);
	phead1->_next = Node1;
	ListNode* Node2 = new ListNode(5);
	Node1->_next = Node2;
	ListNode* Node3 = new ListNode(7);
	Node2->_next = Node3;
	Node3->_next = NULL;
	cout<<IsExitLoop(phead1)<<endl;
}