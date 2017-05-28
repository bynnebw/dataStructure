#include <stdio.h>
#include <queue>

using namespace std;

const int INF = 1000;
const int N = 5;
const int M = 5;

char maze[N][M+1] = {
	"#S...",
	"..#..",
	".....",
	".#..#",
	"..#.G"
};

typedef pair<int,int> P;

int sx = 0,sy = 1;
int gx = 4,gy = 4; 

int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

int d[N][M]; //到各个位置最短距离的数组


int bfs()
{
	queue<P> que;
	for (int i = 0;i < N;i ++)
	{
		for(int j = 0; j < M;j ++)
		{
			d[i][j] = INF;
		}
	}

	que.push(P(sx,sy));
	d[sx][sy] = 0;

	while(que.size())
	{
		P p = que.front();que.pop();
		if(p.first == gx && p.second == gy)
			break;

		for(int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i],ny = p.second + dy[i];
			if ( 0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
			{
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;	
			}
		}
	}
	return d[gx][gy];
}

void solve()
{
	int res = bfs();
	printf("The number is %d\n", res);
}

int main(int argc, char const *argv[])
{
	solve();
	return 0;
}