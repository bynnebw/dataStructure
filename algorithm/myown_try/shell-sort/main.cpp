#include <iostream>
#include "sortTestHelper.h"

using namespace std;

template<typename T>
void shellsort(T arr[],int n)
{
	//mainly idea：分组、进行插入排序
	int h = 1;
	while(h < n/3)
		h = 3*h + 1;
	while( h >= 1)
	{
		for(int i = h;i < n;i++)
		{
			T e = arr[i];
			int j;
			for(j = i; j >= h && e < arr[j-h];j -= h)
				arr[j] = arr[j-h];
			arr[j] = e;
		}

		h /= 3;
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}