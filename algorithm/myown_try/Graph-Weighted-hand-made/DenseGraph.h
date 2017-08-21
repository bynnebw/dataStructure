#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

template<typename Weight>
class DenseGraph
{
private:
	int n,m;
	bool directed;
	vector<vector<Edge<Weight>* >> g;	//首先g是一个矩阵，其次矩阵里面存在的是指针，该指针是一个Edge类型的，Edge类型是一个typename为Weight的模版类。
public:
	DenseGraph(int n,bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;

		//对于图制作一个类来说，这里需要对其进行空间的申请嘛？
		for( int i = 0; i < n; i ++ )
			for( int j = 0; j < n; j ++ )
				g.push_back( vector<Edge<Weight>* >(n,NULL) );
	}
	~DenseGraph()
	{
		for( int i = 0; i < n; i ++ )
			for( int j = 0; j < n; j ++ )
				if( g[i][j] != NULL )
					delete g[i][j];

	}
	int V() { return n; }
	int E() { return m; }

	void addEdge(int v, int w,Weight weight)
	{	
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );

		if( hasEdge(v,w) )
		{
			delete g[v][w];
			if( !directed )
				delete g[w][v];
			m --;
		}

		g[v][w] = new Edge<Weight>(v,w,weight);
		if( !directed )
			g[w][v] = new Edge<Weight>(w,v,weight);
		m ++;
	}
	bool hasEdge(int v, int w)
	{
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );

		return g[v][w] != NULL;
	}

	void show()
	{
		for( int i = 0; i < n; i ++ )
		{
			for( int j = 0; j < n; j ++ )
			{
				if( g[i][j] )
					cout<<g[i][j]->wt()<<"\t";
				else
					cout<<"NULL\t";
			}
			cout<<endl;
		}
	}

	class adjIterator
	{	
	private:
		DenseGraph& G;
		int v;
		int index;
	public:
		adjIterator(DenseGraph& graph,int v) : G(graph)
		{
			this->v = v;
			this->index = -1;
		}
		Edge<Weight>* begin()
		{
			index = -1;
			return next();
		}
		Edge<Weight>* next()
		{
			for( index += 1; index < G.V(); index ++ )
				if( G.g[v][index] )
					return G.g[v][index];

			return NULL;
		}
		bool end()
		{
			return index >= G.V();
		}
	};

};



#endif