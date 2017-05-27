#include <stdio.h>
#define true 1
#define false 0

/*
**	部分和问题
**	采用深度优先搜索算法进行“穷竭搜索”。算法的时间复杂度是O(2^n)。
*/

int dfs(int i,int sum,int* a,int n,int k)
{
	if (i==n)	
		return sum == k;
	
	if (dfs(i+1,sum,a,n,k)) 
		return true;
	
	if (dfs(i+1,sum+a[i],a,n,k)) 
		return true;
	
	return false;
}

void solve(int* a,int n,int k)
{
	if(dfs(0,0,a,n,k))
		printf("Yes\n");
	else
		printf("No\n");
}

int main(int argc, char const *argv[])
{
	const int MAX_N = 20;
	int a[MAX_N] = {1,2,4,7};
	int n = 4,k = 13;

	solve(a,n,k);

	return 0;
}