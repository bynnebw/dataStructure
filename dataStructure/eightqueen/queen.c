#include <stdio.h>
#define N 8

/*
**	解决此问题主要利用到的事回溯法，其实就类似于下棋的时候可以悔棋
**	具体的实现方式是利用递归的方法，通过栈调用保存活动记录，保存运行
**	时的临时变量，以便在想要悔棋的时候可以重新找回原来的数据，进行回溯算法
*/


typedef struct _tag_Pos
{
	int ios;	//i轴方向的偏移量
	int jos;	//j轴方向的偏移量	
} Pos;

static char board[N+2][N+2];
static Pos pos[] = {{-1,-1},{-1,0},{-1,1}};
static int count = 0;

void init()
{
	int i = 0;
	int j = 0;

	for(i = 0;i < N+2; i ++)
	{
		board[0][i] = '#';
		board[N+1][i] = '#';
		board[i][0] = '#';
		board[i][N+1] = '#';
	}

	for(i = 1; i <= N; i++)
	{
		for(j = 1;j <= N;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void display()
{
	int i = 0;
	int j = 0;

	for(i = 0;i < N+2;i ++)
	{
		for(j = 0;j < N+2;j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int check(int i,int j)
{
	int ret = 1;
	int p = 0;

	for(p = 0;p < 3;p++)
	{
		int ni = i;
		int nj = j;

		while( ret && (board[ni][nj] != '#') )
		{
			ni = ni + pos[p].ios;
			nj = nj + pos[p].jos;

			ret = ret&&(board[ni][nj] != '*');
		}
	}

	return ret;
}

void find(int i)
{
	int j = 0;

	if ( i > N )
	{
		count ++;
		printf("Solution: %d\n", count);
		display();
		getchar();
	}
	else
	{
		for(j = 1;j <= N;j++)
		{
			if (check(i,j))						//所以真正用到回溯法的地方是这里，使用递归的方法实现回溯。
			{
				board[i][j] = '*';		
				find(i+1);
				board[i][j] = ' ';
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	init();
	find(1);
	return 0;
}