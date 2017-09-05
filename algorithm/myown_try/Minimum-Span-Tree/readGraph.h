#ifndef READGRAPH
#define READGRAPH 

#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template<typename Graph,typename Weight>	//巧妙的地方就在于是模版类，无需声明Graph的头文件
class readGraph
{	
public:
	readGraph(Graph& graph,const string& filename)
	{	
		ifstream file(filename);
		string line;
		int V,E;

		assert(file.is_open());

		assert(getline(file,line));
		stringstream ss(line);
		ss>>V>>E;
		assert( graph.V() == V );

		for( int i = 0; i < E; i ++ )
		{
			assert(getline(file,line));
			stringstream ss(line);

			int a,b;
			Weight w;
			ss>>a>>b>>w;
			assert( a >= 0 && a < V );
			assert( b >= 0 && b < V );

			graph.addEdge(a,b,w);
		}
	}
};


#endif