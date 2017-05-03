#include <stdio.h>
#include "LinkStack.h"

int isNum(char c)
{
	return ('0' <= c)&&(c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int value(char c) 		// Actually, what is this line of code used for? 将字符串的值转换为整型的值？
{
	return (c - '0');		//这句话曾经出现了问题，我把括号里面的内容写成了 c - '\0'。如果是这样的话，就是把char c的值减去了\0。完全
}							//偏离了程序的意思。警戒！

int express(int left, int right, char op)		//这个函数基本上完成了所有的加减乘除的运算过程
{
	int ret = 0;

	switch(op)
	{
		case '+':
			ret = left + right;
			break;
		case '-':
			ret = left - right;
			break;
		case '*':
			ret = left * right;
			break;
		case '/':
			ret = left / right;
			break;
		default:
			break;
	}
	return ret;
}

int compute(const char* exp)
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while(exp[i] != '\0')
	{
		if (isNum(exp[i]))
		{
			LinkStack_Push(stack,(void*)value(exp[i]));
		}
		else if ( isOperator(exp[i]) )
		{
			int right = (int)LinkStack_Pop(stack);
			int left = (int)LinkStack_Pop(stack);
			int result = express(left,right,exp[i]);

			LinkStack_Push(stack,(void*)result);
		}
		else
		{
			printf("Invalid expression!\n");
			break;
		}
		i ++;
	}

	if ( (LinkStack_Size(stack) == 1) && (exp[i] == '\0') )
	{
		ret = (int)LinkStack_Pop(stack);
	}
	else
	{
		printf("Invalid expression!\n"); 
	}
	LinkStack_Destroy(stack);
	return ret;
}

int main(int argc, char const *argv[])
{
	printf("9+(3-1)*5+8/2=%d\n",compute("931-5*+82/+"));	
	return 0;
}