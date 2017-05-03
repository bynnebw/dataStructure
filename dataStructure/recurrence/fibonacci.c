#include <stdio.h>

/*
**	求解递归问题，最为关键的两个元素是要找到递推关系与边界条件
**	找到这两个元素条件之后，进行递归运算的时候就不用考虑具体的
**	实现细节了。实际上是分而治之的思想，将大问题分解为小问题解决。
*/

int fibonacci(int n)
{
	if ( n > 1 )
	{
		return fibonacci(n-1) + fibonacci(n-2);
	}
	else if ( n == 1 )
	{
		return 1;
	}
	else if ( n == 0 )
	{
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	int i = 0;

	for(i = 1;i <= 10;i++)
	{
		printf("fibonacci(%d) = %d\n",i,fibonacci(i));
	}

	return 0;
}