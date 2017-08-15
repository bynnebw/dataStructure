#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int N = 20;
	int M = 100;

	srand(time(NULL));

	//sparse graph

	SparseGraph g1(N ,false);
	for( int i = 0; i < M; i ++ )
	{
		int a = rand()%N;
		int b = rand()%N;
		g1.addEdge( a, b );
	}

	//O(E)
	for( int v = 0; v < N; v ++ )
	{
		cout<<v<<" : ";
		SparseGraph::adjIterator adj( g1, v );
		for( int w = adj.begin(); !adj.end(); w = adj.next() )
			cout<<w<<" ";
		cout<<endl;
	}
	cout<<endl;

	//dense graph

	DenseGraph g2(N ,false);
	for( int i = 0; i < M; i ++ )
	{
		int a = rand()%N;
		int b = rand()%N;
		g2.addEdge( a, b );
	}

	//O(V^2)
	for( int v = 0; v < N; v ++ )
	{
		cout<<v<<" : ";
		DenseGraph::adjIterator adj( g2, v );
		for( int w = adj.begin(); !adj.end(); w = adj.next() )
			cout<<w<<" ";
		cout<<endl;
	}

	return 0;
}