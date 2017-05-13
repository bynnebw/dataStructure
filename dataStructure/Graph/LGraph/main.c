#include <stdio.h>
#include "LGraph.h"
#include "LinkList.h"

void print_data(LVertex* v)
{
	printf("%s", (char*)v);
}

int main(int argc, char const *argv[])
{
	LVertex* v[] = {"A","B","C","D","E","F"};
	LGraph* graph = LGraph_Create(v,6);

	LGraph_AddEdge(graph,0,1,1);
	LGraph_AddEdge(graph,0,2,1);
	LGraph_AddEdge(graph,0,3,1);
	LGraph_AddEdge(graph,1,5,1);
	LGraph_AddEdge(graph,1,4,1);
	LGraph_AddEdge(graph,2,1,1);
	LGraph_AddEdge(graph,3,4,1);
	LGraph_AddEdge(graph,4,2,1);

	printf("\n");

	printf("The VertexCount of the Graph is : %d\n", LGraph_VertexCount(graph));

	printf("\n");

	printf("The EdgeCount of the Graph is : %d\n", LGraph_EdgeCount(graph));

	printf("\n");

	printf("The LaGraph TD of the Graph is : %d\n", LGraph_TD(graph,3));

	printf("\n");

	printf("The Edge of between the A and D is : %d\n", LGraph_GetEdge(graph,0,3));

	printf("\n");

	LGraph_Display(graph,print_data);

	LGraph_Destroy(graph);

	return 0;
}
