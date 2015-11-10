#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define X 102
#define min(a,b) (a<b?a:b)  
int map[X][X],dfn[X],low[X],ans[X],n,m,depth;
void dfs(int v)
{
   dfn[v] = low[v] = ++depth;
   for(int i=1;i<=n;i++)
      if(map[v][i]==1)
      {
         map[v][i] = map[i][v] = 2;
         if(!dfn[i])    
         {
            dfs(i);    
            low[v] = min(low[v],low[i]);
            if(low[i]>=dfn[v])
                ans[v]++;
         }
         else        
         {
            low[v] = min(low[v],dfn[i]);
            //printf("low[%d] = %d\n",v,low[v]);
         }
      }
}
void init()
{
   memset(map,0,sizeof(map));
   memset(dfn,0,sizeof(dfn));
   memset(low,0,sizeof(low));
   memset(ans,0,sizeof(ans));
   depth = 0;
}
int main()
{
//   freopen("sum.in","r",stdin);
 //  freopen("sum.out","w",stdout);
   int x,y;
   while(cin>>n,n)
   {
      init();
      while(cin>>x,x)
      {
         while(getchar()!='\n')
         {
            cin>>y;
            map[x][y] = map[y][x] = 1;//????
         }
      }
      dfs(1);
      ans[1]--;
      int cnt = 0;
      for(int i=1;i<=n;i++)
         if(ans[i]>0)
         {
            cout<<" "<<i<<endl;
            cnt++;
         }
      cout<<cnt<<endl;
   }
 
   return 0;
}