#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[],int n)
{
	/*for( int i = 0; i < n; i++)
	{
		for(int j = i + 1; j > 0;j--)
		{
			if (arr[j] < arr[j-1])
			{
				swap(arr[j-1],arr[j]);
			}
			else
			{
				break;
			}
		}
	}*/
	//这个插入过程到底是怎样的
	for(int i = 1; i < n; i++)
	{
		T e = arr[i];
		int j;//j保存元素e应该插入的位置
		for(j = i;j > 0 && arr[j-1] > e;j--)
			arr[j] = arr[j-1];
		arr[j] = e;
	}
} 

template<typename T>
void printArray(T arr[],int n)
{
	for(int i = 0; i< n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int a[9] = {7,1,3,2,9,4,5,6,8};
	printArray(a,9);
	insertionSort(a,9);
	printArray(a,9);
	return 0;
}