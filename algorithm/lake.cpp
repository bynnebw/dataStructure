#include <iostream>

using namespace std;

/*
**	LakeCounting问题：有一个大小为N*M的园子，雨后积起了水。八联通的积水被认为是链接在一起的
**	请求出院子里总共有多少水洼。“+”被认为是积水，“*”认为是干的。
**	采用深度优先搜索算法进行迭代计算。
*/

const int nn = 6;
const int mm = 6;

char field_1[nn][mm+1] = {
	"w..w..",
	"w.w...",
	".....w",
	".w...w",
	"w...ww",
	"..w..."
};

void dfs(int x,int y)
{
	field_1[x][y] = '.`';

	for(int dx = -1;dx <= 1; dx++)
	{
		for(int dy = -1;dy <= 1; dy++)
		{
			int nx = x + dx,ny = y + dy;

			if(0 <= nx && nx < nn && 0 <= ny && ny < mm && field_1[nx][ny] == 'w')
				dfs(nx,ny);
		}
	}
	return ;
}

void solve()
{
	int res = 0;
	for(int i = 0;i < nn; i ++)
	{
		for(int j = 0; j < mm; j ++)
		{
			if( field_1[i][j] == 'w' )
			{
				dfs(i,j);
				res ++;
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