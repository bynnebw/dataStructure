#ifndef EDGE
#define EDGE

#include <iostream>
#include <cassert>

using namespace std;

//将权重部分做成模版
template<typename Weight>
class Edge
{
private:
	int a,b;
	Weight weight;

public:
	Edge(int a ,int b , Weight weight)
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

	//What's this functioin works for ? 
	//已知一条边的一个顶点，想知道该边的另外一个顶点
	int other(int x)
	{
		assert( x == a || x == b );
		return x == a ? b : a;
	}

	friend ostream& operator<<(ostream& os, const Edge& e)
	{
		os<<e.a<<"-"<<e.b<<": "<<e.weight;
		return os;
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