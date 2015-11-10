/*
bellman_ford
不能有负环
*/

#include <iostream>
using namespace std;
#define MAXV 50002
#define INF INT_MAX
#define min(a,b) (a>b?b:a)
#define max(a,b) (a<b?b:a)

typedef struct{
	int s,t,w;//s起，t终
}Edge;

Edge edge[MAXV];
int n,d[MAXV],mi,ma;

void bellman_ford(){
	int i;
	bool flag=true;
	while(flag)
	{
		flag=false;
		//要使所有的点满足b-a <= c
		for(i=1;i<=n;i++)
		{			
			if(d[edge[i].t]>d[edge[i].s]+edge[i].w)
			{
				d[edge[i].t]=d[edge[i].s]+edge[i].w;
				flag=true;
			}
		}

	}
}

int main(){
	int i;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&edge[i].s,&edge[i].t,&edge[i].w);
			d[i]=0;						//初始化
		}
		bellman_ford();
	}
	return 0;
}