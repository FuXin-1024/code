#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x)
		:val(x)
		,next(NULL)
	{}
};

ListNode* MergeList(ListNode* list1, ListNode* list2)
{
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	ListNode* head = NULL;
	if (list1->val < list2->val)
	{
		head = list1;
		head->next = MergeList(list1->next, list2);
	}
	else
	{
		head = list2;
		head->next = MergeList(list1, list2->next);
	}
	return head;
}

ListNode* sortList(ListNode* head)
{
	if (head == NULL || head->next==NULL)
		return head;

	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* tmp = slow->next;
	slow->next = NULL;
	return MergeList(sortList(head), sortList(tmp));

}
int main()
{
	ListNode* phead1 = new ListNode(3);
	ListNode* Node1 = new ListNode(2);
	phead1->next = Node1;
	ListNode* Node2 = new ListNode(4);
	Node1->next = Node2;
	
	ListNode* Node3 = new ListNode(7);
	Node2->next = Node3;
	

	ListNode* phead2 = new ListNode(2);
	Node3->next = phead2;
	ListNode* Node4 = new ListNode(4);
	phead2->next = Node4;
	ListNode* Node5 = new ListNode(6);
	Node4->next = Node5;
	ListNode* Node6 = new ListNode(8);
	Node5->next = Node6;
	Node6->next = NULL;

	sortList(phead1);
	system("pause");
	return 0;
}