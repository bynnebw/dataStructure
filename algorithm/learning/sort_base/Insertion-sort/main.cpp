#include <iostream>
#include <algorithm>
#include "SelectionSort.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[],int n)
{
	for (int i = 1; i < n; i++)
	{
		//寻找元素arr[i]合适的插入位置
		//
		//
		for(int j = i;j > 0;j--)
		{
			if (arr[j] < arr[j -1])
			{
				swap(arr[j],arr[j-1]);
			}
			else
			{
				break;
			}
		}

		//简洁版
		/*for(int j = i; j > 0 && arr[j] < arr[j-1];j--)
		{
			swap(arr[j],arr[j-1]);
		}*/
	}
}



int main(int argc, char const *argv[])
{
	int n = 10000;
	cout<<endl;
	cout<<"以下是两种算法的运行时间"<<endl;
	cout<<"Test for Random Array , size = "<<n<<", Random range [0,"<<n<<"]"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 =SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("insertionSort",insertionSort,arr1,n);
	SortTestHelper::testSort("SelectionSort",selectionSort,arr2,n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	return 0;
}