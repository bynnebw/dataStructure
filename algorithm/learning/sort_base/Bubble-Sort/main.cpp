#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "insertionSort.h"

using namespace std;

template<typename T>
void bubbleSort(T arr[],int n)
{
	bool swapped;	//What's the actual use of the swapp
	do{
		swapped = false;

		for (int i = 1; i < n; i++)
		{
			if (arr[i-1] > arr[i])
			{
				swap(arr[i-1],arr[i]);
				swapped = true;
			}
		}
		n--;
	}while(swapped);
}

int main(int argc, char const *argv[])
{
	int n = 100000;


	//Test for random array
	cout<<"Test for Random Array, size ="<<n<<", random range [0,"<<n<<"]"<<endl;

	int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 = SortTestHelper::copyIntArray(arr1,n);
	int* arr3 = SortTestHelper::copyIntArray(arr1,n);

	SortTestHelper::testSort("SelectionSort",selectionSort,arr1,n);	
	SortTestHelper::testSort("insertionSort",insertionSort,arr2,n);	
	SortTestHelper::testSort("Bubble sort",bubbleSort,arr3,n);	

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout<<endl;

	//Test for


	return 0;
}