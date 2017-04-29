#include <stdio.h>
#include <sys/malloc.h>
#include "SeqList.h"
#include "SeqStack.h"

int	main(int argc, char const *argv[])
{
	SeqStack* stack = SeqStack_Create(20);
	int a[10];
	int i = 0;

	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
		SeqStack_Push(stack,a+i);
	}

	printf("Top:%d\n", *(int*)SeqStack_Top(stack));
	printf("Capacity:%d\n", SeqStack_Capacity(stack));
	printf("Length:%d\n", SeqStack_Size(stack));

	while( SeqStack_Size(stack) > 0)
	{
		printf("Pop: %d\n", *(int*)SeqStack_Pop(stack));
	}

	SeqStack_Destroy(stack);

	return 0;
}