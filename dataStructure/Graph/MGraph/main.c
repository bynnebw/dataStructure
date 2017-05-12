#include <stdio.h>
#include <sys/malloc.h>
#include "MGraph.h"

void printf_data(MVertex* v)		//所以这里的v存储的是节点的信息，比如顶点里存储的字符信息。
{
	printf("%s", (char*)v);
}

int main(int argc, char const *argv[])
{
	MVertex* v[] = {"A","B","C","D","E","F"};
	MGraph* graph = MGraph_Create(v,6);

	MGraph_AddEdge(graph,0,1,1);
	MGraph_AddEdge(graph,0,2,1);
	MGraph_AddEdge(graph,0,3,1);
	MGraph_AddEdge(graph,1,5,1);
	MGraph_AddEdge(graph,1,4,1);
	MGraph_AddEdge(graph,2,1,1);
	MGraph_AddEdge(graph,3,4,1);
	MGraph_AddEdge(graph,4,2,1);

	MGraph_Display(graph,printf_data);

	MGraph_Destroy(graph);

	return 0;
}