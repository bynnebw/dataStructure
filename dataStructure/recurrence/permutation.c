#include <stdio.h>

void permutation(char s[],int b,int e)
{
	if ( (0 <= b) && (b <= e))
	{
		if ( b == e )
		{
			printf("%s\n", s);
		}
		else
		{
			int i = 0;

			for(i = b;i <= e;i++)
			{
				char c = s[b];
				s[b] = s[i];
				s[i] = c;

				permutation(s,b+1,e);

				c = s[b];			//Don't know what's the use of the next three lines of codes.
				s[b] = s[i];
				s[i] = c;

			}
		}
	}
}

int main(int argc, char const *argv[])
{
	char s[] = "abc";
	permutation(s,0,2);
	return 0;
}