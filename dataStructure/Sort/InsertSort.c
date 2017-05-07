#include <stdio.h>
/*
**	插入排序
**
*/

void println(int array[],int len)
{
	int i = 0;

	for (int i = 0; i < len; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}

void swap(int array[],int i,int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void InsertSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;

	for(i = 1;i < len; i ++)
	{
		k = i;
		temp = array[k];

		for(j = i-1;(j>=0) && (array[j]>temp);j--)  //目前还不是很理解这部分的原理啊。。
		{
			array[j+1] = array[j];
			k = j;
		}

		array[k] = temp;
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {21,24,58,45,32,16,8,4,32};
	int len = sizeof(array) / sizeof(*array);
	println(array,len);

	InsertSort(array,len);

	println(array,len);

	return 0;
}