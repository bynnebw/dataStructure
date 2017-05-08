#include <stdio.h>

/*
**	This is the demo code of the BubbleSort algorithm
**	THe BubbleSort method is the third one of the mainly
**	mainly basic method in the sort method algorithm.
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

void swap(int array[],int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;	
}

void BubbleSort(int array[],int len)		// Here is the mainly core idea of the algorithm.
{
	int i = 0;
	int j = 0;
	int exchange = 1;			//The idea of using a flag which is called exchange is pretty good.

	for (int i = 0;( i<len ) && exchange ; i++)	//You just doing the scanning process one by one until you reach the end of the condition.
	{
		exchange = 0;

		for (j = len -1;j > i ; j--)
		{
			if (array[j]<array[j-1])
			{
				swap(array,j,j-1);
				exchange = 1;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {21,25,49,25,16,8};
	int len = sizeof(array) / sizeof(*array);

	println(array,len);

	BubbleSort(array,len);

	println(array,len);

	return 0;
}