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
		printf("���������ѡ��: \n");
		printf(" 1  ��ʼ��Ϸ!\n");
		printf(" 0  �˳���Ϸ��\n");
		printf("******************\n");
		scanf("%d", &start);
		switch (start)
		{
		case 0:
			exit(EXIT_FAILURE);
		case 1:
			printf("******��Ϸ��ʼ******");
			srand(time(NULL));
			int random = rand() % 100;
			int input = 0;
			while (1)
			{
				printf("��������µ�����: \n");
				scanf("%d", &input);
				if (input > random)
					printf("��´��ˣ�");
				else if (input < random)
				printf("���С�ˣ�");
				else
				{
					printf("��ϲ��¶��ˣ�\n");
					break;
				}
			}
			break;
		default:
			printf("ѡ�����");
			break;
		}
	}
}