#include <stdio.h>
#include <sys/malloc.h>
#include "LinkStack.h"
#include "SQueue.h"

typedef struct _tag_SQueue
{
    LinkStack* inStack;
    LinkStack* outStack;
} TSQueue;

SQueue* SQueue_Create()
{
    TSQueue* ret = (TSQueue*)malloc(sizeof(TSQueue));

    if ( ret != NULL )
    {
        ret->inStack = LinkStack_Create();
        ret->outStack = LinkStack_Create(); //创建好之后还不行，因为没人能保证创建好之后两个栈都不为空

        if ( (ret->inStack == NULL) || (ret->outStack == NULL) )    //所以必须对两个栈做检测，看两个栈是否创建成功,还有一个严重的问题，这里我曾经写的是“与”，但其实应该是“或”。这里应该是一个逻辑上的失误，但是没想到逻辑的错误会导致整个程序运行不起来。
        {
            LinkStack_Destroy(ret->inStack);
            LinkStack_Destroy(ret->outStack);

            free(ret);

            ret = NULL;
        }
    }
    return ret;
}

void SQueue_Destroy(SQueue* queue)
{
    SQueue_Clear(queue);    //因为使用的是栈，所以在destroy之前一定要先clear，以免内存泄漏
    free(queue);
}

void SQueue_Clear(SQueue* queue)    //因为队列是由两个栈所组成的，所以队列的clear也就是两个栈的clear。
{
    TSQueue* sQueue = (TSQueue*)queue;

    if ( sQueue != NULL )
    {
        LinkStack_Clear(sQueue->inStack);
        LinkStack_Clear(sQueue->outStack);
    }
}

int SQueue_Append(SQueue* queue, void* item)
{
    TSQueue* sQueue = (TSQueue*)queue;

    if ( sQueue != NULL )
    {
        LinkStack_Push(sQueue->inStack,item);
    }
}

void* SQueue_Retrieve(SQueue* queue)
{
    TSQueue* sQueue = (TSQueue*)queue;
    void* ret = NULL;

    if ( sQueue != NULL )
    {
        if ( LinkStack_Size(sQueue->outStack) == 0 )
        {
            while( LinkStack_Size(sQueue->inStack) > 0 )
            {
                LinkStack_Push(sQueue->outStack,LinkStack_Pop(sQueue->inStack));
            }
        }

        ret = LinkStack_Pop(sQueue->outStack);
    }
    return ret;
}

void* SQueue_Header(SQueue* queue)
{
    TSQueue* sQueue = (TSQueue*)queue;
    void* ret = NULL;

    if ( sQueue != NULL )
    {
        if ( LinkStack_Size(sQueue->outStack) == 0 )
        {
            while( LinkStack_Size(sQueue->inStack) > 0 )
            {
                LinkStack_Push(sQueue->outStack,LinkStack_Pop(sQueue->inStack)); //这里曾经有一个失误，压入outStack栈的元素，一定需要是在inStack栈弹出的元素才行。
            }
        }
        ret = LinkStack_Top(sQueue->outStack);
    }
    return ret;
}

int SQueue_Length(SQueue* queue)
{
    TSQueue* sQueue = (TSQueue*)queue;
    int ret = -1;

    if ( sQueue != NULL )
    {
        ret = LinkStack_Size(sQueue->inStack) + LinkStack_Size(sQueue->outStack);
    }
    return ret;
}
