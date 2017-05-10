#include <stdio.h>

void println(int array[],int len)
{
	int i = 0;
	for (int i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int array[],int i,int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int partition(int array[],int low,int high)	//划分函数
{
	int pv = array[low];	//这里应该反复看一下解释。
	while( low < high )
	{
		while( (low < high) && (array[high] >= pv ) )	//先从高处开始扫描，不断的减减，直到不符合条件就转到从低端开始不断增序，比较。
		{
			high--;
		}
		swap(array,low,high);

		while( (low<high) && (array[low] < pv))
		{
			low	++;
		}
		swap(array,low,high);
	}
	return low;
}

void QSort(int array[],int low,int high)
{
	if ( low < high )		//这里主要也是递归的思想，不断调用Qsort这个函数，就实现了不断的划分。
	{
		int pivot = partition(array,low,high);

		QSort(array,low,pivot-1);
		QSort(array,pivot+1,high);
	}
}

void QuickSort(int array[],int len)		//利用递归的思想
{
	QSort(array,0,len-1);
}

int main(int argc, char const *argv[])
{	
	int array[] = {21,25,49,25,16,8};
	int len = sizeof(array) / sizeof(*array);

	println(array,len);

	QuickSort(array,len);

	println(array,len);

	return 0;
}