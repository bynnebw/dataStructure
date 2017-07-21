#include <iostream>
#include "SortTestHelper.h"

template<typename T>
void selectionSort(T arr[],int length)
{
	for (int i = 0; i < length; ++i)
	{
		int minIndex = i;

		for (int j = i + 1; j < length; j ++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i],arr[minIndex]);
	}
}

int main(int argc, char const *argv[])
{
	//测试排序算法辅助函数
	int N = 10000;
	int* arr = SortTestHelper::generateRandomArray(N,0,N);
	selectionSort(arr,N);
	SortTestHelper::printArray(arr,N);

	return 0;
}