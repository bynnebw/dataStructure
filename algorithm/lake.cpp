#include <iostream>

using namespace std;

/*
**	LakeCounting问题：有一个大小为N*M的园子，雨后积起了水。八联通的积水被认为是链接在一起的
**	请求出院子里总共有多少水洼。“+”被认为是积水，“*”认为是干的。
**	采用深度优先搜索算法进行迭代计算。
*/

const int N = 10;
const int M = 12;

char field[N][M+1] = {
	"+********++*",
	"*+++*****+++",
	"****++***++*",
	"**********+*",
	"*+*+*****++*",
	"+*+*+*****+*",
	"*+*+******+*",
	"**+*******+*"
};

void dfs(int x,int y)
{
	field[x][y] = '*';

	for(int dx = -1;dx <= 1; dx++)
	{
		for(int dy = -1;dy <= 1; dy++)
		{
			int nx = x + dx,ny = y + dy;

			if(0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == '+')
				dfs(nx,ny);
		}
	}
	return ;
}

void solve()
{
	int res = 0;
	for(int i = 0;i < N; i ++)
	{
		for(int j = 0; j < M; j ++)
		{
			if( field[i][j] == '+' )
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