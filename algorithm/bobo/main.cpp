#include <iostream>
#include "SortTestHelper.h"

using namespace std;

void selectSort(int arr[],int n)
{
	for (int i = 0; i < n; i++)
	{
		//寻找[i,n)区间范围内的最小值
		int minIndex = i;
		for( int j = i+1; j < n ; j ++)
		{
			if ( arr[j] < arr[minIndex] )
			{
				minIndex = j;
			}
		}
		swap(arr[i],arr[minIndex]);		//之前把swap放到for j的循环里，导致程序出错
	}
}


int main(int argc, char const *argv[])
{
	int n = 10;
	int rangeL = 0;
	int rangeR = 10;
	int* arr = SortTestHelp::generateRandomArray(n,rangeL,rangeR);
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<endl;
	}

	cout<<"this is a divided line"<<endl;

	selectSort(arr,n);

	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<endl;
	}

	return 0;
}