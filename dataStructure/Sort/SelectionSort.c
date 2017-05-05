#include <stdio.h>

/*
**	快速选择算法，将前面的元素分别与后面的元素进行比较，如果后面的元素更小，那么二者之间交换位置
**	然后继续进行比较，每循环比较一趟，整个数组的长度就会减一。排序的核心操作就是交换与比较。
**	每个元素不断的雨后面的元素进行比较，比较符合条件的话就进行两两交换。
*/

void println(int array[], int len)
{
	int i = 0;

	for( i = 0; i < len; i ++)
	{
		printf("%d\n", array[i]);
	}

	printf("\n");
}

void swap(int array[],int i, int j)
{
	int temp = array[i];
	
	array[i] = array[j];
	
	array[j] = temp;
}

void SelectionSort(int array[],int len)
{
	int i = 0;
	int j = 0;
	int k = -1;

	for (int i = 0; i < len; i++)	//核心算法其实在这个地方：首先从数组的首元素开始，不断向后移动。此时不断的将两两比较，做交换。
	{
		k = i;		//k其实相当于是标记的指针，只不过这里是数组，所以用下标来进行标记。

		for (j = i; j < len; j++)
		{
			if( array[j] < array[k] )
			{
				k = j;
			}
		}
		swap(array,i,k);	//交换下标是i和k的元素
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {34,543,23,124,534,645,332,2,45,233,12};
	int length = sizeof(array) / sizeof(*array);
	println(array,length);

	SelectionSort(array,length);

	println(array,length);

	return 0;
}