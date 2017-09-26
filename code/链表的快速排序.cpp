#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
struct ListNode
{
	int _value;
	ListNode* _next;

	ListNode(int x)
		:_value(x)
		, _next(NULL)
	{}
};

ListNode* partion(ListNode* begin, ListNode* end)
{
	if (begin == end || begin->_next == end)
		return begin;

	int key = begin->_value;
	ListNode* p = begin;
	ListNode* q = begin->_next;
	while (q != end)
	{
		if (q->_value < key)
		{
			swap(&p->_value, &q->_value);
			p = p->_next;
		}
		q = q->_next;
	}
	swap(&p->_value, &key);
	return p;
}

void QuickSort(ListNode* begin, ListNode* end)
{
	if (begin == end || begin->_next == end)
		return;
	ListNode* mid = partion(begin, end);
	QuickSort(begin, mid);
	QuickSort(mid->_next, end);
}

ListNode* SortList(ListNode* head)
{
	if (head == NULL || head->_next == NULL)
		return head;
	QuickSort(head,NULL);
	return head;
}
int main()
{
	ListNode* head = new ListNode(3);
	ListNode* Node1 = new ListNode(1);
	head->_next = Node1;
	ListNode* Node2 = new ListNode(2);
	Node1->_next = Node2;
	ListNode* Node3 = new ListNode(5);
	Node2->_next = Node3;
	ListNode* Node4 = new ListNode(4);
	Node3->_next = Node4;
	ListNode* Node5 = new ListNode(8);
	Node4->_next = Node5;
	Node5->_next = NULL;
	SortList(head);
	system("pause");
	return 0;
}