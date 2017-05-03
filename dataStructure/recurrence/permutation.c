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
				s[b] = s[i];		//把出去一个元素之后的其他元素进行全排列，排列完之后，还需要把交换过的元素再交换回来
				s[i] = c;			//这样再下一次循环的时候，就可以继续对除去下一个元素之外的其他元素进行全排列。

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