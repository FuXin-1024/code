#pragma once
#include<iostream>
using namespace std;

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

Node* FindNode(Node* root,int x)
{
	if (root == NULL)
		return NULL;
	if (root->_value == x)
		return root;
	Node*  ret = FindNode(root->_left, x);
	if (ret)
		return ret;
	return FindNode(root->_right, x);
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

void FindNodeTest()
{

	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	cout << FindNode(root, 1)->_value << endl;
	cout << FindNode(root, 2)->_value << endl;
	cout << FindNode(root, 3)->_value << endl;
	cout << FindNode(root, 4)->_value << endl;
	cout << FindNode(root, 5)->_value << endl;
	cout << FindNode(root, 6)->_value << endl;
	cout << FindNode(root, 0)<< endl;

}