#include <stdio.h>
#include <sys/malloc.h>
#include "GTree.h"
#include "LinkList.h"

/*
** 通用树工程
** 使用方法:双亲节点实现方法->较为复杂
*
*
*
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

static void recursive_display(GTreeNode* node,GTree_Printf* pFunc,int format,int gap,char div)
{
	int i = 0;

	if ( (node!=NULL) && (pFunc!=NULL) )
	{
		for (i = 0;i < format;i++)		//首先打印根节点，打印完根节点之后，在利用递归打印子节点。
		{
			printf("%c", div);
		}
		pFunc(node->data);	//打印根节点
		printf("\n");

		for ( i = 0;i < LinkList_Length(node->child);i++)	//递归打印子节点
		{
			TLNode* trNode = (TLNode*)LinkList_Get(node->child,i);
			recursive_display(trNode->node,pFunc,format+gap,gap,div);
		}
	}
}

static void recursive_delete(LinkList* list,GTreeNode* node)
{
	if ( (list!=NULL) && (node!=NULL) )
	{
		GTreeNode* parent = node->parent;
		int i = 0;
		int index = -1;

		//因为一个节点是放在两个链表里的，一个是组织链表，一个是逻辑的双亲链表。所以在进行删除操作的时候，需要将两个链表中的节点均删除。

		for(i=0;i<LinkList_Length(list);i++)	//首先找到要删除的节点。然后在组织链表里将它删除。
		{
			TLNode* trNode = (TLNode*)LinkList_Get(list,i);
			if(trNode->node == node)
			{
				LinkList_Delete(list,i);
				free(trNode);
				index = i;
				break;
			}
		}

		//在child芥蒂娜中将元素删除.  实际上过程和在组织链表里的删除操作是一样的。

		if( index >= 0)
		{
			if ( parent != NULL )		//
			{
				for ( i = 0; i < LinkList_Length(parent->child); i++)
				{
					TLNode* trNode = (TLNode*)LinkList_Get(parent->child,i);

					if ( trNode->node == node )
					{
						LinkList_Delete(parent->child,i);
						free(trNode);
						break;
					}
				}
			}

			//再有就是把这个节点的孩子链表中将元素全部删除。
			while( LinkList_Length(node->child) > 0 )
			{
				TLNode* trNode = (TLNode*)LinkList_Get(node->child,0);

				recursive_delete(list,trNode->node);
			}
			LinkList_Destroy(node->child);	//将child的元素全部destroy掉
			free(node);
		}
	}
}

//递归返回子树的最大高度。
static int recursive_height(GTreeNode* node)
{
	int ret = 0;
	if ( node != NULL )
	{
		int subHeight = 0;
		int i = 0;

		for ( i = 0; i < LinkList_Length(node->child); i++)
		{
			TLNode* trNode = (TLNode*)LinkList_Get(node->child,i);

			subHeight = recursive_height(trNode->node);

			if ( ret < subHeight)		//边递归，边寻找最大值。所谓树的高度便是子树的最高高度。 
			{
				ret = subHeight;
			}
		}
		ret = ret + 1;
	}

	return ret;
}

static int recursive_degree(GTreeNode* node)
{
	int ret = -1;
	if ( node != NULL )
	{
		int subDegree = 0;
		int i = 0;

		ret = LinkList_Length(node->child);

		for(i = 0;i < LinkList_Length(node->child);i++)
		{
			TLNode* trNode = (TLNode*)LinkList_Get(node->child,0);
			subDegree = recursive_degree(trNode->node);

			if ( ret < subDegree )
			{
				ret = subDegree;
			}
		}
	}
	return ret;
}


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
	GTree_Delete(tree,0);
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

/*
**	因为树的定义是递归定义的，所以删除操作也需要采用
**	递归的方式删除才可以。因为一个节点往往还有子节点，逻辑上会有点复杂。
*/

GTreeData* GTree_Delete(GTree* tree,int pos)
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree,pos);
	GTreeData* ret = NULL;

	if ( trNode != NULL )
	{
		ret = trNode->node->data;
		recursive_delete(tree,trNode->node);
	}
	return ret;
}

GTreeData* GTree_Get(GTree* tree,int pos)
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree,pos);
	GTreeData* ret = NULL;

	if ( trNode!=NULL )
	{
		ret = trNode->node->data;
	}
	return ret;
}

GTreeData* GTree_Root(GTree* tree)
{
	return GTree_Get(tree,0);
}

int GTree_Height(GTree* tree)		//涉及递归
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree,0);
	int ret = 0;

	if ( trNode != NULL )
	{
		ret = recursive_height(trNode->node);
	}
	return ret;
}

int GTree_Count(GTree* tree)
{
	return LinkList_Length(tree);
}

int GTree_Degree(GTree* tree)	//涉及递归
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree,0);
	int ret = -1;

	if ( trNode != NULL )
	{
		ret = recursive_degree(trNode->node);
	}
	return ret;
}

void GTree_Display(GTree* tree,GTree_Printf* pFunc,int gap,char div)	//因为树的定义方式是递归定义的，所以打印的时候也是递归打印
{
	TLNode* trNode = (TLNode*)LinkList_Get(tree,0);
	if ( (trNode!=NULL) && (pFunc != NULL) )
	{
		recursive_display(trNode->node,pFunc,0,gap,div);
	}
}