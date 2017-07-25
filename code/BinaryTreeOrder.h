#pragma once
#include<iostream>
#include<stack>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;

	BinaryTreeNode(const int x)
		:_value(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

typedef BinaryTreeNode Node;

Node* CreateTree(int* a, size_t n,size_t& index)
{
	if (index < n && a[index] != '#')
	{
		Node* root = new Node(a[index]);
		root->_left = CreateTree(a, n, ++index);
		root->_right = CreateTree(a, n, ++index);
		return root;
	}
	return NULL;
}

void PrevOrder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->_value << " ";
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

void PrevOrderNonR(Node* root)
{
	if (root == NULL)
		return;
	Node* cur = root;
	stack<Node*> s;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cout << cur->_value << " ";
			cur = cur->_left;
		}
		Node* top = s.top();
		s.pop();
		cur = top->_right;
	}
}

void InOrder(Node* root)
{
	if (root == NULL)
		return;
	InOrder(root->_left);
	cout << root->_value << " ";
	InOrder(root->_right);
}

void InOrderNonR(Node* root)
{
	if (root == NULL)
		return;
	Node* cur = root;
	stack<Node*> s;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->_left;
		}
		Node* top = s.top();
		cout << top->_value << " ";
		s.pop();
		cur = top->_right;
	}
}
void PostOrder(Node* root)
{
	if (root == NULL)
		return;
	PostOrder(root->_left);
	PostOrder(root->_right);
	cout << root->_value << " ";
}

void PostOrderNonR(Node* root)
{
	if (root == NULL)
		return;
	Node* cur = root;
	Node* prev = NULL;
	stack<Node*> s;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->_left;
		}
		Node* top = s.top();
		if (top->_right == NULL || top->_right == prev)
		{
			cout << top->_value << " ";
			prev = top;
			s.pop();
		}
		else
		{
			cur = top->_right;
		}
	}
}

void OrderTest()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#',5,6 };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	cout << "PrevOrder: "; PrevOrder(root); cout << endl;
	cout << "PrevOrderNonR: "; PrevOrderNonR(root); cout << endl;
	cout << "InOrder: "; InOrder(root); cout << endl;
	cout << "InOrderNonR: "; InOrderNonR(root); cout << endl;
	cout << "PostOrder: "; PostOrder(root); cout << endl;
	cout << "PostOrderNonR: "; PostOrderNonR(root); cout << endl;

}