//辅助头文件，主要功能：
//随机生成数组，打印随机生成的数组


#ifndef SORTTESTHELPER_H_
#define SORTTESTHELPER_H_

#include <iostream>
#include <ctime>
#include <cassert>	//I got to found out what the cassert means

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

	template<typename T>
	void printArray(T arr[],int n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout<<arr[i]<<endl;
		}
	}
}

#endif