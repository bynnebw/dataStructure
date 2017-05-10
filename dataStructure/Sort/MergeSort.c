#include <stdio.h>
#include <sys/malloc.h>

void println(int array[], int len)
{
    int i = 0;
    
    for(i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    
    array[i] = array[j];
    
    array[j] = temp;
}

void Merge(int src[],int des[],int low,int mid,int high)
{
	
}

void MSort(int src[],int des[],int low,int high,int max)
{

}

void MergeSort(int array[],int len)
{

}

int main(int argc, char const *argv[])
{
	int array[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(array) / sizeof(*array); 
    
    println(array, len);
	return 0;
}