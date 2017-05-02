#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int isLeft (char c)
{
	int ret = 0;

	switch(c)
	{
		case '<':
		case '(':
		case '{':
		case '[':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
			break;
	}
	return ret;
}

int isRight (char c)
{
	int ret = 0;

	switch(c)
	{
		case '>':
		case ')':
		case '}':
		case ']':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
			break;
	}
	return ret;
}

int match(char left,char right)
{
	int ret = 0;

	switch(left)
	{
		case '<':
			ret = (right == '>');
			break;
		case '(':
			ret = (right == ')');
			break;
		case '{':
			ret = (right == '}');
			break;
		case '[':
			ret = (right == ']');
			break;
		case '\'':
			ret = (right == '\'');
			break;
		case '\"':
			ret = (right == '\"');
			break;
		default:
			ret = 0;
			break;
	}
	return ret;
}

int scanner(const char* code)
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while( code[i] != '\0' )
	{
		if ( isLeft(code[i]) )
		{
			LinkStack_Push( stack, (void*)(code + i) ) ;
		}
		if ( isRight(code[i]) )
		{
			char* c = (char*)LinkStack_Pop(stack);

			if ( (c == NULL) || !match(*c,code[i]))
			{
				printf("%c does not match !\n", *c);
				ret = 0;
				break;
			}
		}

		i ++;
	}

	if ( (LinkStack_Size(stack) == 0) && (code[i] == '\0') )
	{ 
		printf("Succeed!\n");		
		ret = 1;
	}
	else
	{
		printf("Invalid code!\n");
		ret = 0;
	}

	LinkStack_Destroy(stack);

	return ret;
}


int main(int argc, char const *argv[])
{
	const char* code = "sji<>fjiesfgji<jfgisj>sdjglifsdjgio<ksjfg>idsjfis";
	scanner(code);
	return 0;
}