#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"


using namespace std;

int main(int argc, char const *argv[])
{
	int N = 20;
	int M = 100;

	srand(time(NULL));

	//generate a sparsegraph using the class of sparsegraph
	SparseGraph g1(N,false);
	for( int i = 0; i < M; i ++ )
	{
		int a = rand()%N;
		int b = rand()%N;

		g1.addEdge( a,b ); 
	}

	for( int v = 0; v < N; v ++ )
	{
		cout<<v<<" : ";
		SparseGraph::adjIterator adj( g1,v );
		for( int w = adj.begin(); !adj.end(); w = adj.next() )
			cout<<w<<" ";

		cout<<endl;
	}

	cout<<endl;
	cout<<"Down the line is the densegraph way"<<endl;

	DenseGraph g2(N,false);
	for( int i = 0; i < M; i ++ )
	{
		int a = rand()%N;
		int b = rand()%N;

		g2.addEdge( a,b ); 
	}

	//对稠密图的每条边进行遍历的时候是，O(n^2)的时间复杂度
	for( int v = 0; v < N; v ++ )
	{
		cout<<v<<" : ";
		DenseGraph::adjIterator adj( g2,v );
		for( int w = adj.begin(); !adj.end(); w = adj.next() )
			cout<<w<<" ";

		cout<<endl;
	}

	return 0;
}