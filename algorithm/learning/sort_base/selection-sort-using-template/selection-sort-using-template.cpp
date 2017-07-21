#include <iostream>
#include "student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[],int length)
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
	//测试模版函数，传入整型数组
	int a[10] = {2,5,6,1,0,4,3,7,9,8};
	selectionSort(a,10);
	for (int i = 0; i < 10; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	//测试模版函数，传入浮点数组

	float b[4] = {4.4,3.3,2.2,1.1};
	selectionSort(b,4);
	for (int i = 0; i < 4; ++i)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;

	//测试模版函数，传入字符串数组
	string c[4] = {"D","B","C","A"};
	selectionSort(c,4);
	for (int i = 0; i < 4; ++i)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
	
	//测试模版函数，传入自定义结构体Student数组
	Student d[4] = {{"D",90},{"C",100},{"B",95},{"A",95}};
	selectionSort(d,4);
	for (int i = 0; i < 4; ++i)
	{
		cout<<d[i];
	}
	cout<<endl;

	return 0;
}