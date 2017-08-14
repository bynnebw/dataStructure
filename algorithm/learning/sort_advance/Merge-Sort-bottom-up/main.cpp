#include <iostream>
#include "MergeSort.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void mergeSortBU(T arr[],int n)
{
	for ( int sz = 1; sz <= n; sz += sz )	//对进行merge的元素个数进行遍历
	{
		for ( int i = 0; i < n; i += sz + sz )		//每一轮在归并元素中起始的元素位置
		{
			__merge(arr, i , i + sz - 1, min(i+sz+sz-1,n-1) );
		}
	}
}

int main(int argc, char const *argv[])
{
	int n = 1000000;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"Test for Random Array, size = "<<n<<"random range [0, "<<n<<"]"<<endl;
	int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 = SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("MergeSort",mergeSort,arr1,n);
	SortTestHelper::testSort("MergeSort Bottom Up",mergeSortBU,arr2,n);

	delete[] arr1;
	delete[] arr2;

	cout<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	return 0;
}