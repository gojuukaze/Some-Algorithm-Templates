#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000000

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

int f(int n,int p)
{
    if(n==0) 
		return 0;
    return f(n/p,p) + n/p;
}


int main()
{
	initprime();
	int x;
	while(cin>>x)
	{
		printf("%d!ÖÐ ",x);

		for(int i=2;i<=x;i++)
		{
			if(fprime(i))
			{
				printf( "%dÓÐ%d¸ö," ,i,f(x,i) );
			}
		}
		printf("\n");
	}

	return 0;
}