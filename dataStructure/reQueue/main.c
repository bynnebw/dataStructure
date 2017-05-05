#include <stdio.h>
#include <stdlib.h>
#include "SQueue.h"

int main(int argc, char const *argv[])
{
    SQueue* queue = SQueue_Create();
    int a[10] = {0};
    int i = 0;

    for(i = 0; i < 10 ; i++)
    {
        a[i] = i + 1;
        SQueue_Append(queue,a+i);
    }

    printf("Header:%d\n", *(int*)SQueue_Header(queue)); 
    printf("Length:%d\n", SQueue_Length(queue));

    for (int i = 0; i < 5; i++)
    {
    	printf("Retrieve: %d\n",*(int*)SQueue_Retrieve(queue));
    }

	printf("Header:%d\n", *(int*)SQueue_Header(queue)); 
    printf("Length:%d\n", SQueue_Length(queue));

    for(i = 0; i < 10;i ++)
    {
    	a[i] = i + 1;
    	SQueue_Append(queue,a+i);
    }

    while(SQueue_Length(queue) > 0) //这个用栈实现的队列，对于长度本身的capacity是没有限制的哦！所以不管数组的大小是多少，都可以尽可能的往队列里装～
    {
    	printf("Retrieve: %d\n",*(int*)SQueue_Retrieve(queue));
    }    

    SQueue_Destroy(queue);

    return 0;
}