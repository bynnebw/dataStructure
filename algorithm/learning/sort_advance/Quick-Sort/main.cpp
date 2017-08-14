#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
int __partition(T arr[],int l,int r)
{
	T v = arr[l];

	int j = l;
	for ( int i = l+1 ; i <= r ; i ++ )
	{
		/*if( arr[i] < v )
		{
			j ++;
			swap( arr[j] , arr[i] ); 
		}*/

		if( arr[i] < v )
		{
			swap( arr[j+1] , arr[i] );
			j ++;
		}
	}
	swap( arr[l] , arr[j] );
	return j;
}

template<typename T>
void __quickSort(T arr[],int l,int r)
{
	if ( l >= r)
		return;
	int p = __partition(arr,l,r);
	__quickSort(arr,l,p-1);
	__quickSort(arr,p+1,r);
}

template<typename T>
void quickSort(T arr[],int n)
{
	__quickSort(arr,0,n-1);
}

int main(int argc, char const *argv[])
{
	int n = 100000;
	cout<<"------------------------------"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
	//int* arr2 = SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("quickSort",quickSort,arr1,n);

	delete[] arr1;

	cout<<"------------------------------"<<endl;
	return 0;
}