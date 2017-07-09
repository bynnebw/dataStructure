#include <iostream>
#include "SortTestHelper.h"

using namespace std;
//using namespace SortTestHelp;

int main(int argc, char const *argv[])
{
	int n = 10000;
	int rangeL = 0;
	int rangeR = 10000;
	int* arr = SortTestHelp::generateRandomArray(n,rangeL,rangeR);

	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<endl;
	}

	return 0;
}