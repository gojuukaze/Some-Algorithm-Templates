#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 500000

bool isprime[(N-1)/2];

void initprime()
{
	int i,j;
	memset(isprime,true,sizeof(isprime));
	for(i=3;i*i<=N;i+=2)
		if(isprime[(i-1)/2]) 
		{
			for(j=i*i;j<=N;j+=2*i)
				isprime[(j-1)/2]=false;
		}
}
bool fprime(int n)
{
	if(n==1 || n==0)
		return false;
	if(n==2)
		return true;
	else
		if(!(n&1))
			return false;
		else
			if(isprime[(n-1)/2]) return true;
			else return false;
}
int main()
{
	int T,a,b,i,j,num;
	bool ans;

	initprime();//³õÊ¼»¯
	while(~scanf("%d",&T))
	{
		if(fprime(T))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}