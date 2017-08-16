#include<iostream>
using namespace std;

template <class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	BinaryTreeNode(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}

	~BinaryTree()
	{
		_Destroy(_root);
	}

	BinaryTree(const BinaryTree<T>& t)
	{
		_root = _Copy(t._root);
	}

	//´«Í³
	BinaryTree<T>& operator=(const BinaryTree<T>& t)
	{
		if (this != &t)
		{
			Node* newNode = _Copy(t._root);
			_Destroy(_root);
			_root = newNode;
		}
		return *this;
	}

protected:
	void _Destroy(Node* root)
	{
		if (root == NULL)
			return;

		_Destroy(root->_left);
		_Destroy(root->_right);

		delete root;
	}

	Node* _Copy(Node* root)
	{
		if (root == NULL)
			return NULL;

		Node* newNode = new Node(root->_data);
		newNode->_left = _Copy(root->_left);
		newNode->_right = _Copy(root->_right);

		return newNode;
	}
private:
	Node* _root;
};