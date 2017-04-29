#include "SeqStack.h"
#include "SeqList.h"

/*
**  because of using the codes that I've wittern in the past,
**	luckily the code can be used in the situation of the SeqStack
**	The resaon of this is because of the the special kind of "void".
**	And that's the very basic reason of the resuable of the code like this.
*/	

SeqStack* SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}

void SeqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);
}

void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
}

int SeqStack_Push(SeqStack* stack, void* item)
{
	return SeqList_Insert(stack,item,SeqList_Length(stack));
}

int SeqStack_Pop(SeqStack* stack)
{
	SeqList_Delete(stack,SeqList_Length(stack) - 1);
}

void SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack,SeqList_Length(stack) - 1);
}	

int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}