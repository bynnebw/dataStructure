//测试一下寻找图中不同节点之间的路径，并将其打印出来
#include <iostream>
#include <cassert>
#include "Path.h"
#include "ReadGraph.h"
#include "SparseGraph.h"
#include "DenseGraph.h"


using namespace std;

int main(int argc, char const *argv[])
{
	string filename = "/Users/zhangrongrong/Desktop/testG1.txt";
	SparseGraph g = SparseGraph(13,false);
	ReadGraph<SparseGraph> readGraph(g,filename);
	g.show();
	cout<<endl;

	Path<SparseGraph> dfs(g,9);
	cout<<"DFS : ";
	dfs.showPath(12);

	return 0;
}