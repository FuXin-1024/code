#pragma once
#include<iostream>
using namespace std;

//��Ҷ�ӽڵ�ĸ���
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

}