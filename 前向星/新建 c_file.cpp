#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#define MAX 100005

using namespace std;


struct edge{
	int Next,to;
} G[MAX];
int g[MAX];

int edgecnt;


void addedge(int u, int v) 
{	
	G[ edgecnt ].to = v;
	G[ edgecnt ].Next = g[u];
	g[u] = edgecnt++;
}

int find(int u)
{
	int i,v;

	for(i=g[u];i!=-1;i=G[i].Next)
	{
		v=G[i].to;
		
	}
	return 0;
}

int main()
{
	

	memset(g,-1,sizeof(g));
	
	return 0;
}