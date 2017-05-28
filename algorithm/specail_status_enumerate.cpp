#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 4

//不是太明白整个程序的运作过程，得花时间研究一下 

bool used[MAX_N];
int perm[MAX_N];

//生成{0，1，2，3，4，...，n-1}的n！种排列

void permutation1(int pos,int n){
	if(pos == n)
	{
		//这里编写需要对perm进行的操作
		for( int i = 0;i < MAX_N; i++)
		{
			cout << perm[i] << " ";
		}
		cout << endl;
		return ;
	}
	for(int i = 0;i < n;i ++)
	{
		if(!used[i])
		{
			perm[pos] = i;
			used[i] = true;
			permutation1(pos+1,n);
			used[i] = false;
		}
	}
	return ;
}

int perm2[MAX_N];
void permutation2(int n)
{
	for(int i = 0;i < n;i++)
	{
		perm2[i] = i;
	}
	do{
		//这里编写需要对perm2进行的操作
		for(int i = 0; i < MAX_N; i ++)
		{
			cout << perm2[i] << " ";
		}
		cout << endl;
	}while ( next_permutation(perm2,perm2 + n));

	return ;
}

int main(int argc, char const *argv[])
{
	cout << "permutation1:" << endl;
	for ( int i = 0; i < MAX_N; i ++)
	{
		perm[i] = i;
		used[i] = false;
	}
	permutation1(0,MAX_N);

	cout << "permutation2:" << endl;
	permutation2(MAX_N);
	return 0;
}

