/*
**	The hamming distance is to calculate the number varies 
**	of the two numbers, if the bits id different ,then cal+1
**	Just like this demo , first translate the two numbers 
**	in binary expression , and then compare the two numbers
**	using bit by bit.
*/

#include <stdio.h>

int solve(int a, int b)
{	
	int tmpInt=a^b;		
    int dis=0;
    
    while(tmpInt)
    {
        if((tmpInt>>1)<<1 != tmpInt)
        {
            ++dis;
        }
        
        tmpInt>>=1;
    }
    
	printf("The hamming distance is :%d\n", dis);
	return 0;
}

int main(int argc, char const *argv[])
{
	int a = 1, b = 4;
	solve(a,b);
	return 0;
}