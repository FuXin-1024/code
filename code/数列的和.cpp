#include<iostream>
#include<math.h>
#include<iomanip>  
using namespace std;

int main()
{
	float  n;
	int m;
	float ret=0.0;
	while (cin >> n >> m)
	{
		for (int i = 0; i < m; i++)
		{
			ret += n;
			n = sqrt(n);
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << ret << endl;
	}
	system("pause");
	return 0;
}