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
	while ((c = getchar()) != '\n') //����һ���ַ�һ���ַ��жϣ�ֱ�����У��������
	{
		if (c != ' ')
		{
			ungetc(c, stdin);//����ַ�c���ǿո񣬾�Ҫ��c�ַ����ص����У���Ȼ������ݶ�ȡ����
		
			cin >> nArr[0];//������Ὣ��һ������ȫ���룬ֱ�������ո�
			v.push_back(nArr[0]);
		}
	}
	system("pause");
	return 0;
}