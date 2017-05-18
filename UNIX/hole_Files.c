#include "apue.h"
#include <fcntl.h>

/*
**	程序用于创建一个具有空洞的文件
**
*/


char buf1[] = "abcdefghij" ;
char buf2[] = "ABCDEFGHIJ" ;

int main(int argc, char const *argv[])
{
	int fd;

	if ((fd = creat("file.hole",FILE_MODE)) < 0)
	{
		printf("create error\n");
	}

	if ( write(fd,buf1,10) != 10 )
	{
		printf("buf1 write error\n");
	}

	if (lseek(fd,16384,SEEK_SET) == -1 )
	{
		printf("lseek error\n");
	}

	if (write(fd,buf2,10) != 10)
	{
		printf("buf2 write error\n");
	}


	exit(0);
}