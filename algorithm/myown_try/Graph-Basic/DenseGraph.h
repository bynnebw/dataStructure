#ifndef DESNSEGRAPH_H_
#define DESNSEGRAPH_H_

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph
{
private:
	int n,m;
	bool directed;
	vector<vector<bool>> g; //二维矩阵

public:
	DenseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;

		//初始化邻接矩阵，所有的值都可以设置为false
		for( int i = 0; i < n; i ++ )
			g.push_back( vector<bool>(n,false) );
	}
	~DenseGraph()
	{
		//没有声明空间，所以不需要delete操作。
	}
	int V() { return n; }
	int E() { return m; }

	void addEdge( int v, int w)
	{
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );

		if( hasEdge(v,w) )
			return;

		g[v][w] = true;

		if( !directed )
			g[w][v] = true;

		m ++;
	}


	//因为使用邻接矩阵，所以在判断两个点之间是否有边的时间复杂度仅仅为O(1).
	bool hasEdge( int v, int w )
	{
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );

		return g[v][w];
	}
	void show()
	{
		for( int i = 0; i < n; i ++ )
		{
			for( int j = 0; j < n; j ++ )
				cout<<g[i][j]<<"\t";
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
		adjIterator(DenseGraph& graph,int v):G(graph)
		{
			this->v = v;
			this->index = -1;
		}
		int begin()
		{
			index = -1;
			return next();
		}
		int next()
		{
			//因为使用的是邻接矩阵来表征，所以在遍历时是两重遍历
			for( index += 1; index < G.V(); index ++ )
				if( G.g[v][index] )
					return index;

			return -1;
		}
		bool end()
		{
			 return index >= G.V();
		}
		
	};
	
};

#endif