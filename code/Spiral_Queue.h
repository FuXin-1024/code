#pragma once
#include<iostream>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) :(b) )
#define abs(a) ((a) > 0 ? (a) : (-a))
#define square(a) ((a) * (a))

//输入坐标，输出对应的数字

int Spiral_Queue(int x, int y)
{
	int c = max(abs(x), abs(y));// 该坐标所在第几层
	int max = square(2 * c + 1); //该层的最大值

	if (y == -c) //上
		return max +( x + y);
	else if (x == -c) //左
		return max + (3 * x - y);
	else if (y == c) //下
		return max +(- x - 5 * y);
	else  //右
		return max +(- 7 * x + y);

}

void Spiral_QueueTest()
{
	int x, y;
	const int N = 4; //需要打印的层数
	for (y = -N; y <= N; y++)
	{
		for (x = -N; x <= N; x++)
			cout << Spiral_Queue(x, y) << "  ";
		cout << endl;           //按y层打印，换行  
	}
}
