#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 500000
__int64 a[N];
//直接打印
void zhi(__int64 n)
{
  __int64 i;
  printf("%I64d=",n);
  for(i=2;i<=n;i++)
    while(n!=i)
    {
      if(n%i==0)
      {
        printf("%I64d*",i);
        n=n/i;
      }
      else
        break;
    }
  printf("%I64d",n);
	printf("\n");
}
//返回数组
zhi2(__int64 n)
{

	__int64 i,j;
	printf("%I64d=",n);
  for(i=2;i<=n;i++)
  {
    while(n!=i)
    {
      if(n%i==0)
      {
        a[i]++;
        n=n/i;
      }
      else
        break;
    }
  }
  a[n]++;

  for(i=0;i<N;i++)
  {
	  if(a[i]>0)
	  {
		  for(j=0;j<a[i];j++)
			  printf("%I64d=",i);
	  }
  }
  	printf("\n");
}

main()
{freopen("in.txt","r",stdin);
  __int64 n,i,j;
  memset(a,0,sizeof(a));
  while(~scanf("%I64d",&n))
  {
  zhi(n);
  //zhi2(n);
  }

}

