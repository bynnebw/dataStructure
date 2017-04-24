#include <stdio.h>
#include <sys/malloc.h>
#include "DLinkList.h"

typedef struct _tag_DLinkList
{
    DLinkListNode header;
    DLinkListNode* slider;
    int length;
}TDLinkList;

DLinkList* DLinkList_Create()
{
	TDLinkList* ret = (TDLinkList*)malloc(sizeof(TDLinkList));

	if ( ret != NULL )
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}

	return ret;
}

void DLinkList_Destroy(DLinkList* list)
{
	free(list);
}

void DLinkList_Clear(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;

	if ( sList != NULL )
	{
		sList->length = 0;
		sList->header.next = NULL;
        sList->header.pre = NULL;
        sList->slider = NULL;
	}
}

int DLinkList_Length(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = -1;

	if ( sList != NULL )
	{
		ret = sList->length;
	}

	return ret;
}

int DLinkList_Insert(DLinkList* list,DLinkListNode* node, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
    int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
    int i = 0;

    if ( ret )
    {
    	DLinkListNode* current = (DLinkListNode*)sList;
        DLinkListNode* next = NULL;

        for(i = 0;(i < pos) && (current->next != NULL); i++)
        {
        	current = current->next;
        }
        next = current->next;

        current->next = node;
        node->next = next;

        if ( next != NULL )
        {
        	next->pre = node;
        }
        node->pre = current;

        if ( sList->length == 0 )
        {
        	node->pre = NULL;
        	sList->slider = node;				//这句话该怎么理解？
        }

        sList->length++;
    }
    return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list,int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
    DLinkListNode* ret = NULL;
    int i = 0;

    if ( (sList != NULL) && (0 <= pos) && (pos < sList->length) )
    {
    	DLinkListNode* current = (DLinkListNode*)sList;

    	for(i=0;i<pos;i++)
    	{
    		current = current->next;
    	}
    	ret = current->next;
    }
    return ret;
}

DLinkListNode* DLinkList_Delete(DLinkList* list,int pos)
{

}

DLinkListNode* DLinkList_Reset(DLinkList* list)
{

}

DLinkListNode* DLinkList_Current(DLinkList* list)
{

}

DLinkListNode* DLinkList_Next(DLinkList* list)
{

}

DLinkListNode* DLinkList_Pre(DLinkList* list)
{

}