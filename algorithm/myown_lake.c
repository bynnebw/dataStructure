#include <stdio.h>
#define M 6
#define N 6

char field[M][N+1] = {
	"w..w..",
	"w.w...",
	".....w",
	".w...w",
	"w...ww",
	"..w..."
};



void dfs(int i,int j)
{
	int nx = 0;
	int ny = 0;
	field[i][j] = '.';		//所以递归的关键是这里。也就是“初始条件”
	for(int dx = -1;dx <= 1; dx ++)
	{
		for(int dy = -1; dy <= 1; dy ++)
		{
			nx = i + dx,ny = j + dy;
			if (0 < nx && nx < M && 0 <= ny && ny < N && field[nx][ny] == 'w')
			{
				dfs(nx,ny);
			}
		}
	}
}

void solve()
{
	int res = 0;
	for(int i = 0;i < M;i ++)
	{
		for(int j = 0; j < N ; j ++)
		{
			if (field[i][j] == 'w')
			{
				dfs(i,j);
				res++;
			}
		}
	}
	printf("%d\n", res);
}


int main(int argc, char const *argv[])
{
	solve();
	return 0;
}