#pragma once
#include<iostream>
#include<stack>
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

struct pNode
{
	int _value;
	pNode* _left;
	pNode* _right;
	pNode* _parent;

	pNode(const int x)
		:_value(x)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
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

Node* Find(Node* root, const int& value)
{
	if (root == NULL)
		return NULL;
	if (root->_value == value)
		return root;
	Node* tmp = Find(root->_left, value);
	if (tmp)
		return tmp;
	return Find(root->_right, value);
}

bool GetPath(Node* root, Node* node, stack<Node*>& s)
{
	if (root == NULL)
		return false;
	if (root->_value == node->_value)
	{
		s.push(root);
		return true;
	}
	s.push(root);
	if (GetPath(root->_left, node, s))
		return true;
	if (GetPath(root->_right, node, s))
		return true;
	s.pop();
	return false;
}

//查找的是普通二叉树
Node* ComGrandParent(Node* root, Node* node1, Node* node2)
{
	if (root == NULL || node1==NULL || node2==NULL)
		return NULL;
	if (node1 == root || node2 == root)
		return root;
	stack<Node*> s1;
	stack<Node*> s2;

	GetPath(root, node1, s1);
	GetPath(root, node2, s2);

	while (s1.size() > s2.size())
	{
		s1.pop();
	}

	while (s1.size() < s2.size())
	{
		s2.pop();
	}

	while (s1.top() != s2.top())
	{
		s1.pop();
		s2.pop();
	}
	return s1.top();
}

//查找的是搜索二叉树
Node* ComGrandParent1(Node* root, Node* node1, Node* node2)
{
	if (root == NULL || node1 == NULL || node2 == NULL)
		return NULL;

	int min, max;
	if (node1->_value < node2->_value)
	{
		min = node1->_value;
		max = node2->_value;
	}
	else
	{
		min = node2->_value;
		max = node1->_value;
	}

	Node* cur = root;
	while (cur)
	{
		if (min <= cur->_value && max >= cur->_value)
			return cur;
		if (min > cur->_value)
			cur = cur->_right;
		if (max < cur->_value)
			cur = cur->_left;
	}
	return NULL;
}

int Height(pNode* root, pNode* node)
{
	if (root == NULL)
		return 0;
	int len = 0;
	for (; node != NULL; node = node->_parent)
		++len;
	return len;
}

//查找的是带有指向父节点的三叉链
pNode* ComGrandParent2(pNode* root, pNode* node1, pNode* node2)
{
	if (root == NULL || node1 == NULL || node2 == NULL)
		return NULL;

	int len1 = Height(root, node1);
	int len2 = Height(root, node2);

	for (; len1 > len2; len1--)
		node1 = node1->_parent;
	for (; len2 > len1; len2--)
		node2 = node2->_parent;

	while (node1 && node2 && node1 != node2)
	{
		node1 = node1->_parent;
		node2 = node2->_parent;
	}

	if (node1 == node2)
		return node1;
	else
		return NULL;
}


void Test()
{
	size_t index = 0;
	int  a[] = { 1, 2, 4, '#', '#', 5, '#', '#', 3, 6, '#', '#', 7, '#', '#' };
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);

	size_t index1 = 0;
	int  a1[] = { 5, 3, 1, 0, '#', '#', '#', 4, '#', '#', 7, 6, '#', '#', 8, '#', 9, '#', '#' };
		//5, 3, 1, 0, '#', '#, '#', 4, '#', '#', 7, 6, '#', '#', 8, '#', 9, '#', '#'
	Node* root1 = CreateTree(a1, sizeof(a1) / sizeof(a1[0]), index1);
	Node* node1 = Find(root,4);
	Node* node2 = Find(root, 7);

	Node* ret = ComGrandParent1(root1, node1, node2);
	cout << ret->_value << endl;
}