#include <stdio.h>
#include <sys/malloc.h>
#include "LinkList.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));

	if ( ret != NULL )
	{
		ret->length = 0;
		ret->header.next = NULL;
	}

	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	free(list);
}

void LinkList_Clear(LinkList* list)
{
	TLinkList* sList = (TLinkList*)list;

	if ( sList != NULL )
	{
		sList->length = 0;
		sList->header.next = NULL;
	}
}

int LinkList_Length(LinkList* list)
{
	TLinkList* sList = (TLinkList*)list;
	int ret = -1;

	if ( sList != NULL )
	{
		ret = sList->length;
	}
	return ret;
}

int LinkList_Insert(LinkList* list,LinkListNode* node,int pos)
{

}

LinkListNode* LinkList_Get(LinkList* list,int pos)
{

}

LinkListNode* LinkList_Delete(LinkList* list,int pos)
{

}