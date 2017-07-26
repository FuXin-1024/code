#pragma once
#include<iostream>
using namespace std;

//判断一颗二叉树是是否是另一颗树的子树。比如tree2是tree1的子树。 
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

bool DoesTree1HaveTree2(Node* root1, Node* root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;

	if (root1->_value != root2->_value)
		return false;

	return DoesTree1HaveTree2(root1->_left, root2->_left) &&
		DoesTree1HaveTree2(root1->_right, root2->_right);
}

bool IsSubTree(Node* root1, Node* root2)
{
	bool result = false;
	if (root1 != NULL && root2 != NULL)
	{
		if (root1->_value == root2->_value)
			result = DoesTree1HaveTree2(root1, root2);
		if (!result)
			result = IsSubTree(root1->_left, root2);
		if (!result)
			result = IsSubTree(root1->_right, root2);
	}
	return result;
}

void IsSubTreeTest()
{
	int a1[] = { 8, 8, 9, '#', '#', 2, 4, '#', '#', 7, '#', '#', 7, '#', '#' };
	int a2[] = { 8, 9, '#', '#', 2, '#', '#' };
	size_t index1 = 0;
	Node* root1 = CreateTree(a1, sizeof(a1) / sizeof(a1[0]), index1);

	size_t index2 = 0;
	Node* root2 = CreateTree(a2, sizeof(a2) / sizeof(a2[0]), index2);
	cout << IsSubTree(root1, root2) << endl;
}