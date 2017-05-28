#include <stdio.h>
#include <queue>

using namespace std;

const int INF = 100000000;
const int N = 10;
const int M = 10;

typedef pair<int,int> P;

char maze[N][M+1] = {
	"#S######.#",
	"......#..#",
	".#.##.##.#",
	".#........",
	"##.##.####",
	"....#....#",
	".#######.#",
	"....#.....",
	".####.###.",
	"....#...G#"
};

int sx = 0,sy = 1;
int gx = 9,gy = 8;

int d[N][M];

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int bfs()
{
	queue<P> que;
	for(int i = 0; i < N; i ++)
	{
		for ( int j = 0; j < M ; j ++)
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

		for(int i = 0;i < 4;i ++)
		{
			int nx = p.first + dx[i],ny = p.second + dy[i];

			if ( 0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
			{
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return	d[gx][gy];
}

void slove()
{
	int res = bfs();
	printf("%d\n", res);
}


int main(int argc, char const *argv[])
{
	slove();
	return 0;
}