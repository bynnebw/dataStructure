#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

int main(int argc, char const *argv[])
{
    LinkQueue* queue = LinkQueue_Create();
    int a[10] = {0};
    int i = 0;

    for(i = 0; i < 10 ; i++)
    {
        a[i] = i + 1;
        LinkQueue_Append(queue,a+i);
    }

    printf("Header:%d\n", *(int*)LinkQueue_Header(queue)); 
    printf("Length:%d\n", LinkQueue_Length(queue));

    for (int i = 0; i < 5; i++)
    {
    	printf("Retrieve: %d\n",*(int*)LinkQueue_Retrieve(queue));
    }

	printf("Header:%d\n", *(int*)LinkQueue_Header(queue)); 
    printf("Length:%d\n", LinkQueue_Length(queue));

    for(i = 0; i < 10;i ++)
    {
    	a[i] = i + 1;
    	LinkQueue_Append(queue,a+i);
    }

    while(LinkQueue_Length(queue) > 0) //这个用栈实现的队列，对于长度本身的capacity是没有限制的哦！所以不管数组的大小是多少，都可以尽可能的往队列里装～
    {
    	printf("Retrieve: %d\n",*(int*)LinkQueue_Retrieve(queue));
    }    

    LinkQueue_Destroy(queue);

    return 0;
}