#include "apue.h"

#define BUFFSIZE 4906

int main(int argc, char const *argv[])
{
	int n;

	char buf[BUFFSIZE];

	while( ( n = read(STDIN_FILENO,buf,BUFFSIZE)) > 0 )
	{
		if (write(STDOUT_FILENO,buf,n) != n)
			printf("wirte error\n");

		if (n < 0)
			printf("read error\n"); 
	}


	exit(0);
}