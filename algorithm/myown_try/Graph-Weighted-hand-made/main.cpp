#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "readGraph.h"

using namespace std;

int main(int argc, char const *argv[])
{
	string filename = "/Users/zhangrongrong/Desktop/testG1.txt";
	int V = 8;
	cout<<fixed<<setprecision(2);

	DenseGraph<double> g1 = DenseGraph<double>(V,false);	//初始化图
	readGraph<DenseGraph<double>,double> readGraph1(g1,filename);	//从文件中读取，生成图
	g1.show();
	cout<<endl;

	SparseGraph<double> g2 = SparseGraph<double>(V,false);
	readGraph<SparseGraph<double>,double> readGraph2(g2,filename);
	g2.show();
	


	return 0;
}