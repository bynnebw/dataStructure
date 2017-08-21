#ifndef PATH_H
#define PATH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

template<typename Graph>
class Path
{
private:
	Graph& G;
	int s;
	bool* visited;
	int* from;

	void dfs(int v)
	{
		visited[v] = true;
		typename Graph::adjIterator adj(G,v); //这里有一个小trick，就是adjIterator不知道是graph的一个成员变量还是一个类型，所以要加上一个关键字

		//使用迭代的方法，遍历邻边。使用模版，使得可以对任意的图都适用	
		for( int i = adj.begin(); !adj.end(); i = adj.next() )
		{
			if( !visited[i] )	//这里一开始少了个[]。
			{
				from[i] = v;	//在添加此行代码的时候一定要注意大括号的匹配问题
				dfs(i);
			}
		}
	}
public:
	Path(Graph& graph,int s):G(graph)
	{
		//initialize of the algorithm
		assert( s >= 0 && s < G.V() );

		visited = new bool[G.V()];
		from = new int[G.V()];

		for( int i = 0; i < G.V(); i ++ )
		{
			visited[i] = false;
			from[i] = -1;
		}

		this->s = s;

		//寻路算法

		dfs(s);
	}
	~Path()
	{
		delete[] visited;
		delete[] from;
	}

	bool hasPath(int w)			//从s到w是否存在路径
	{	
		assert( w >= 0 && w < G.V() );
		return visited[w];
	}

	void path(int w,vector<int>& vec)	//将从s到w的路径找到
	{
		stack<int> s;

		int p = w;
		while( p != -1 )
		{
			s.push(p);
			p = from[p];	//因为每次from[p]中存放的都是p节点前面的节点
		}

		vec.clear();
		while( !s.empty() )
		{
			vec.push_back( s.top() );
			s.pop();
		}
	}
	void showPath(int w)	//将从s到w的路径打印出来
	{
		vector<int> vec;
		path(w,vec);
		for( int i = 0; i < vec.size(); i ++ )
		{
			cout<<vec[i];
			if( i == vec.size() - 1 )
				cout<<endl;
			else
				cout<<" - > ";
		}
	}
};

#endif