#include <stdio.h>

/*
**	This is the basic idea of the ShellSort 
**	Algoritm.
** ShellSort is consisit of the InsertSortation
** It feels more like the FFT algorithm
*/

void println(int array[],int len)
{
	int i = 0;

	for (int i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}

void swap(int array[], int i , int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void ShellSort(int array[],int len) 		//This is main core of the algorithm
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;

	do
	{
		
		
	}while( gap > 1 );

}

int main(int argc, char const *argv[])
{
	int array[] = {21,25,49,25,16,8};
	int len = sizeof(array) / sizeof(*array);

	println(array,len);	
	return 0;
}