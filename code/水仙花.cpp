#include<iostream>
#include<vector>
using namespace std;

//水仙花
int main()
{
	int m; int n;
	while (cin >> m >> n)
	{
		vector<int> ret;
		for (int i = m; i <= n; i++)
		{
			int a = i / 100;//百位
			int b = (i % 100) /10;//十位
			int c = i % 10;
			if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
				ret.push_back(i);
		}
		if (ret.empty())
			cout << "no";
		else
		for (auto tmp : ret)
			cout << tmp << " ";
	}
	system("pause");
	return 0;
}