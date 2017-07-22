//辅助头文件，主要功能：
//随机生成数组，打印随机生成的数组


#ifndef SORTTESTHELPER_H_
#define SORTTESTHELPER_H_

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>	//I got to found out what the cassert means
#include <string>

using namespace std;

namespace SortTestHelper
{
	int* generateRandomArray(int n,int rangeL,int rangeR)
	{
		assert(rangeL <= rangeR);

		int* arr = new int[n];

		srand(time(NULL));	//设置随机种子

		for (int i = 0; i < n; ++i)
		{
			arr[i] = rand() % (rangeR -rangeL + 1) + rangeL;
		}
		return arr;
	}

	int* generateNearlyOrderedArray(int n,int swapTimes)	//怎么办到的，实现更加有序的数组？
	{
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}

		srand(time(NULL));
		for(int	i = 0;i <swapTimes;i++)
		{
			int posx = rand()%n;
			int posy = rand()%n;
			swap(arr[posx],arr[posy]);
		}

		return arr;
	}

	int* copyIntArray(int a[],int n)
	{
		int* arr = new int[n];
		copy(a,a+n,arr);			//STL的拷贝,good
		return arr;
	}

	template<typename T>
	void printArray(T arr[],int n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout<<arr[i]<<endl;
		}
	}

	template<typename T>
	bool isSorted(T arr[],int n)
	{
		for (int i = 0; i < n-1; i++)
		{
			if (arr[i] > arr[i+1])
			{
				return false;	
			}
			return true;
		}
	}

	template<typename T>
	void testSort(const string& sortName,void (*sort)(T[],int),T arr[],int n)
	{
		clock_t startTime = clock();
		sort(arr,n);
		clock_t endTime = clock();

		//assert(isSorted(arr,n));
		cout<<sortName<<":"<<double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}
};

#endif