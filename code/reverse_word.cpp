//#include<iostream>
//using namespace std;
////二叉搜索树与双向链表
//struct Node
//{
//	int _value;
//	Node* _left;
//	Node* _right;
//
//	Node(const int x)
//		:_value(x)
//		, _left(NULL)
//		, _right(NULL)
//	{}
//};
//
//Node* CreateTree(int* a, int n, int& index)
//{
//	if (index < n && a[index] != '#')
//	{
//		Node* root = new Node(a[index]);
//		root->_left = CreateTree(a, n, ++index);
//		root->_right = CreateTree(a, n, ++index);
//		return root;
//	}
//	return NULL;
//}
//
//void _Convert(Node* root, Node** prev)
//{
//	if (root == NULL)
//		return;
//	if (root->_left)
//		_Convert(root->_left, prev);
//
//	//left指针指向上一个结点
//	root->_left = *prev;
//	//right指向下一个结点
//	if (*prev != NULL)
//		(*prev)->_right = root;
//	*prev = root;
//
//	if (root->_right)
//		_Convert(root->_right, prev);
//}
//Node* Convert(Node* root)
//{
//	if (root == NULL)
//		return NULL;
//
//	//找到最左边的结点-->转换后链表的头结点
//	Node* head = root;
//	while (head->_left)
//	{
//		head = head->_left;
//	}
//	Node* prev = NULL;
//	_Convert(root, &prev);
//	return head;
//}
//
//void Test()
//{
//	int a[] = { 10, 6, 4, '#', '#', 8, '#', '#', 14, 12, '#', '#', 16, '#', '#' };
//	int index = 0;
//	Node* root = CreateTree(a, sizeof(a) / sizeof(a[0]), index);
//	Convert(root);
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include <algorithm>
//using namespace std;
//
//#define MAX 101 
//int D[MAX][MAX];
//int n;
//int maxSum[MAX][MAX];
//
//int MaxSum(int i, int j)
//{
//	if (maxSum[i][j] != -1)
//		return maxSum[i][j];
//
//	if (i == n)
//		maxSum[i][j] = D[i][j];
//
//	else
//	{
//		int x = MaxSum(i + 1, j);
//		int y = MaxSum(i + 1, j + 1);
//		maxSum[i][j] = max(x, y) + D[i][j];
//	}
//	return maxSum[i][j];
//}
//int main()
//{
//	int i, j;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	for (j = 1; j <= i; j++)
//	{
//		cin >> D[i][j];
//		maxSum[i][j] = -1;
//	}
//	cout << MaxSum(1, 1) << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//bool cmp(const string &a, string &b)
//{
//	if ((a + b) > (b + a))
//		return true;
//	return false;
//
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		string m;
//		vector<string> v;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> m;
//			v.push_back(m);
//		}
//		sort(v.begin(), v.end(),cmp);
//		for (auto ret : v)
//			cout << ret;
//	}
//	return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	while (getline(cin,str))
	{
		reverse(str.begin(), str.end());
		int i = 0, j = i;
		while (i < str.size())
		{
			while (i < str.size() && str[i] != ' ')
			{
				++i;
			}
			reverse(str.begin() + j, str.begin() + i);
			j = ++i;
		}
		cout << str;
	}
	system("pause");
	return 0;
}