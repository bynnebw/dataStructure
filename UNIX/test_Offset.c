#include "apue.h"

//程序用于测试对其标准输入能否设置偏移量

int main(int argc, char const *argv[])
{
	if ( lseek(STDIN_FILENO,0,SEEK_CUR) == -1 )
		printf("cannot seek\n");

	else
		printf("seek OK\n");

	exit(0);
}