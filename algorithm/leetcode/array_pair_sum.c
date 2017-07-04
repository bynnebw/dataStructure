/*
**	Input: [1,4,3,2]
**	Output: 4
**	Explanation: n is 2, and 
**	the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
*/
#include <stdio.h>
#define CAL(array) sizeof(array)/sizeof(array[0])
#define MIN(a,b) (a>b) ? b : a   		//这里曾经出现过错误，要研究一下

void sortArray(int* a, int numsSize)
{
	for (int i = 0; i < numsSize - 1; i++)
	{
		int isSorted = 1;
		for (int j = 0;j < numsSize - 1; j++)
		{
			if(a[j] > a[j+1])
			{
				isSorted = 0;
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		if(isSorted) break;
	}
}
/*int min(int a, int b)
{
	if ( a >= b) return b;
}*/

int arrayPairSum(int* nums, int numsSize) {
    if(numsSize%2==0)
    {
    	//这里将数组做一次排序应该就可以了，然后两两结合计算和值，结果就是答案,采用冒泡排序会比较好。
    	int sum = 0;
    	sortArray(nums,numsSize);
    	for ( int i = 0; i < (numsSize);i ++)
    	{
    		printf("a[%d] = %d\n",i,nums[i]);
    	}



    	int temp[] = {};
    	
    	for ( int i = 0; i < (numsSize/2);i ++)
    	{
    		temp[i] = MIN(nums[i*2],nums[i*2+1]);
    	}
    	for ( int i = 0; i < (numsSize/2);i ++)
    	{
    		printf("b[%d] = %d\n",i,temp[i]);
    	}

    	for ( int i = 0; i < (numsSize/2);i ++)
    	{
			sum += temp[i];
    	}
    	printf("the sum of the result is : %d\n", sum);

    }
    else
    {
 		printf("the numsSize of the array isn't even\n");
    }
}

int main(int argc, char const *argv[])
{
	int numsSize = 0;	
	int array[] = {34,35,64,12,31,54};
	numsSize = CAL(array);
	arrayPairSum(array,numsSize);
	return 0;
}