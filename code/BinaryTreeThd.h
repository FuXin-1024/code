#include<iostream>
using namespace std;

enum PointerTag
{
	THREAD,
	LINK
};

template <class T>
 struct BinaryTreeNodeThd
{
	BinaryTreeNodeThd(const T& x)
	:_data(x)
	, _left(NULL)
	, _right(NULL)
	, _leftTag(LINK)
	, _rightTag(LINK)
	{}

	T _data;
	BinaryTreeNodeThd* _left;
	BinaryTreeNodeThd* _right;
	PointerTag _leftTag;
	PointerTag _rightTag;
}; 

 template <class T>
 class BinaryTreeThd
 {
	 typedef BinaryTreeNodeThd Node;
 public:
	 BinaryTreeThd(T* a, size_t n, const T& invalid = T())
	 {
		 size_t index = 0;
		 _root = _CreateTree(a, n, invlaid, index);
	 }

	 //中序线索化
	 void InOrderThreading()
	 {
		 Node* prev = NULL;
		 _InOrderThreading(_root, prev);
	 }
 protected:
	 Node* _CreateTree(T* a, size_t n, const T& invalid, size_t& index)
	 {
		 Node* root = NULL;
		 if (index < n && a[index] != invalid)
		 {
			 Node* root = new(a[index]);
			 root->_left = _CreateTree(a, n, invalid, ++index);
			 root->_right = _CreateTree(a, n, invalid, ++index);
		 }
		 return root;
	 }

	 void _InOrderThreading(Node* cur, Node* prev)
	 {
		 if (cur == NULL)
			 return;

		 _InOrderThreading(cur->_left, prev);
		 if (cur->_left == NULL)
		 {
			 cur->_left = rev;
			 cur->_leftTag = THREAD;
		 }
		 if (prev && prev->_right == NULL)
		 {
			 prev->_right = cur;
			 prev->_rightTag = THREAD;
		 }
		 prev = cur;
		 _InOrderThreading(cur->_right, prev);
	 }
 private:
	 Node* _root;
 };

