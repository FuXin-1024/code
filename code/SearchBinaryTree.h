#include<iostream>
using namespace std;

template <class K>
struct SerachBinaryTreeNode
{
	K _key;
	SerachBinaryTreeNode<K>* _left;
	SerachBinaryTreeNode<K>* _right;

	SerachBinaryTreeNode(const K& key)
		:_key(key)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class K>
class SerachBinaryTree
{
	typedef SerachBinaryTreeNode<K> Node;
public:
	SerachBinaryTree()
		:_root(NULL)
	{}

	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node(key);
			return true;
		}

		Node* cur = root;
		Node* parent = NULL;

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
		if (parent->_key < key)
		{
			parent->_right = new Node(key);
			return true;
		}
		else
		{
			parent->_left = new Node(key);
			return true;
		}
	}

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	const Node* Find(const K& key)
	{
		if (_root == NULL)
			return NULL;

		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				cur = cur->_left;
			}
			else
				return cur;
		}
		return NULL;
	}

	const Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	~SerachBinaryTree()
	{
		_Destroy(_root);
	}

protected:

	bool _InsertR(Node*& root, const K& key)
	{
		if (root == NULL)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
			return _InsertR(root->_right, key);
		else if (root->_key>key)
			return _InsertR(root->_left, key);
		else
			return false;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	const Node* _FindR(Node* root,const K& key)
	{
		if (root == NULL)
			return NULL;

		if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else if (root->_key>key)
		{
			return _FindR(root->_left, key);
		}
		else
		{
			return root;
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
private:
	Node* _root;
};

void Test()
{
	SerachBinaryTree<int> s;
	s.InsertR(5);
	s.InsertR(3);
	s.InsertR(4);
	s.InsertR(1);
	s.InsertR(7);
	s.InsertR(8);
	s.InsertR(2);
	s.InsertR(6);
	s.InsertR(0);
	s.InsertR(9);
	s.InOrder(); cout << endl;

	//cout << s.Find(0)->_key << endl;
	//cout << s.Find(1)->_key << endl;
	//cout << s.Find(2)->_key << endl;
	//cout << s.Find(3)->_key << endl;
	//cout << s.Find(4)->_key << endl;
	//cout << s.Find(5)->_key << endl;
	//cout << s.Find(6)->_key << endl;
	//cout << s.Find(7)->_key << endl;
	//cout << s.Find(8)->_key << endl;
	//cout << s.Find(9)->_key << endl;
	//cout << s.Find(11) << endl;

	/*cout << s.FindR(0)->_key << endl;
	cout << s.FindR(1)->_key << endl;
	cout << s.FindR(2)->_key << endl;
	cout << s.FindR(3)->_key << endl;
	cout << s.FindR(4)->_key << endl;
	cout << s.FindR(5)->_key << endl;
	cout << s.FindR(6)->_key << endl;
	cout << s.FindR(7)->_key << endl;
	cout << s.FindR(8)->_key << endl;
	cout << s.FindR(9)->_key << endl;
	cout << s.FindR(11) << endl;*/
}