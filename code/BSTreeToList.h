#include<iostream>
using namespace std;

//������������ת����һ�������˫������
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
	//��tree������������ת����last_node��ת�����������һ������ָ��
	if (root->_left != NULL)
		ConvertNode(root->_left, last_node);
	//����root��leftָ�룬ָ����һ���ڵ�
	root->_left = *last_node;
	//����ָ�����һ���ڵ㣬rightָ����һ���ڵ�
	if (*last_node != NULL)
		(*last_node)->_right = root;
	//����ָ���������һ���ڵ��ָ��
	*last_node = root;
	// ��root������������ת����last_node��ת�����������һ������ָ��
	if (root->_right != NULL)
		ConvertNode(root->_right, last_node);
}

Node* BSTreeToList(Node* root)
{
	if (root == NULL)
		return NULL;
	//�ҵ�����ߵĽڵ㣬��ת���������ͷ���
	Node* head = FindLeftMostNode(root);
	Node* last_node = NULL;
	//����ת��
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