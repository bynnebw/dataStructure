#include<iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[],int n)
{
	//最初的没有改变的插入排序算法，可以看到其实效率并不是很高
	/*for(int i = 0; i< n; i++)
	{
		for(int j = i; j > 0 && arr[j] < arr[j-1];j--)
		{
			swap(arr[j],arr[j-1]);
		}
	
	}*/

	//经过改进之后的插入排序的算法，运行效率高了很多，而且当数组更加有序的时候，效率会更加高的
	//Not really understand...	
	for (int i = 0; i < n; i++)
	{
		T e = arr[i];
		int j;	//j保存元素e应该插入的位置
		for(j = i;j > 0 && arr[j-1] > e;j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}

int main(int argc, char const *argv[])
{
	int n = 10000;

	//测试1 一般测试
	cout<<"Test for Random Array , size = "<<n<<", Random range [0,"<<n<<"]"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 =SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("insertionSort",insertionSort,arr1,n);
	SortTestHelper::testSort("SelectionSort",selectionSort,arr2,n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	//测试2 有序性更强的测试
	cout<<"Test for more ordered random array, size ="<<n<<",random range [0,3]"<<endl;
	arr1 = SortTestHelper::generateRandomArray(n,0,3);
	arr2 = SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("insertionSort",insertionSort,arr1,n);
	SortTestHelper::testSort("selectionSort",selectionSort,arr2,n);

	delete[] arr1;
	delete[] arr2;

	//测试3 测试近乎有序的数组
	int swapTimes = 100;
	cout<<"Test for Nearly ordered random array, size ="<<n<<",swap time = "<<swapTimes<<endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("insertionSort",insertionSort,arr1,n);
	SortTestHelper::testSort("selectionSort",selectionSort,arr2,n);

	delete[] arr1;
	delete[] arr2;
	
	return 0;
}