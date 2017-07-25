#pragma once
#include<iostream>
using namespace std;

//¶þ²æÊ÷µÄ¾µÏñ

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
void MirrorRecurively(Node* root)
{
	if (root == NULL || (root->_left == NULL &&root->_right == NULL))
		return;

	Node* tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;

	if (root->_left)
		MirrorRecurively(root->_left);
	if (root->_right)
		MirrorRecurively(root->_right);
}

Node* CreateTree(int* a, size_t n, size_t& index)
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

void MRTest()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	MirrorRecurively(root);
}
