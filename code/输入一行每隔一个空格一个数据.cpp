#pragma warning(disable:4996)
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	char str[20];
	vector<int> v;
	//scanf("%[^\n]", str);
	//printf("%s", str);

	int nArr[100];
	char c;
	int i = 0;
	while ((c = getchar()) != '\n') //流中一个字符一个字符判断，直到换行，输入结束
	{
		if (c != ' ')
		{
			ungetc(c, stdin);//如果字符c不是空格，就要将c字符还回到流中，不然造成数据读取错误
		
			cin >> nArr[0];//流输入会将第一个数据全读入，直到遇到空格
			v.push_back(nArr[0]);
		}
	}
	system("pause");
	return 0;
}