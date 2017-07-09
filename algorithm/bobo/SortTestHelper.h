#ifndef _SORTTESTHELPER_H_
#define _SORTTESTHELPER_H_

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelp{
	int* generateRandomArray(int n,int rangeL,int rangeR){

		int* arr = new int[n];
		srand(time(NULL));		//设置随机种子
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR-rangeL+1) + rangeL;
		}
		return arr;
	}
}


#endif