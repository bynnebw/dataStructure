#include <iostream>
#include <algorithm>
#include "Heap.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void heapSort2(T arr[],int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
	for( int i = n-1; i >= 0; i -- )
	{
		arr[i] = maxheap.extractMax();
	}
}

template<typename T>
void heapSort1(T arr[],int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for( int i = 0; i < n; i ++ )
	{
		maxheap.insert(arr[i]);
	}

	for( int i = n-1; i >= 0; i -- )
	{
		arr[i] = maxheap.extractMax();
	}
}

int main(int argc, char const *argv[])
{
	int n = 100000;
	//测试1 一般性测试

	cout<<"Test for Random Array, size = "<<n<<" ,random range [0, "<<n<<"]"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 = SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("Heap Sort 1",heapSort1,arr1,n);
	SortTestHelper::testSort("Heap Sort 2",heapSort2,arr2,n);

	delete[] arr1;
	delete[] arr2;

	return 0;
}