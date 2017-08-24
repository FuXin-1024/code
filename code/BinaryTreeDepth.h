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

bool IsBalanced(Node* root)
{
	if (root == NULL)
		return true;

	int left = Depth(root->_left);
	int right = Depth(root->_right);
	int diff = left - right;
	if (diff > 1 || diff < -1)
		return false;

	return IsBalanced(root->_left) && IsBalanced(root->_right);
}

bool IsBalanced1(Node* root, int& depth)
{
	if (root == NULL)
		return true;

	int left = 0, right = 0;
	if (IsBalanced1(root->_left, left) && IsBalanced1(root->_right, right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
void Test()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int  index = 0;
	int depth = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	cout<<IsBalanced1(root,depth)<<endl;
}