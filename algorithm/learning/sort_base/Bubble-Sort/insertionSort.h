#ifndef INSERTIONSORT
#define INSERTIONSORT

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void insertionSort(T arr[],int n)
{
	for (int i = 0; i < n; i++)
	{
		T e = arr[i];
		int j;
		for(j = i;j > 0 && arr[j-1] > e;j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}


#endif