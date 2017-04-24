#include <stdio.h>
#include <sys/malloc.h>
#include "CircleList.h"

//typedef unsigned int TCircleList;

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;		//这个“游标” 是干什么用的？
	int length;
}TCircleList;


CircleList* CircleList_Create()
{
	TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
}

void CircleList_Destroy(CircleList* list)
{
	free(list);
}

void CircleList_Clear(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;

	if ( sList != NULL ) 
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->slider = NULL;
	}
}

int CircleList_Length(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	int ret = -1;

	if ( sList != NULL )
	{
		ret = sList->length;
	}

	return ret;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	TCircleList* sList = (TCircleList*)list;
	int ret = (sList != NULL) && (0 <= pos) && (node != NULL);
	int i = 0;

	if ( ret )
	{
		CircleListNode* current = (CircleList*)sList;

		for(i = 0;(i < pos) && (current->next != NULL);i++)
		{
			current = current->next;
		}
		
		node->next = current->next;
		current->next = node;

		if ( sList->length == 0)
		{
			sList->slider = node;
			node->next = node;
		}

		sList->length++;
	}

	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if ( (sList != NULL) && (pos >= 0) )
	{
		CircleListNode* current = (CircleListNode*)sList;

		for(i = 0; i < pos ; i++)
		{
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if ( (sList != NULL) && (pos >= 0) )
	{
		CircleListNode* current = (CircleListNode*)sList;
		CircleListNode* first = sList->header.next;				//在删除前先对第一个元素进行标记
		CircleListNode* last = (CircleListNode*)CircleList_Get(sList,sList->length - 1);	//所谓基于“气宗”门道，就是利用之前已经写好的函数来直接使用

		for(i=0;i < pos;i++)
		{
			current = current->next;
		}
		
		ret = current->next;			//得到所要删除的元素节点
		current->next = ret->next;		//将要删除的节点的上一个节点的next指针，略过该要删除的节点，而指向删除节点的下一个节点。

		sList->length--;

		if ( first == ret )					//这里实际上是做一个判断，如果删除的元素是原来链表的第一个元素，那么将表头节点的指针指向原来的第二个节点，而最后一个节点指向原来的链表中的第二个节点
		{
			sList->header.next = ret->next;
			last->next = ret->next;
		}

		if ( sList->slider == ret )
		{
			sList->slider = ret->next;
		}

		if ( sList->length == 0 )			//最后判断一下链表是不是空了
		{
			sList->header.next = NULL;
			sList->slider = NULL;
		}
	}

	return ret;
}


//------------------------------------------------------以下是循环链表所特有的部分--------------------------------------------------
//关键是游标

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)	//可以直接删除循环链表里面的元素，而不需要提前知道他的下标
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if ( sList != NULL )
	{
		CircleListNode* current = (CircleListNode*)sList;

		for(i = 0;i < sList->length; i++)
		{
			if ( current->next == node )			//主要是找到所要删除的元素在循环链表里的逻辑位置
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}

		if ( ret != NULL )	
		{
			CircleList_Delete(sList,i);			//如果真找到了，那么此时的i就是所要删除的元素在循环链表里面的逻辑位置，那么此时调用之前在程序里已经写好的删除操作
		}
	}
	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)		//重置就是把
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if ( sList != NULL )
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}
	return ret;
}

CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if ( sList != NULL )
	{
		ret = sList->slider;
	}

	return ret;
}

CircleListNode* CircleList_Next(CircleList* list)		//移动游标，游标往下一个移动
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if ( (sList != NULL) && (sList->slider != NULL) )
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}
	return ret;
}