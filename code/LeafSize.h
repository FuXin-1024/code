#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//求叶子节点的个数
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
size_t GetLeafSize(Node* root)
{
	if (root == NULL)
		return 0;
	if ((root->_left == NULL) && (root->_right == NULL))
		return 1;
	return GetLeafSize(root->_left) + GetLeafSize(root->_right);
}

void GetLeafSize(Node* root, size_t& count)
{
	if (root == NULL)
		return ;
	if ((root->_left == NULL) && (root->_right == NULL))
		++count;

	GetLeafSize(root->_left, count);
	GetLeafSize(root->_right, count);
}

//第K层的节点数
size_t GetKLevelSize(Node* root, size_t k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelSize(root->_left, k - 1) + GetKLevelSize(root->_right, k - 1);
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

void LeafSizeTest()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	size_t index = 0;
	size_t count = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	cout << GetLeafSize(root) << endl;
	GetLeafSize(root, count);
	cout << count << endl;
	cout << GetKLevelSize(root, 3) << endl;

}