#include <stdio.h>

void println(int array[],int len)
{
	int i = 0;

	for (int i = 0; i < len; i++)
	{
		printf("%d", array[i]);
	}

	printf("\n");
}

void swap(int array[], int i , int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int main(int argc, char const *argv[])
{
	int array[] = {21,25,49,25,16,8};
	return 0;
}