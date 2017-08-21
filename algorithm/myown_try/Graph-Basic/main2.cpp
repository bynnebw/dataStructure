#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"

using namespace std;

int main(int argc, char const *argv[])
{
	string filename1 = "/Users/zhangrongrong/Desktop/testG1.txt";
	string filename2 = "/Users/zhangrongrong/Desktop/testG2.txt";
	
	SparseGraph g1 = SparseGraph( 13 , false );
	ReadGraph<SparseGraph> readGrapgh1( g1,filename1 );	//将txt文件中的内容读进去g1中
	Component<SparseGraph> component1(g1);
	cout<<"TextG1.txt , component count: "<<component1.count()<<endl;

	cout<<endl;

	SparseGraph g2 = SparseGraph( 7,false );
	ReadGraph<SparseGraph> readGrapgh2( g2,filename2 );
	Component<SparseGraph> component2(g2);
	cout<<"TextG1.txt , component count: "<<component2.count()<<endl;
	cout<<endl;

	return 0;
}