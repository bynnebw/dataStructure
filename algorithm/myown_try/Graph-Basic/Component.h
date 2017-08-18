#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;
template<typename Graph>
class Component
{
private:
	Graph& G;
	bool* visited;
	int ccount;		//记录有多少个联通分量


	//很像在树结构中，对树的遍历中所使用的递归的方法，只不过在图中会使用visited变量来记录是否之前已经访问到了该变量
	void dfs(int v)
	{
		visited[v] = true;
		typename Graph::adjIterator adj(G,v); //这里有一个小trick，就是adjIterator不知道是graph的一个成员变量还是一个类型，所以要加上一个关键字

		//使用迭代的方法，遍历邻边。使用模版，使得可以对任意的图都适用	
		for( int i = adj.begin(); !adj.end(); i = adj.next() )
		{
			if( !visited[i] )	//这里一开始少了个[]。
				dfs(i);
		}
	}
public:
	Component(Graph& graph): G(graph)
	{
		visited = new bool[G.V()];
		ccount = 0;

		for( int i = 0; i < G.V(); i ++ )
			visited[i] = false;

		for( int i = 0; i < G.V(); i ++ )
		{
			if( !visited[i] )
			{
				dfs(i);
				ccount ++;
			}
		}
	}
	~Component()
	{
		delete[] visited;
	}

	int count()
	{
		return	ccount;
	}

	
};

#endif