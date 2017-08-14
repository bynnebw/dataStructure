#include <iostream>
#include <algorithm>

using namespace std;




template<typename T>
void heapSort(T arr[],int n)
{
	for( int i = (n-1)/2; i >= 0; i -- )
		__shiftDown2(arr,n,i);
	
	for( int i = n-1; i > 0; i -- )
		swap( arr[0] , arr[i] );
		__shiftDown2(arr,i,0);
}

int main(int argc, char const *argv[])
{

	return 0;
}