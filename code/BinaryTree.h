#include<iostream>
#include<stack>
#include<queue>
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

	//传统
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
	//现代
	/*BinaryTree<T>& operator=(const BinaryTree<T> t)
	{
		swap(_root, t._root);
		return *this;
	}*/

	BinaryTree(T* a, size_t n, const T& invalid = T())
	{
		size_t index = 0;
		_root = CreateTree(a, n, invalid, index);
	}

	//前序遍历
	void PrevOrder()
	{
		_PrevOrder(_root);
	}

	void PrevOrderNonR()
	{
		Node* cur = _root;
		stack<Node*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			Node* top = s.top();
			s.pop();
			cur = top->_right;
		}
	}

	//中序遍历
	void InOrder()
	{
		_InOrder(_root);
	}

	void InOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			cout << top->_data << " ";
			s.pop();
			cur = top->_right;
		}
	}
	//后序遍历
	void PostOrder()
	{
		_PostOrder(_root);
	}

	void PostOrderNonR()
	{
		stack<Node*> s;
		Node* cur = _root;
		Node* prev = NULL;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			if (top->_right == NULL || top->_right == prev)
			{
				cout << top->_data << " ";
				prev = top;
				s.pop();
			}
			else
			{
				cur = top->_right;
			}
		}
	}

	//层序遍历
	void LevelOrder()
	{
		_LevelOrder(_root);
	}

	size_t Size()
	{
		return _Size(_root);
	}

	//叶子节点数
	size_t GetLeafSize()
	{
		return  _GetLeafSize(_root);
	}
protected:
	Node* CreateTree(T* a, size_t n, const T& invalid, size_t& index)
	{
		Node* root = NULL;
		if (index < n && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = CreateTree(a, n, invalid, ++index);
			root->_right = CreateTree(a, n, invalid, ++index);
		}
		return root;
	}

	void _PrevOrder(Node* root)
	{
		if (root == NULL)
			return;
		
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return ;

		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;

		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_data << " ";
	}

	void _LevelOrder(Node* root)
	{
		if (root == NULL)
			return;

		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			Node* front = q.front();
			cout << front->_data << " ";
			q.pop();

			if (front->_left)
				q.push(front->_left);
			if (front->_right)
				q.push(front->_right);
		}
	}

	size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	size_t _GetLeafSize(Node* root)
	{
		if (root == NULL)
			return 0;

		if (root->_left == NULL && root->_right == NULL)
			return 1;

		return _GetLeafSize(root->_left) + _GetLeafSize(root->_right);
	}



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

void BinaryTreeTest()
{
	int  a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree  <int> t(a, sizeof(a) / sizeof(a[0]), '#');
	
	cout << "PrevOrde "; t.PrevOrder(); cout << endl;
	cout << "PrevOrdeNonR "; t.PrevOrderNonR(); cout << endl;

	cout << "InOrder "; t.InOrder(); cout << endl;
	cout << "InOrderNonR "; t.InOrderNonR(); cout << endl;

	cout << "PostOrde "; t.PostOrder(); cout << endl;
	cout << "PostOrdeNonR "; t.PostOrderNonR(); cout << endl;

	cout << "LevelOrder "; t.LevelOrder(); cout << endl;

	cout << "Size = ";  cout << t.Size()<< endl;

	cout << "LeafSize = ";  cout << t.GetLeafSize() << endl;
}