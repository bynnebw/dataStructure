#include <stdio.h>

void hanoi(int n,char a,char b,char c)
{
	if ( n > 0 )
	{
		if ( n == 1 )
		{
			printf("%c -> %c\n", a,c);
		}
		else
		{
			hanoi(n-1,a,c,b);				//借助c，将a传送到b
			printf("%c -> %c\n", a,c);
			hanoi(n-1,b,a,c);
		}
	}
}

int main(int argc, char const *argv[])
{
	hanoi(3,'a','b','c');
	return 0;
}