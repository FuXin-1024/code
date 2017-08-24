#include<iostream>
using namespace std;

//二叉树的深度
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

int Depth(Node* root)
{
	if (root == NULL)
		return 0;
	int left = Depth(root->_left);
	int right = Depth(root->_right);

	return left > right ? left + 1 : right + 1;
}
Node* CreateTree(int* a, int n, int& index)
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