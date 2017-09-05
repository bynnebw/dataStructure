#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"

using namespace std;

template<typename Weight>
class SparseGraph
{
private:
	int n,m;
	bool directed;
	vector<vector<Edge<Weight>* >> g;
public:
	SparseGraph(int n,bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		//还是要对邻接表进行初始化申请内存空间的

		for( int i = 0; i < n; i ++ )
			g.push_back( vector<Edge<Weight>* >() );
	}
	~SparseGraph()
	{
		for( int i = 0; i < n; i ++ )
			for( int j = 0; j < g[i].size(); j ++ )	//这里注意，不是矩阵，所以不要直接赋值为n
				delete g[i][j];
	}
	int V() { return n; }
	int E() { return m; }

	void addEdge(int v, int w,Weight weight)
	{	
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );

		g[v].push_back( new Edge<Weight>(v,w,weight));
		if( v != w && !directed )
			g[w].push_back( new Edge<Weight>(w,v,weight));
		m ++;
	}
	bool hasEdge(int v, int w)
	{
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );

		for( int i = 0; i < g[v].size(); i ++ )
		{
			if( g[v][i]->other(v) == w )
				return true;
		}
		return false;
	}

	void show()
	{
		for( int i = 0; i < n; i ++ )
		{
			cout<<"Vertex "<<i<<":\t";
			for( int j = 0; j < g[i].size(); j ++ )
				cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
			cout<<endl;
		}
	}

	//在类的内部制作迭代器，方便在外面进行迭代打印
	class adjIterator
	{
	private:
		SparseGraph& G;
		int v;
		int index;
	public:
		adjIterator(SparseGraph& graph,int v):G(graph)	//对与v节点相连的其他节点进行遍历
		{
			this->v = v;
			this->index = 0;
		}
		Edge<Weight>* begin()
		{
			index = 0;
			if( G.g[v].size() )
				return G.g[v][index];
			return NULL;
		}

		Edge<Weight>* next()
		{
			index += 1;
			if( G.g[v].size())
				return G.g[v][index];
			return NULL;
		}
		
		bool end()
		{
			return index >= G.g[v].size();
		}
	};
	
};

#endif