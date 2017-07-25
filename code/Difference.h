#pragma once
#include<iostream>
using namespace std;
struct Node
{
	int _value;
	Node* _next;

	Node(const int x)
		:_value(x)
		, _next(NULL)
	{}
};

void Difference(Node** LA, Node* LB)
{
	Node* pa, *pb, *prev, *q;
	prev = NULL;
	pa = *LA;
	while (pa)
	{
		pb = LB;
		while (pb && pa->_value != pb->_value)
		{
			pb = pb->_next;
		}
		if (pb)
		{
			if (!prev)
				*LA = pa->_next;
			else
				prev->_next = pa->_next;
			q = pa;
			pa = pa->_next;
			free(q);
		}
		else
		{
			prev = pa;
			pa = pa->_next;
		}
	}
}


void DifferenceTest()
{
	Node* head = new Node(5);
	Node* n1 = new Node(10);
	head->_next = n1;
	Node* n2 = new Node(20);
	n1->_next = n2;
	Node* n3 = new Node(15);
	n2->_next = n3;
	Node* n4 = new Node(25);
	n3->_next = n4;
	Node* n5 = new Node(30);
	n4->_next = n5;

	Node* head1 = new Node(5);
	Node* n6 = new Node(15);
	head1->_next = n6;
	Node* n7 = new Node(35);
	n6->_next = n7;
	Node* n8 = new Node(25);
	n7->_next = n8;
	n8->_next = NULL;

	Difference(&head, head1);
}