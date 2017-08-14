#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "insertionSort.h"
using namespace std;

template<typename T>
void __merge(T arr[],int l,int mid,int r)
{
	T aux[r-l+1];
	for( int i = l; i <= r; i ++ )
	{
		aux[i-l] = arr[i];
	}
	int i = l,j = mid+1;
	for( int k = l; k <= r; k ++ )
	{
		if ( l > mid )		//做一些数组越界的处理
		{
			arr[k] = aux[j-l];
			j ++;
		}
		else if ( j > r )
		{
			arr[k] = aux[i-l];
			i ++;
		}
		else if ( aux[i-l] < aux[j-l] )
		{
			arr[k] = aux[i-l];
			i ++;
		}
		else
		{
			arr[k] = aux[j-l];
			j ++;
		}
	}
}

template<typename T>
void __mergeSort(T arr[],int l,int r)
{
	if( l >= r )	//递归到底的情况
		return;

	int mid = (l+r) / 2;

	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid+1,r);
	if ( arr[mid] > arr[mid+1] )
	{
		__merge(arr,l,mid,r);		//递归到底之后进行归并	
	}
	
}

template<typename T>
void mergeSort(T arr[],int n)
{
	__mergeSort(arr,0,n-1);
}

int main(int argc, char const *argv[])
{
	int n = 50000;

	cout<<"-----------------------------------"<<endl;

	int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 = SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("insertionSort",insertionSort,arr1,n);
	SortTestHelper::testSort("mergeSort",mergeSort,arr2,n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;

	cout<<"-----------------------------------"<<endl;
	return 0;
}