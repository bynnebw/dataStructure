#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main(int argc, char const *argv[])
{
	string filename = "/Users/zhangrongrong/Desktop/testG1.txt";
	
	SparseGraph g1( 13 , false );
	ReadGraph<SparseGraph> readGrapgh1( g1,filename );	//将txt文件中的内容读进去g1中
	//为验证读取效果，可以在sparsegraph中写一个打印函数。
	g1.show();
	cout<<endl;

	cout<<"next is the format of using the adjacent matrix method"<<endl;

	cout<<endl;

	DenseGraph g2( 13, false );
	ReadGraph<DenseGraph> readGrapgh2( g2,filename );
	g2.show();

	return 0;
}