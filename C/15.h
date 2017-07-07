#pragma warning(disable:4996)
#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void Test15()
{
	int start = 1;
	while (start)
	{
		printf("******************\n");
		printf("请做出你的选择: \n");
		printf(" 1  开始游戏!\n");
		printf(" 0  退出游戏！\n");
		printf("******************\n");
		scanf("%d", &start);
		switch (start)
		{
		case 0:
			exit(EXIT_FAILURE);
		case 1:
			printf("******游戏开始******");
			srand(time(NULL));
			int random = rand() % 100;
			int input = 0;
			while (1)
			{
				printf("请输入你猜的数字: \n");
				scanf("%d", &input);
				if (input > random)
					printf("你猜大了！");
				else if (input < random)
				printf("你猜小了！");
				else
				{
					printf("恭喜你猜对了！\n");
					break;
				}
			}
			break;
		default:
			printf("选择错误！");
			break;
		}
	}
}