#include <cstdlib>
#include <iostream>

using namespace std;

class complex
{
	int a;
	int b;
public:
	complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}

	int getA()
	{
		return a;
	}
	
	int getB()
	{
		return b;
	}

	friend complex operator+ (const complex& c1,const complex& c2);
	friend ostream& operator<< (ostream& out,const complex& c);
};

ostream& operator<< (ostream& out,const complex& c)		//注意这里的使用方法
{
	out<<c.a<<" + "<<c.b<<"i"<<endl;
	return out;
}

complex operator+ (const complex& c1,const complex& c2)
{
	complex ret;

	ret.a = c1.a + c2.a;
	ret.b = c1.b + c2.b;
	
	return ret;
}

int main(int argc, char const *argv[])
{
	complex c1(1, 2);
	complex c2(3, 4);
	complex c3 = c1 + c2;
	
	cout<<c1<<endl;
	cout<<c2<<endl;
	cout<<c3<<endl;

	cin.get();
	return 0;
}