#pragma once
#include<iostream>
#include<queue>
using namespace std;

//¶þ²æÊ÷µÄ²ãÐò±éÀú
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
void LevelOrder(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* front = q.front();
		cout << front->_value << " ";
		q.pop();
		if (front->_left)
			q.push(front->_left);
		if (front->_right)
			q.push(front->_right);
	}
}

Node* CreateTree(int *a, size_t n, size_t& index)
{
	if (index < n && a[index]!= '#')
	{
		Node* root = new Node(a[index]);
		root->_left = CreateTree(a, n, ++index);
		root->_right = CreateTree(a, n, ++index);
		return root;
	}
	return NULL;
}

void LevelOrderTest()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	LevelOrder(root);
}