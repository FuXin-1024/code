#pragma once
#include<iostream>
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
//求二叉树的高度
size_t Depth(Node* root)
{
	if (root == NULL)
		return 0;
	int left = Depth(root->_left);
	int right = Depth(root->_right);
	return left > right ? left + 1 : right + 1;
}

Node* CreateTree(int a[], size_t n, size_t& index)
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

//销毁二叉树
void Destroy(Node* root)
{
	if (root == NULL)
		return;
	Destroy(root->_left);
	Destroy(root->_right);
	delete root;
}

void DepthTest()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	cout << Depth(root) << endl;
	
}
