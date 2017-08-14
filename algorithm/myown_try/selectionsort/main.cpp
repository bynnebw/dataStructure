#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[],int n)
{
	for ( int i = 0; i < n; i++)
	{
		int minIndex = i;
		for ( int j = i;j < n; j++)
		{
			if(arr[minIndex] > arr[j])
				minIndex = j;
		}
		swap(arr[i],arr[minIndex]);
	}
}

template<typename T>
void printArray(T arr[],int n)
{
	for(int i = 0; i < n; i ++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	/*int arr[9] = {7,1,3,2,9,4,5,6,8};
	printArray(arr,9);
	selectionSort(arr,9);
	printArray(arr,9);
	*/

	int n = 100000;

	cout<<"-----------------------------------------------------"<<endl;	
	cout<<"随机生成数组，容量大小为："<<n<<endl;

	int* arr = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 = SortTestHelper::generateNearlyOrderedArray(n,100);

	SortTestHelper::testSort("对完全无序的数组进行插入排序",selectionSort,arr,n);
	SortTestHelper::testSort("对近乎有序的数组进行插入排序",selectionSort,arr2,n);
	cout<<endl;
	cout<<"-----------------------------------------------------"<<endl;
	return 0;
}