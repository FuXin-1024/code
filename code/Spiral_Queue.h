#pragma once
#include<iostream>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) :(b) )
#define abs(a) ((a) > 0 ? (a) : (-a))
#define square(a) ((a) * (a))

//�������꣬�����Ӧ������

int Spiral_Queue(int x, int y)
{
	int c = max(abs(x), abs(y));// ���������ڵڼ���
	int max = square(2 * c + 1); //�ò�����ֵ

	if (y == -c) //��
		return max +( x + y);
	else if (x == -c) //��
		return max + (3 * x - y);
	else if (y == c) //��
		return max +(- x - 5 * y);
	else  //��
		return max +(- 7 * x + y);

}

void Spiral_QueueTest()
{
	int x, y;
	const int N = 4; //��Ҫ��ӡ�Ĳ���
	for (y = -N; y <= N; y++)
	{
		for (x = -N; x <= N; x++)
			cout << Spiral_Queue(x, y) << "  ";
		cout << endl;           //��y���ӡ������  
	}
}
