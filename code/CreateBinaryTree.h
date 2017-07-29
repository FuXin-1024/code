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

Node* CreateBinaryTree(int* PreOrder, int startPre, int endPre, int* InOrder, int startIn, int endIn)
{
	if (PreOrder == NULL || InOrder == NULL || (endPre - startPre != endIn - startIn))
		return NULL;
	if (startPre > endPre)
		return NULL;

	Node* root = new Node(PreOrder[startPre]);//ǰ�������һ��Ԫ�ؼ�Ϊ�������ĸ��ڵ�
	if (startPre == endPre)//���ǰ�����ֻ��һ���ڵ㣬���ء�
		return root;
	int index, len;
	//�����������������
	for (index = startIn; index <= endIn; ++index)
	{
		if (PreOrder[startPre] == InOrder[index])
			break;
	}
	if (index > endIn)
		return NULL;

	//�ݹ鹹��������
	if (index > startIn)
	{
		len = index - startIn;
		root->_left = CreateBinaryTree(PreOrder, startPre + 1, startPre + 1 + len - 1, InOrder, startIn, startIn + len - 1);
	}
	//�ݹ鹹��������
	if (index < endIn)
	{
		len = endIn - index;
		root->_right = CreateBinaryTree(PreOrder, endPre - len + 1, endPre, InOrder, endIn - len + 1, endIn);
	}
	return root;
}

void CreateTreeTest()
{
	int PreOrder[] = { 1, 2, 3, 4, 5, 6 };
	int InOrder[] = { 3, 2, 4, 1, 6, 5 };
	Node* root = CreateBinaryTree(PreOrder, 0, 5, InOrder, 0, 5);
}