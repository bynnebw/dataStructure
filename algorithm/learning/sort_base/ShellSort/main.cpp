#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void shellSort(T arr[],int n)
{
	int h = 1;
	while(h < n/3)
		h = 3*h + 1;
	while( h>=1 ){
		for(int i = h;i < n; i++)
		{
			T e = arr[i];
			int j;
			for(j = i;j >= h && e < arr[j-h];j -= h)
				arr[j] = arr[j-h];
			arr[j] = e;
		}
		h /= 3;
	}
		
}


int main(int argc, char const *argv[])
{

	int n = 10000;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"Test for Random Array , size = "<<n<<", random range[0,"<<n<<"]"<<endl;
	
	int* arr = SortTestHelper::generateRandomArray(n,0,n);
	SortTestHelper::testSort("ShellSort",shellSort,arr,n);

	delete[] arr;

	cout<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	return 0;
}