#include <stdio.h>
#include <sys/malloc.h>
#include "MGraph.h"

/*
**	使用邻接矩阵，动态存储图中的边信息
**	单独使用顶点信息进行存储顶点的相关信息。 
*/

typedef struct _tag_Mgraph
{
	int count;
	MVertex** v;			//顶点数据
	int** matrix;

} TMGraph;

/*
**	使用二维数组，动态实现邻接矩阵。
*/

MGraph* MGraph_Create(MVertex** v,int n)
{
	TMGraph* ret = NULL;

	if ( ( v != NULL ) && ( n > 0 ) )
	{
		ret = (TMGraph*)malloc(sizeof(TMGraph));

		if ( ret != NULL )
		{
			int* p = NULL;
			
			ret->count = n;
			
			ret->v = (MVertex**)malloc(sizeof(MVertex*) * n);
			
			ret->matrix = (int**)malloc(sizeof(int*) * n);
			
			p = (int*)calloc(n*n,sizeof(int));		//calloc相比于malloc强的地方在于他在申请的时候已经自动初始化了。这样会省掉很多麻烦

			if ( (ret->v != NULL) && (ret->matrix != NULL) && (p != NULL) )
			{
				int i = 0;

				for ( i = 0;i < n;i ++)
				{
					ret->v[i] = v[i];
					ret->matrix[i] = p + i * n;
				}
			}
			else
			{
				free(p);
				free(ret->matrix);
				free(ret->v);
				free(ret);

				ret = NULL;
			}
		}
	}
	return ret;
}

void MGraph_Destroy(MGraph* graph)
{
	TMGraph* tGraph = (TMGraph*)graph;

	if ( tGraph!= NULL )
	{
		free(tGraph->v);
		free(tGraph->matrix[0]);
		free(tGraph->matrix);
		free(tGraph);
	}
}

void MGraph_Clear(MGraph* graph)
{
	TMGraph* tGraph = (TMGraph*)graph;

	if ( tGraph!= NULL )
	{
		int i = 0;
		int j = 0;

		for ( i = 0; i < tGraph->count;i++)
		{
			for ( j = 0; j < tGraph->count; j ++)
			{
				tGraph->matrix[i][j] = 0;
			}
		}
	}
}

int MGraph_AddEdge(MGraph* graph,int v1,int v2,int w)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int ret = (tGraph!=NULL);

	ret = ret && (0 <= v1) && (0 <= v2) && (v1 < tGraph->count) && (v2 < tGraph->count) && (0 <= w);

	if (ret)
	{
		tGraph->matrix[v1][v2] = w;
	}
	return ret;
}

int MGraph_RemoveEdge(MGraph* graph,int v1,int v2)
{
	int ret = MGraph_GetEdge(graph,v1,v2);

	if (ret != 0 )
	{
		((TMGraph*)graph)->matrix[v1][v2] = 0;
	}
	return ret;
}

int MGraph_GetEdge(MGraph* graph,int v1,int v2)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int condition = (tGraph!= NULL);
	int ret = 0;

	condition = condition && (0 <= v1) && (v1 < tGraph->count);
	condition = condition && (0 <= v2) && (v2 < tGraph->count);

	if ( condition )
	{
		ret = tGraph->matrix[v1][v2];
	}

	return ret;
}

int MGraph_TD(MGraph* graph,int v)	//计算顶点的度（入度+出度）  ， 这里的参数v该怎么理解？
{
	TMGraph* tGraph = (TMGraph*)graph;
	int condition = (tGraph != NULL);
	int ret = 0;

	condition = condition && (0 <= v) && (v < tGraph->count);

	if ( condition )
	{	
		int i = 0;

		for ( i = 0; i < tGraph->count;i++ )		//两个if满足条件的，一个是“入度”，一个是“出度”
		{
			if (tGraph->matrix[v][i] != 0)
			{
				ret ++;
			}
			if ( tGraph->matrix[i][v] != 0)
			{
				ret ++;
			}
		}
	}
	return ret;
}

int MGraph_VertexCount(MGraph* graph)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int ret = 0;

	if ( tGraph!=NULL )
	{
		ret = tGraph->count;
	}

	return ret;
}

int MGraph_EdgeCount(MGraph* graph)
{
	TMGraph* tGraph = (TMGraph*)graph;
	int ret = 0;

	if ( tGraph!=NULL )
	{
		int i = 0;
		int j = 0;

		for ( i =0; i < tGraph->count; i++)
		{
			for ( j = 0;j < tGraph->count;j ++)
			{
				if ( tGraph->matrix[i][j] != 0 )
				{
					ret ++;
				}
			}
		}
	}

	return ret;	
}

void MGraph_Display(MGraph* graph,MGraph_Printf* pFunc)
{
	TMGraph* tGraph = (TMGraph*)graph;

	if ( (tGraph!=NULL) && (pFunc!= NULL) )
	{
		int i = 0;
		int j = 0;

		for ( i = 0;i < tGraph->count;i++)
		{
			for ( j = 0; j < tGraph->count;j++)
			{
				if ( tGraph->matrix[i][j] != 0 )
				{
					printf("< ");
					pFunc(tGraph->v[i]);
					printf(", ");
					pFunc(tGraph->v[j]);
					printf(", %d", tGraph->matrix[i][j]);
					printf("> ");
					printf(" ");
				}
			}
		}

		printf("\n");
	}
}
