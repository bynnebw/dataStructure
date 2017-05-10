#include <stdio.h>
#include <sys/malloc.h>
#include "GTree.h"
#include "LinkList.h"

/*
** 通用树工程
*/

/*
**	利用结构体的声明来实现树节点
**	每个树节点中包含着两个指针（指向父亲的指针，树节点存放数据元素的指针），和一个用于揭示该树节点的子节点的链表。	
*/
typedef struct _tag_GTreeNode GTreeNode;
struct _tag_GTreeNode		
{
	GTreeData* data;	//树节点里面存放的数据。
	GTreeNode* parent;	//每个树节点有一个指向他的父亲节点的指针。
	LinkList* child;	//指向孩子的指针链表，因为不知道究竟有多少个子节点，所以每个树节点就放了一个链表，里面存放的是他的子节点的指针。
};

/*
**	组织链表中存放的一个指针，该指针指向的是树节点
**	根据树的结构图可以看出，树中的每个元素都是组织链表中的元素。
*/

typedef struct _tag_TLNode TLNode;		//链表的节点结构体        //这里应该代表的是组织链表。
struct _tag_TLNode
{
	LinkListNode header;
	GTreeNode* node;
};

//每个树节点都可以用组织链表来访问。因为数据封装，所以用户看不到，其实返回的是链表。
GTree* GTree_Create()
{
	return LinkList_Create();
}

void GTree_Destroy(GTree* tree)
{
	GTree_Clear(tree);
	LinkList_Destroy(tree);
}

void GTree_Clear(GTree* tree)
{

}


/*
**	要维护每个节点和双亲之间的连接，对于每个新加进来的节点，都必须将它的parent指针，指向它的双亲节点。
*/

int GTree_Insert(GTree* tree,GTreeData* data,int pPos)	//因为树的实现是基于一张表的，所以在插入的时候，pPos指的应该是他父亲在这张表里的位置
{	
	LinkList* list = (LinkList*)tree;
	int ret = (list != NULL) && (data != NULL) && (pPos < LinkList_Length(list));

	if ( ret )
	{
		//在组织链表进行操作，申请节点空间。

		TLNode* trNode = (TLNode*)malloc(sizeof(TLNode));	
		TLNode* cldNode = (TLNode*)malloc(sizeof(TLNode));
		
		TLNode* pNode = (TLNode*)LinkList_Get(list,pPos);

		GTreeNode* cNode = (GTreeNode*)malloc(sizeof(GTreeNode));	//在堆空间中malloc出一个节点出来,这个应该就是需要插入的节点

		ret = (trNode != NULL ) && (cldNode != NULL ) && (cNode != NULL);

		if ( ret )
		{
			cNode->data = data;
			cNode->parent = NULL;	//这里的parent应该是取出来的，所以需要写代码把parent写出来。
			cNode->child = LinkList_Create();

			trNode->node = cNode;
			cldNode->node = cNode;

			LinkList_Insert(list,(LinkListNode*)trNode,LinkList_Length(list));

			if( pNode != NULL )
			{
				cNode->parent = pNode->node;

				LinkList_Insert(pNode->node->child,(LinkListNode*)cldNode,LinkList_Length(pNode->node->child));
			}
		}
		else
		{
			free(trNode);
			free(cldNode);
			free(cNode);
		}
	}
	return ret;
}

GTreeData* GTree_Delete(GTree* tree,int pos)
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree,pos);
	GTreeData* ret = NULL;

	if ( trNode != NULL )
	{

	}
	return ret;
}

GTreeData* GTree_Get(GTree* tree,int pos)
{

}

GTreeData* GTree_Root(GTree* tree)
{

}

int GTree_Height(GTree* tree)
{

}

int GTree_Count(GTree* tree)
{

}

int GTree_Degree(GTree* tree)
{

}

void GTree_Display(GTree* tree,GTree_Printf* pFunc,int gap,char div)
{

}