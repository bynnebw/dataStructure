#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;
//使用递归的实现方式效率还是要低很多。
//using binary search method to find the exact number that I wanna find.
// this is the method without using the binary search method.
template<typename T>
int binarySearch(T arr[],int n,T target)
{	
	int l = 0, r = n - 1;
	while( l <= r )
	{
		int mid = l + (r-l)/2;
		if( arr[mid] == target )
			return mid;
		if( arr[mid] > target )
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

//using the recursion method to realize the binary search method.
template<typename T>
int __binarySearch2(T arr[],int l,int r,T target)
{
	if( l > r )
		return -1;

	int mid = (l+r)/2;
	
	if( arr[mid] == target )
		return mid;
	else if( arr[mid] > target )
		return __binarySearch2(arr,0,mid-1,target);
	else
		return __binarySearch2(arr,mid+1,r,target);
}

template<typename T>
int binarySearch2(T arr[],int n,T target)
{
	return __binarySearch2( arr,0,n-1,target );
}


int main(int argc, char const *argv[])
{
	int n = 100000;
	int* a = new int[n];
	
	for( int i = 0; i < n ; i ++ )
		a[i] = i;

	clock_t startTime = clock();

	for( int i = 0; i < 2*n; i ++ )
	{
		int v = binarySearch(a,n,i);
		if( i < n )
			assert( v == i );
		else
			assert( v == -1 );
	}

	clock_t endTime = clock();

	cout<<"binarySearch (without recursion): "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s"<<endl;

	//testing the method using the recursion method
	startTime = clock();

	for( int i = 0; i < 2*n; i ++ )
	{
		int v = binarySearch2(a,n,i);
		if( i < n )
			assert( v == i );
		else
			assert( v == -1 );
	}


	endTime = clock();
	cout<<"binarySearch (without recursion): "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s"<<endl;

	return 0;
}