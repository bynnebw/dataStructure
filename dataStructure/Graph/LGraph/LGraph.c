#include <stdio.h>
#include <sys/malloc.h>
#include "LGraph.h"
#include "LinkList.h"

typedef struct _tag_LGraph
{
	int count;
	LVertex** v;
	LinkList** la;
} TLGraph;

typedef struct _tag_ListNode
{
	LinkListNode header;
	int v;
	int w;
} TListNode;

LGraph* LGraph_Create(LVertex** v,int n)
{
	TLGraph* ret = NULL;
	int ok = 1;

	if ( (v != NULL) && (n >0) )
	{
		ret = (TLGraph*)malloc(sizeof(TLGraph));

		if ( ret != NULL )
		{
			ret->count = n;

			ret->v = (LVertex**)calloc(n,sizeof(LVertex*));

			ret->la = (LinkList**)calloc(n,sizeof(LinkList*));

			ok = (ret->v != NULL) && (ret->la != NULL);

			if ( ok )
			{
				int i = 0;

				for ( i = 0; i < n; i ++)
				{
					ret->v[i] = v[i];					//ret->v[i] = i;  这里之前这样写，导致程序不能正常运行，产生段错误。
				}
				for ( i = 0;(i < n) && ok; i++)
				{
					ok = ok && ((ret->la[i] = LinkList_Create()) != NULL);		//有几个顶点，就申请几个链表.
				}
			}

			if ( !ok )
			{
				if ( ret->la != NULL )
				{
					int i = 0;

					for ( i = 0; i < n; i++)
					{
						LinkList_Destroy(ret->la[i]);
					}
				}

				free(ret->la);
				free(ret->v);
				free(ret);

				ret = NULL;
			}
		}
	}
	return ret;
}

void LGraph_Destroy(LGraph* graph)
{
	TLGraph* tGraph = (TLGraph*)graph;

	LGraph_Clear(tGraph);

	if ( tGraph!= NULL )
	{
		int i = 0;

		for ( i =0; i < tGraph->count;i++)
		{
			LinkList_Destroy(tGraph->la[i]);
		}

		free(tGraph->la);
		free(tGraph->v);
		free(tGraph);
	}
}

void LGraph_Clear(LGraph* graph)
{
	TLGraph* tGraph = (TLGraph*)graph;

	if ( tGraph!= NULL )
	{
		int i = 0;

		for ( i = 0;i < tGraph->count;i++)
		{
			while( LinkList_Length(tGraph->la[i]) > 0)
			{
				free(LinkList_Delete(tGraph->la[i],0));
			}
		}
	}	
}

int LGraph_AddEdge(LGraph* graph,int v1,int v2,int w)
{
	TLGraph* tGraph = (TLGraph*)graph;
	TListNode* node = NULL;
	int ret = (tGraph != NULL);

	ret = ret && (0 <= v1) && (v1 < tGraph->count);
	ret = ret && (0 <= v2) && (v2 < tGraph->count);
	ret = ret && (0 < w) && ((node = (TListNode*)malloc(sizeof(TListNode))) != NULL );

	if ( ret )
	{
		node->v = v2;
		node->w = w;

		LinkList_Insert(tGraph->la[v1],(LinkListNode*)node,0);
	}

	return ret;
}

int LGraph_GetEdge(LGraph* graph,int v1,int v2)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int condition = (tGraph!=NULL);
	int ret = 0;

	condition = condition && (0<=v1) && (v1 < tGraph->count);
	condition = condition && (0<=v2) && (v2 < tGraph->count);

	if ( condition )
	{
		TListNode* node = NULL;
		int i = 0;

		for ( i = 0;i < LinkList_Length(tGraph->la[v1]); i ++)
		{
			node = (TListNode*)LinkList_Get(tGraph->la[v1],i);

			if ( node->v == v2)
			{
				ret = node->w;

				break;
			}
		}
	}

	return ret;
}

int LGraph_RemoveEdge(LGraph* graph,int v1,int v2)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int condition = (tGraph != NULL);
	int ret = 0;

	condition = condition && (0 <= v1) && (v1 < tGraph->count);
	condition = condition && (0 <= v2) && (v2 < tGraph->count);

	if ( condition )
	{
		TListNode* node = NULL;
		int i = 0;

		for ( i = 0; i < LinkList_Length(tGraph->la[v1]);i++)
		{
			node = (TListNode*)LinkList_Get(tGraph->la[v1],i);

			if ( node->v == v2 )
			{
				ret = node->w;

				LinkList_Delete(tGraph->la[v1],i);

				free(node);

				break;
			}
		}
	}

	return ret;
}

//I don't think that I fully understand the meaning of calculating the TD of the LGraph.

int LGraph_TD(LGraph* graph,int v)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int condition = (tGraph!= NULL);
	int ret = 0;

	condition = condition && (0<=v) && (v < tGraph->count);

	if ( condition )
	{
		int i = 0;
		int j = 0;

		for ( i = 0; i < tGraph->count;i++)
		{
			for ( j = 0;j < LinkList_Length(tGraph->la[i]);j++)
			{
				TListNode* node = (TListNode*)LinkList_Get(tGraph->la[i],j);

				if ( node->v == v)
				{
					ret ++;
				}
			}
		}
		ret += LinkList_Length(tGraph->la[v]);
	}

	return ret;
}

int LGraph_VertexCount(LGraph* graph)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int ret = 0;

	if ( tGraph != NULL )
	{
		ret = tGraph->count;
	}
	return ret;
}

int LGraph_EdgeCount(LGraph* graph)
{
	TLGraph* tGraph = (TLGraph*)graph;
	int ret = 0;

	if ( tGraph != NULL )
	{
		int i = 0;

		for ( i = 0; i < tGraph->count;i++)
		{
			ret += LinkList_Length(tGraph->la[i]);
		}
	}

	return ret;
}


//显示函数还需要再继续研究一下，并没有完全理解它的打印原理。

void LGraph_Display(LGraph* graph,LGraph_Printf* pFunc)
{
	TLGraph* tGraph = (TLGraph*)graph;

	if ( (tGraph!=NULL) && (pFunc!= NULL) )
	{
		int i = 0;
		int j = 0;

		for (i = 0;i < tGraph->count; i++)
		{
			printf("%d:", i);
			pFunc(tGraph->v[i]);
			printf(" ");
		}
		
		printf("\n");

		for (i = 0;i < tGraph->count;i++)
		{
			for ( j = 0; j <LinkList_Length(tGraph->la[i]); j ++)
			{
				TListNode* node = (TListNode*)LinkList_Get(tGraph->la[i],j);

				printf("<");
				pFunc(tGraph->v[i]);
				printf(", ");
				pFunc(tGraph->v[node->v]);	//What's this line of code supposed to mean?
				printf(", %d", node->w);
				printf(">");
				printf(" ");
			}
		}
		printf("\n");
	}
}