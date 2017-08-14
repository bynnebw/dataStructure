#include <iostream>
#include <algorithm>
#include <ctime>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;

template<typename T>
int _partition2(T arr[],int l,int r)
{
	swap( arr[l], arr[rand()%(r-l+1)+l]);
}

template<typename T>
void _quickSort(T arr[],int l,int r)
{
	if( r-l <= 15 )
	{
		insertionSort(arr,l,r);
		return;
	}

	int p = _partition2(arr,l,r);
	_quickSort(arr,l,p-1);
	_quickSort(arr,p+1,r);
}

template<typename T>
void quickSort(T arr[],int n)
{
	srand(time(NULL));
	_quickSort(arr,0,n-1);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}