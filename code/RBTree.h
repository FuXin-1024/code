#include<iostream>
using namespace std;

enum COLOR
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{
	K _key;
	V _value;
	COLOR _color;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	RBTreeNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _color(RED)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}

	~RBTree()
	{
		_Destroy(_root);
	}

	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key,value);
			_root->_color = BLACK;
			return NULL;
		}
		Node* parent = NULL;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (parent->_key < key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//判断插入的几种情况
		while (parent && parent->_color == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//叔叔存在切为红
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else //叔叔不存在或者存在为黑
				{
					//双旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}
					RotateR(grandfather);
					parent->_color = BLACK;
					grandfather->_color = RED;
					break;
				}
			}
			//父亲是右儿子，叔叔在左边
			else
			{
				Node* uncle = grandfather->_left;
				//叔叔存在且为红
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					grandfather->_color = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				//叔叔不存在，或存在为黑
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}
					RotateL(grandfather);
					parent->_color = BLACK;
					grandfather->_color = RED;
					break;
				}
			}
		}
		_root->_color = BLACK;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}
protected:
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		Node* ppNode = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (ppNode == NULL)
		{
			_root = subL;
			_root->_parent = NULL;
		}
		else
		{
			if (ppNode->_right == parent)
			{
				ppNode->_right = subL;
			}
			else
			{
				ppNode->_left = subL;
			}
			subL->_parent = ppNode;
		}
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		Node* ppNode = parent->_parent;
		subR->_left = parent;
		parent->_parent=subR;
		if (ppNode == NULL)
		{
			_root = subR;
			_root->_parent = NULL;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
			subR->_parent = ppNode;
		}

	}

	void _Destroy(Node* root)
	{
		if (root == NULL)
			return;
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root;
};


void Test()
{
	RBTree<int, int> t1;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15, 9, 3 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		t1.Insert(a[i], i);
	}
	t1.InOrder(); cout << endl;
	/*cout << t1.IsBlance() << endl;*/
}


