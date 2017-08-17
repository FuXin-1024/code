#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

template<class T>
struct Less
{
	bool operator()(const T& l, const T& r)const
	{
		return l < r;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& l, const T& r)const
	{
		return l > r;
	}
};

template<class T,class Compare=Less<T>>
struct Heap
{
public:
	Heap(T* a, size_t n)
	{
		_a.reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			_a.push_back(a[i]);
		}
		for (int j = (_a.size() - 1) / 2; j >= 0; --j)
		{
			_AdjustDown(j);
		}
	}

	const T& Top() const
	{
		return _a[0];
	}

	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}

	void Pop()
	{
		assert(!_a.empty());
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}

	size_t Size()
	{
		return _a.size();
	}

	bool Empty()
	{
		if (_a.size() == 0)
		{
			return false;
		}
		return true;
	}
protected:
	void _AdjustDown(int root)
	{
		Compare comFunc;
		int parent = root;
		int child = root * 2 + 1;

		while (child < _a.size())
		{
			if (child + 1 < _a.size() && comFunc(_a[child + 1], _a[child]))
				++child;
			if (comFunc(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}

	void _AdjustUp(int child)
	{
		Compare comFunc;
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (comFunc(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
private:
	vector<T> _a;
};

void HeapTest()
{
	int a[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	int n = sizeof(a) / sizeof(a[0]);
	Heap<int, Greater<int>> hp(a, n);
	cout << hp.Size() << endl;
	cout<<hp.Top()<<endl;
	hp.Push(28);
	hp.Pop();
	/*cout << hp.Size() << endl;
	hp.Print();*/
}
