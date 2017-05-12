#include <stdio.h>
#include <sys/malloc.h>
#include "MGraph.c"

typedef struct _tag_Mgraph
{
	int count;
	MVertex** v;			//顶点数据
	int** matrix;

} TMGraph;


MGraph* MGraph_Create(MVertex** v,int n)
{
	TMGraph* ret = NULL;

	
}

void MGraph_Destroy(MGraph* graph)
{

}

void MGraph_Clear(MGraph* graph)
{

}

int MGraph_AddEdge(MGraph* graph,int v1,int v2,int w)
{

}

int MGraph_RemoveEdge(MGraph* graph,int v1,int v2)
{

}

int MGraph_GetEdge(MGraph* graph,int v1,int v2)
{

}

int MGraph_TD(MGraph* graph,int v)	//计算顶点的度（入度+出度）
{

}

int MGraph_VertexCount(MGraph* graph)
{

}

int MGraph_EdgeCount(MGraph* graph)
{

}

void MGraph_Display(MGraph* graph,MGraph_Printf* pFunc)
{

}
