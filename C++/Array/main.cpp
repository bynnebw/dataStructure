#include <stdio.h>
#include <iostream>
#include "Array.h"
#include "Array.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	Array a1(10);

	a1[10];

	for (int i = 0; i < a1.Length(); i++)
	{
		a1.setData(i,i);
	}
	for (int i = 0; i < a1.Length(); i++)
	{
		printf("%d\n", a1.getData(i));	
	}

	Array a2 = a1;

	for (int i = 0; i < a2.Length(); i++)
	{
		a2.setData(i,i);
	}
	for (int i = 0; i < a2.Length(); i++)
	{
		printf("%d\n", a2.getData(i));	
	}
 	
	cout<<"---------------------------------"<<endl;

	Array a3 = a1;

	for (int i = 0; i < a3.Length(); ++i)
	{
		a3[i] = i;
	}

	for(int i = 0;i < a1.Length();i ++)
	{
		printf("a[%d] = %d\n", i,a1[i]+1);		//对操作符进行重载之后可以实现直接像数组一样使用a[];
	}

	cin.get();
	return 0;
}