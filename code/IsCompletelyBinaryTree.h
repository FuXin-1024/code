#pragma once
#include<iostream>
#include<queue>
using namespace std;

//判断一棵树是否为完全二叉树
struct Node
{
	int _value;
	Node* _left;
	Node* _right;

	Node(const int x)
		:_value(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

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

queue<Node*> q;
bool flag = false;

bool HaveChild(Node* child)
{
	if (child)
	{
		if (!flag)
			q.push(child);
		else
			return false;
	}
	else
	{
		flag = true;
	}
	return true;
}
bool IsCompleteltBinaryTree(Node* root)
{
	if (root == NULL)//空树也是完全二叉树
		return true;

	q.push(root);

	while (!q.empty())
	{
		Node* front = q.front();
		q.pop();
		if (!HaveChild(front->_left))
			return false;

		if (!HaveChild(front->_right))
			return false;
	}
	return true;
}

void CompleteTest()
{
	int  a[] = { 1, '#', 4, '#', 5, 6 };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	cout << IsCompleteltBinaryTree(root) << endl;

}