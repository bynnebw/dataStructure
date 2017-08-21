#ifndef READ_GRAPH_H
#define READ_GRAPH_H 

#include <iostream>
#include <string>
#include <fstream>	//I have to check it out the meaning of the header file
#include <sstream>
#include <cassert>

using namespace std;

template<typename Graph,typename Weight>
class ReadGraph
{
public:
	ReadGraph(Graph& graph,const string& filename)
	{
		ifstream file(filename);
		string line;
		int V,E;

		assert( file.is_open() );
		assert( getline(file,line) );
		stringstream ss( line );
		ss>>V>>E; //处理了文件中的第一行

		assert( V == graph.V() );

		for( int i = 0; i < E; i ++ )
		{
			assert( getline(file,line) );	//一行一行的拿数据
			stringstream ss(line);

			int a,b;
			Weight w;
			ss>>a>>b>>w; //将ss中相应的整型放入到a,b中。

			//接下来就要建立起从a到b的一条边
			assert( a >= 0 && a < V );
			assert( b >= 0 && b < V );
			graph.addEdge( a,b,w );
		}
	}
};

#endif