#include<stdlib.h>
#include<stdio.h>

void fn1(void), fn2(void), fn3(void), fn4(void);

void main()
{
	atexit(fn1);
	atexit(fn2);
	atexit(fn3);
	atexit(fn4);
	printf("This is executeed first\n");

}

void  fn1()
{
	printf("next.\n");
	system("pause");
}

void  fn2()
{
	printf("executed ");
}

void  fn3()
{
	printf("is ");
}

void  fn4()
{
	printf("This ");
}