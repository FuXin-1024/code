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

//第一次相遇时开始计时，第二次相遇时，即为环长度
int CircularLength(ListNode* phead)
{
	if (!IsExitLoop(phead)) //如果不带环，环的长度为0
		return 0;
	ListNode* fast = phead;
	ListNode* slow = phead;
	bool first = false;
	bool second = false;
	int len = 0;
	while (1)
	{
		fast = fast->_next->_next;
		slow = slow->_next;

		if (fast == slow && second == true)//第二次相遇跳出循环
			break;

		if (fast == slow && first == false)//第一次相遇,开始计数
		{
			first = true;
			second = true;
		}
		if(first == true)
			++len;
	}
	return len;
}

//环的入口点   相遇点到入口点的距离等于头结点到入口点的距离
ListNode* FindEntrance(ListNode* phead)
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
	if (fast == NULL && fast->_next == NULL)
		return NULL;
	
	//走到相遇点
	fast = phead;
	while (fast != slow)
	{
		fast = fast->_next;
		slow = slow->_next;
	}
	return slow;
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
	Node3->_next = Node1;
	cout<<IsExitLoop(phead1)<<endl;
	cout << "len = " << CircularLength(phead1) << endl;
	cout << FindEntrance(phead1)->_value << endl;
}