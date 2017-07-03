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
        if((tmpInt>>1)<<1 != tmpInt)	//这里将tmpInt值先右移一位，再左移回来，这样可以将原来的	
        {								//数值的最后一位置为0，这样再与原来的值相比较就可以知道了
            ++dis;						//最后一位与原来的最后一位是否一致。如果不一致自然就置为1咯
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