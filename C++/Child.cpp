//在继承关系中，注意存在赋值兼容性原则
//从例子中可以看出，可以直接将子类直接赋给父类，所以说：子类是特殊的父类。

#include <iostream>
using namespace std;

class Parent
{
protected:
	const char* name;
public:
	Parent()
	{
		name = "Parent";
	}

	void print()
	{
		cout<<"Name: "<<name<<endl;
	}
};

class Child : public Parent
{
protected:
	int i;
public:
	Child(int i)
	{
		this->name = name;
		this->i = i;
	}
};

int main(int argc, char const *argv[])
{
	Child child(1000);
	Parent parent = child;
	Parent* pp = &child;
	Parent& rp = child;

	parent.print();
	pp->print();
	rp.print();
	
	return 0;
}