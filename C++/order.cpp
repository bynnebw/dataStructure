//本程序主要解释了，在调用构造函数与析构函数时的调用顺序。

#include <stdio.h>

class Test
{
private:
	int mI;
public:
	Test()
	{
		printf("Test()\n");
		mI = -1;
	}

	Test(int i)
	{
		printf("Test(int i),i = %d\n",i);
		mI = i;
	}

	Test(const Test& obj)
	{
		mI = obj.mI;
		printf("Test(const Test& obj), i = %d\n",mI);
	}

	~Test()
	{
		printf("~Test(),i = %d\n", mI);
	}
	
};

void func(Test t)		//这里的拷贝构造函数虽然执行了，但是我不知道执行该构造函数的意义何在。而且在虽然func函数的参数是Test t
{						//问题是好像这个参数并没有使用啊。
	Test r(22);			//执行新的
}

void run()
{
	Test t(11);			//首先执行，
	func(t);			//调用func函数，实参传到形参，调用“拷贝构造函数”，跳转到func函数参数部分去
}

int main(int argc, char const *argv[])
{
	run();
	
	return 0;
}