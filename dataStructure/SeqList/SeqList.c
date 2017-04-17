#include <stdio.h>
#include <sys/malloc.h>
#include "SeqList.h"

typedef unsigned int TSeqListNode;

typedef struct _tag_seqlist 
{
	int capacity;
	int length;
	TSeqListNode* node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	TSeqList* ret = NULL;
	
	if (capacity >= 0)
	{
		ret = (TSeqList*)malloc(sizeof(TSeqList*) + capacity * sizeof(TSeqListNode*));
	}

	if (ret != NULL)
	{
		ret -> capacity = capacity;
		ret -> length = 0;
		ret -> node = (TSeqListNode*)(ret+1);
	}

	return ret;
}
void SeqList_Destroy(SeqList* list)
{
	free(list);
}
void SeqList_Clear(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;

	if (sList != NULL)
	{
		sList -> length = 0;
	}
}

int SeqList_Capacity(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;

	if (sList != NULL)
	{
		ret = sList -> capacity;
	}
	return ret;
}
int SeqList_Length(SeqList* list)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;

	if (sList != NULL)
	{
		ret = sList -> length;
	}
	return ret;	
}
int SeqList_Insert(SeqList* list,SeqListNode* node,int pos)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = (sList != NULL);
	int i = 0;

	ret = ret && (sList -> length + 1 <= sList -> capacity);
	ret = ret && (0 <= pos);

	if (ret)
	{
		if (pos >= sList->length) 
		{
			pos = sList->length;
		}
		for (int i = sList->length; i > pos; i--)
		{
			sList->node[i] = sList->node[i-1];
		}
		sList->node[i] = (TSeqListNode)node;

		sList->length ++;
	}
	return ret;
}

SeqListNode* SeqList_Get(SeqList* list,int pos)
{
	TSeqList* sList = (TSeqList*)list;
	
}
SeqListNode* SeqList_Delete(SeqList* list,int pos)
{

}