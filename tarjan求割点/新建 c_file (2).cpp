#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 10001
typedef vector<int>::iterator it;
vector<int> g[maxn];
int dfn[maxn],low[maxn];
bool vit[maxn];
int n,idx,sons;
int ans;
 
void dfs(int u,bool root)
{
    vit[u]=1;
    dfn[u]=low[u]=++idx;
    int child=0;
    for(it i=g[u].begin();i!=g[u].end();++i)
    {
        int v=*i;
        if(!dfn[v])
        {
            dfs(v,false);
            low[u]=min(low[u],low[v]);
            if(root)
                sons++;
            else if(low[v]>=dfn[u])
                child++;
        }
        else low[u]=min(low[u],dfn[v]);
    }
    ans=max(ans,child+1);
}
 
int tarjan(int root)
{
    if(g[root].size()==0) return 0;
    memset(dfn,0,sizeof(dfn));
    ans=idx=sons=0;
    dfs(root,true);
    if(sons>1) ans=max(ans,sons);
    return ans;
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
    int m,u,v;
    while(scanf("%d%d",&n,&m)!=EOF && n)
    {
        for(int i=0;i<n;i++)
            g[i].clear();
        while(m-->0)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(vit,0,sizeof(vit));
        int ma=0,total=0;
        for(int i=0;i<n;i++)
            if(!vit[i])
                total++,ma=max(ma,tarjan(i));
        printf("%d\n",total+ma-1);
    }
}