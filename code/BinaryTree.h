#include<iostream>
#include<stack>
#include<queue>
#include<assert.h>
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

	size_t GetLeafSize1()
	{
		size_t count = 0;
		_GetLeafSize(_root, count);
		return count;
	}

	//求第k层的节点数
	size_t GetKLevelSize(size_t k)
	{
		assert(k > 0);
		return _GetKLevelSize(_root, k);
	}

	size_t Depth()
	{
		return _Depth(_root);
	}

	Node* Find(const T& x)
	{
		return _Find(_root, x);
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

	void _GetLeafSize(Node* root, size_t& count)
	{
		if (root == NULL)
			return ;

		if (root->_left == NULL && root->_right == NULL)
			count++;

		_GetLeafSize(root->_left,count);
		_GetLeafSize(root->_right,count);
	}

	size_t _GetKLevelSize(Node* root, size_t k)
	{
		if (root == NULL)
			return 0;
		if (k == 1)
			return 1;
		return _GetKLevelSize(root->_left, k - 1) + _GetKLevelSize(root->_right, k - 1);
	}

	size_t _Depth(Node* root)
	{
		if (root == NULL)
			return 0;
		int left = _Depth(root->_left);
		int right = _Depth(root->_right);
		return left > right ? left + 1 : right + 1;
	}

	Node* _Find(Node* root, const T& x)
	{
		if (root == NULL)
			return NULL;
		if (root->_data == x)
			return root;

		Node* ret = _Find(root->_left, x);
		if (ret)
			return ret;
		return _Find(root->_right, x);
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
	cout << "LeafSize = ";  cout << t.GetLeafSize1() << endl;

	cout << "KLevelSize = ";  cout << t.GetKLevelSize(3) << endl;

	cout << "Depth = ";  cout << t.Depth() << endl;
	
	cout << "Find(3) = "; cout << t.Find(3)->_data << endl;
}