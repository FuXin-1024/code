#pragma once
#include<iostream>
#include<assert.h>
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
bool IsBalanced(Node* root, int& depth)
{
	if (root == NULL)
	{
		depth = 0;
		return true;
	}

	int leftDepth = 0;
	int rightDepth = 0;
	bool left = IsBalanced(root->_left, leftDepth);
	bool right = IsBalanced(root->_right, rightDepth);

	if (left && right)
	{
		int diff = rightDepth - leftDepth;
		if (diff <= 1 && diff >= -1)
		{
			depth = 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
			return true;
		}
	}
	return false;
}

bool IsBalanced(Node* root)
{
	int depth = 0;
	return IsBalanced(root, depth);
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

void IsBalancedTest()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	cout << IsBalanced(root) << endl;

}