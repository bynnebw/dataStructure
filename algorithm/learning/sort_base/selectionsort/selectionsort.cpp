//使用选择排序进行对数组的排序

#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int arr[],int length)
{
	for (int i = 0; i < length; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i],arr[minIndex]);
	}
}

int main(int argc, char const *argv[])
{
	int a[10] = {2,4,1,6,3,7,5,0,9,10};
	selectionSort(a,10);
	for (int i = 0; i < 10; ++i)
		{
			cout<<a[i]<<endl;
		}	
	return 0;
}