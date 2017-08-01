#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

void CalculateFruitCount(map<string,int>m, string s[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		//m[s[i]]++; / map����operator[]������, �����ݵ�ͬ���±ߴ���
	
	pair<map<string, int>::iterator, bool> ret;
	ret = m.insert(make_pair(s[i], i));
	if (ret.second == false)
		ret.first->second++;
	}
}

void GetFavoriteFruit(const vector<string>& fruits, size_t K)
{
	map<string, int> m;
	for (size_t i = 0; i < fruits.size(); i++)
	{
		m[fruits[i]]++;
	}
	struct Compare
	{
		bool operator()(map<string, int>::iterator Left, map<string, int>::iterator Right)
		{
			return (Left->second) < (Right->second);
		}
	};

	priority_queue<map<string, int>::iterator, vector<map<string, int>::iterator>, Compare> q;
	map<string, int>::iterator it = m.begin();
	while (it != m.end())
	{
		q.push(it);
		++it;
	}
	for (size_t i = 0; i < K; i++)
	{
		cout  << "=" << q.top()->second << endl;
		q.pop();
	}
}

void TestFruits()
{
	vector<string> V;
	for (size_t i = 0; i < 10; i++)
	{
		V.push_back("ƻ��");
		V.push_back("�㽶");
		V.push_back("����");
		V.push_back("����");
		V.push_back("���ܹ�");
		V.push_back("����");
		V.push_back("����");
		V.push_back("������");
		V.push_back("����");
	}
	for (size_t i = 0; i < 5; i++)
	{
		V.push_back("�㽶");
		V.push_back("����");
		V.push_back("����");
	}
	GetFavoriteFruit(V, 3);
}