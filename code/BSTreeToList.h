#include<iostream>
using namespace std;

//将二叉搜索树转换成一个排序的双向链表
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

Node* FindLeftMostNode(Node* root)
{
	if (root == NULL)
		return NULL;
	while (root->_left != NULL)
		root = root->_left;
	return root;
}

void ConvertNode(Node* root, Node** last_node)
{
	if (root == NULL)
		return;
	//对tree的左子树进行转换，last_node是转换后链表最后一个结点的指针
	if (root->_left != NULL)
		ConvertNode(root->_left, last_node);
	//调整root的left指针，指向上一个节点
	root->_left = *last_node;
	//调整指向最后一个节点，right指向下一个节点
	if (*last_node != NULL)
		(*last_node)->_right = root;
	//调整指向最后链表一个节点的指针
	*last_node = root;
	// 对root的右子树进行转换，last_node是转换后链表最后一个结点的指针
	if (root->_right != NULL)
		ConvertNode(root->_right, last_node);
}

Node* BSTreeToList(Node* root)
{
	if (root == NULL)
		return NULL;
	//找到最左边的节点，即转换后链表的头结点
	Node* head = FindLeftMostNode(root);
	Node* last_node = NULL;
	//进行转换
	ConvertNode(root, &last_node);
	return head;
}

void Test()
{
	size_t index = 0;
	int  a[] = { 4, 2, 1, '#', '#', 3, '#', '#', 6, 5, '#', '#', 7, '#', '#' };
	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
	Node* head = BSTreeToList(root);
 }