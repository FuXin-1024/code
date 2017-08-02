#include<iostream>
#include<assert.h>
using namespace std;

//直接插入排序
void InsertSort(int* arr, int len)//升序排列
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

//选择排序
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

//堆排序
//升序建大堆

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
	//堆顶与最后一个数交换，除最后一个数，调整成大堆。循环。保证每个堆的最后一个数是最大的
	for (int i = len - 1; i >= 0; --i)
	{
		swap(arr[0], arr[i]);
		AdjustDown(arr,i, 0);
	}
}

//冒泡排序
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

// 进一步优化，假如数组有100个，后面90个都已排好序且都大于前面10个数字，
//那么在第一趟遍历后，最后发生交换的位置必定小于10，且这个位置之后的数据必定已经有序了，
//记录下这位置，第二次只要从数组头部遍历到这个位置就可以了。
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

//归并排序
void _MergeSort(int* src, int* dst, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	//[left,mid],[mid+1,right]
	_MergeSort(src, dst, left, mid);
	_MergeSort(src, dst, mid + 1, right);

	int begin1 = left; int begin2 = mid + 1;
	int index = 0;
	
	while (begin1 <= mid && begin2 <= right)
	{
		if (src[begin1] < src[begin2])
			dst[index++] = src[begin1++];
		else
			dst[index++] = src[begin2++];
	}

	while (begin1 <= mid)
		dst[index++] = src[begin1++];
	while (begin2 < right)
		dst[index++] = src[begin2++];

	int i = 0; int j = left;
	while (i < index)
		src[j++] = dst[i++];
}
void MergeSort(int* arr, int len)
{
	assert(arr);
	assert(len > 0);
	int *tmp = new int[len];
	_MergeSort(arr, tmp, 0, len - 1);
}

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

	int arr5[] = { 3, 1, 5, 2, 8, 7, 9, 0, 6, 4 };
	MergeSort(arr5, sizeof(arr5) / sizeof(arr5[0]));
}