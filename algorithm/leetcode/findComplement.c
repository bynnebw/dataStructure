//本程序主要是对一个数字进行按位取反操作，主要用到的思想还是移位操作。

#include <stdio.h>

int findComplement(int num) 
{
	int tmp = num, i = 0x1;

	while(tmp > 0)
	{
    	num = num^i;
    	tmp = tmp>>1;
    	i = i<<1;
	}
	printf("num = %d\n", num);
	return num;
}

int main(int argc, char const *argv[])
{
	int a = 5;
	findComplement(a);
 	return 0;
}



//    10010110001  		---->    	01101001110 

