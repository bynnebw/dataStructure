//“边”的模版类，

#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

template<typename Weight>
class Edge
{
private:
	int a,b;
	Weight weight;
public:
	Edge(int a,int b,Weight weight)
	{
		this->a = a;
		this->b = b;
		this->weight = weight;
	}	
	Edge(){}
	~Edge(){}
	
	int v() { return a; }
	int w() { return b; }

	Weight wt() { return weight; }

	int other(int x)
	{
		assert( x == a || x == b );
		return x == a ? b : a;
	}

	friend ostream& operator<<(ostream& out, const Edge& e)	//given一条边，把边的两个端点以及边的权重打印出来。
	{
		out<<e.a<<" - "<<e.b<<": "<<e.weight;
		return out;
	}

	bool operator<(Edge<Weight>& e)
	{
		return weight < e.wt();
	}

	bool operator<=(Edge<Weight>& e)
	{
		return weight <= e.wt();
	}

	bool operator>(Edge<Weight>& e)
	{
		return weight > e.wt();
	}

	bool operator>=(Edge<Weight>& e)
	{
		return weight >= e.wt();
	}
	bool operator==(Edge<Weight>& e)
	{
		return weight == e.wt();
	}
};



#endif