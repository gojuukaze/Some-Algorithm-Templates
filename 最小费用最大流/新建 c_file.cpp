#include <stdio.h>
#include <iostream>
#include <string.h>
#include<cmath>
using namespace std;
const int N=1000;
const int MAXE=200000;
const int inf=1<<30;
int head[N],ep;
int d[N],pre[N];
bool vis[N];
int q[MAXE];
struct Edge
{
    int u,v,c,w,next;//u到v,c容量,w费用
}edge[MAXE];
void addedge(int u,int v,int w,int c)//u v 费用 容量
{
    edge[ep].u=u;
    edge[ep].v=v;
    edge[ep].w=w;
    edge[ep].c=c;
    edge[ep].next=head[u];
    head[u]=ep++;
	
    edge[ep].v=u;
    edge[ep].u=v;
    edge[ep].w=-w;
    edge[ep].c=0;
    edge[ep].next=head[v];
    head[v]=ep++;
}
int SPFA(int src,int des)
{
    int l,r;
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=des;i++) d[i]=inf;
    d[src]=0;
    l=0;r=0;
    q[r++]=src;
    vis[src]=1;
    while(l<r)
    {
        int u=q[l++];
        
        for(int j=head[u];j!=-1;j=edge[j].next)
        {
            int v=edge[j].v;
            if(edge[j].c>0&&d[u]+edge[j].w<d[v])
            {
                d[v]=d[u]+edge[j].w;
                pre[v]=j;
                if(!vis[v])
                {
                    vis[v]=1;
                    q[r++]=v;
                }
            }
        }
		vis[u]=0;
    }
    if(d[des]==inf)
        return 0;
    return 1;
}


int MCMF(int src,int des)
{
    int flow=0,ans=0;//flow是得到的最大流的值 ans得到的是最小的费用
    while(SPFA(src,des))
    {
        ans+=d[des];//费用根据实际情况修改
        int u=des;
        int mini=inf;
		int ta,tb;
        while(u!=src)
        {
            if(edge[pre[u]].c<mini)
                mini=edge[pre[u]].c;
            u=edge[pre[u]].u;
        }
        flow+=mini;
        u=des;
        while(u!=src)
        {
            edge[pre[u]].c-=mini;
            edge[pre[u]^1].c+=mini;
            u=edge[pre[u]].u;
        }
    }
//	cout<<flow<<endl;
    return ans;
}


int main()
{
    int n,m,i,j,src,des;
	int u,v,cost,flo;
    while(scanf("%d%d",&n,&m)!=EOF)//点，边
    {
		//初始化
		ep=0;
		memset(head,-1,sizeof(head));
		//s,t点
		scanf("%d%d",&src,&des);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&u,&v,&cost,&flo);
			addedge(u,v,cost,flo);
		}

		int t=MCMF(1,5);
		
		printf("%d\n",t);
	}
    return 0;
}

