/******************************************************
* @author:xiefubao
*******************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

#define min(a,b) (a>b?b:a)
#define max(a,b) (a<b?b:a)
#define eps 1e-8
#define zero(_) (abs(_)<=eps)
const double pi=acos(-1.0);

typedef __int64 LL;
const int Max=50010;
const LL INF=0x3FFFFFFF;

struct edge
{
  int u,v;
  int next;
  int len;
} edges[Max*3];
int tot=0;
int head[Max];
void add(int u,int v,int c)
{
  edges[tot].u=u;
  edges[tot].v=v;
  edges[tot].len=c;
  edges[tot].next=head[u];
  head[u]=tot++;
}
int dist[Max];
int n;
int  mi=Max;
int ma=0;
int que[Max*10];
bool rem[Max];
void spfa()
{
  memset(rem,0,sizeof rem);
  dist[mi]=0;
  rem[mi]=1;
  int left=0;
  int right=1;
  que[0]=mi;
  while(left<right)
  {
    int t=que[left++];
    rem[t]=0;
    for(int i=head[t]; i!=-1; i=edges[i].next)
    {
      int ne=edges[i].v;
      if(dist[ne]>dist[t]+edges[i].len)
      {
        dist[ne]=dist[t]+edges[i].len;
        if(!rem[ne])
        {
          que[right++]=ne;
          rem[ne]=1;
        }
      }
    }
  }
}
int main()
{
  cin>>n;
  memset(head,-1,sizeof head);
  for(int i=0; i<n; i++)
  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
 //   a++;b++;
  //  mi=min(mi,a-1);
  //  ma=max(ma,b);
    add(a,b,c);
  }
  for(i=mi; i<=ma; i++)
  {
 //   add(i,i+1,0);
  //  add(i+1,i,-1);
    dist[i]=0;
  }
  spfa();
  cout<<dist[ma]<<endl;
  return 0;
}