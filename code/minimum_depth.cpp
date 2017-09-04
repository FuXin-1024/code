#include<iostream>
#include<queue>
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

int run(Node* root)
{
	if (root == NULL)
		return 0;

	int depth = 0;
	if (root->_left != NULL && root->_right != NULL)
	{
		int left = run(root->_left);
		int right = run(root->_right);
		depth = left < right ? left : right;
	}
	else if (root->_left != NULL)
	{
		depth = run(root->_left);
	}
	else if (root->_right != NULL)
		depth = run(root->_right);

	return depth + 1;
}

int minDepth(Node* root)
{
	if (root == NULL)
		return 0;
	int depth = 0;
	queue<Node*> q;
	q.push(root);
	
	while (!q.empty())
	{
		int size = q.size();
		depth++;
		for (int i = 0; i < size; i++)
		{
			Node* cur = q.front();
			q.pop();
			if (cur->_left == NULL && cur->_right == NULL)
				return depth;
			 if (cur->_left != NULL)
				q.push(cur->_left);
			 if (cur->_right != NULL)
				q.push(cur->_right);
		}
	}
	return depth;
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

int main()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5};
	size_t index = 0;
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	int ret = minDepth(root);
	cout << ret << endl;
	system("pause");
	return 0;
}