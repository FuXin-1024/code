#include<iostream>
#include<assert.h>
using namespace std;

//ֱ�Ӳ�������
void InsertSort(int* arr, int len)//��������
{
	assert(arr);
	assert(len > 0);
	for (int i = 1; i <len; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		
		while (j>=0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void ShellSort(int* arr, int len)
{
	assert(arr);
	assert(len);

	int gap = len;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < len; i++)
		{
			int end = i - gap;
			int temp = arr[i];

			while (end >= 0)
			{
				if (arr[end] < temp)
					break;

				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = temp;
		}
	}
}

//ѡ������
void SelectSort(int* arr, int len)
{
	assert(arr > 0);
	assert(len > 0);
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[i])
				swap(arr[i], arr[j]);
		}
	}
}

//������
//���򽨴��

void AdjustDown(int* heap, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && heap[child + 1] > heap[child])
			++child;
		if (heap[child]>heap[parent])
		{
			swap(heap[child], heap[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* arr, int len)
{
	assert(arr);
	assert(len);
	int parent = (len - 2) >> 1;
	for (; parent >= 0; --parent)
		AdjustDown(arr, len, parent);
	//�Ѷ������һ���������������һ�����������ɴ�ѡ�ѭ������֤ÿ���ѵ����һ����������
	for (int i = len - 1; i >= 0; --i)
	{
		swap(arr[0], arr[i]);
		AdjustDown(arr,i, 0);
	}
}

//ð������
void BubbleSort(int* arr, int len)
{
	assert(arr);
	assert(len > 0);
	for (int i = len; i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

void BubbleSort1(int* arr, int len)
{
	assert(arr);
	assert(len);
	bool flag = 1;
	for (int i = len; flag; i--)
	{
		flag = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[j-1])
			{
				swap(arr[j], arr[j-1]);
				flag = 1;
			}
		}
	}
}

// ��һ���Ż�������������100��������90�������ź����Ҷ�����ǰ��10�����֣�
//��ô�ڵ�һ�˱����������������λ�ñض�С��10�������λ��֮������ݱض��Ѿ������ˣ�
//��¼����λ�ã��ڶ���ֻҪ������ͷ�����������λ�þͿ����ˡ�
void BubbleSort2(int* arr, int len)
{
	assert(arr);
	assert(len > 0);
	int flag = len;
	for (int i; flag;)
	{
		i = flag;
		flag = 0;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = j;
			}
		}
	}
}

//��������

void Test()
{
	int arr[] = { 5 ,8, 9, 4 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	int arr1[] = { 3, 1, 5, 2, 8, 7, 9, 0, 6, 4 };

	ShellSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
	int arr2[] = { 3, 1, 5, 2, 8, 7, 9, 0, 6, 4 };

	SelectSort(arr2, sizeof(arr2) / sizeof(arr2[0]));

	int arr3[] = { 3, 1, 5, 2, 8, 7, 9, 0, 6, 4 };
	HeapSort(arr3, sizeof(arr3) / sizeof(arr3[0]));

	int arr4[] = { 3, 1, 5, 2, 8, 7, 9, 0, 6, 4 };
	BubbleSort2(arr4, sizeof(arr4) / sizeof(arr4[0]));
}