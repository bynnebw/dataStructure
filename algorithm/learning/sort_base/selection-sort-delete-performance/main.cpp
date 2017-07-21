#include <iostream>
#include "SortTestHelper.h"

using namespace std;

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
	int N = 10000;
	int* arr = SortTestHelper::generateRandomArray(N,0,N);
	SortTestHelper::testSort("selectionSort",selectionSort,arr,N);
	delete[] arr;
	SortTestHelper::printArray(arr,N);

	return 0;
}