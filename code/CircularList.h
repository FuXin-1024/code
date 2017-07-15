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

//�ж��Ƿ��л��������������ָ�룬����������л�
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

//��һ������ʱ��ʼ��ʱ���ڶ�������ʱ����Ϊ������
int CircularLength(ListNode* phead)
{
	if (!IsExitLoop(phead)) //��������������ĳ���Ϊ0
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

		if (fast == slow && second == true)//�ڶ�����������ѭ��
			break;

		if (fast == slow && first == false)//��һ������,��ʼ����
		{
			first = true;
			second = true;
		}
		if(first == true)
			++len;
	}
	return len;
}

//������ڵ�   �����㵽��ڵ�ľ������ͷ��㵽��ڵ�ľ���
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
	
	//�ߵ�������
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