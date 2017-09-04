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

ListNode* InsertionList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* cur = head;
	ListNode* sortHead = new ListNode(0);
	ListNode* node = sortHead;

	while (cur)
	{
		ListNode* next = cur->next;
		node = sortHead;
		while (node->next != NULL && node->next->val < cur->val)
		{
			node = node->next;
		}
		cur->next = node->next;
		node->next = cur;
		cur = next;
	}
	return sortHead->next;
}
int main()
{
		ListNode* phead1 = new ListNode(1);
		ListNode* Node1 = new ListNode(3);
		phead1->next = Node1;
		ListNode* Node2 = new ListNode(5);
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

		InsertionList(phead1);
	system("pause");
	return 0;
}