#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define N 10001
char s1[N],s2[N];
int next[N];

void getnext(int next[],char s[])
{
	int len,i=0,j=-1;
	next[0]=-1;
	len=(int)strlen(s);
	while(i<len)
	{
		if(j==-1 || s[i]==s[j])
		{
			i++;j++;
			if(s[i]!=s[j])
				next[i]=j;
			else
				next[i]=next[j];
		}
		else
			j=next[j];
	}
}

int KMP2(char s1[],char s2[],int next[])
{
	//返回模式串在主串中出现的首位置
	int i,j,len1,len2;
	i=0;j=0;
	len1=(int)strlen(s1);
	len1=(int)strlen(s1);
	while(i<len1&&j<len2)
	{
		if(j<0||s1[i]==s2[j])
		{
			i++;j++;
		}
		else
			j=next[j];
	}
	if(j==len2)
		return i-j;
	return 0;
}

int KMP(char s1[],char s2[],int next[])
{	//返回最长相同的主串后缀和模式前缀
		int i,j,len1,len2;
	i=0;j=0;
	len1=(int)strlen(s1);
	len1=(int)strlen(s1);
	while(i<len1)
	{
		if(j<0||s1[i]==s2[j])
		{
			i++;j++;
		}
		else
			j=next[j];
	}
	if(j==len2)
		return j;
}

int main()
{
	int ans;
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		getnext(next,s2);
		ans=KMP(s1,s2,next);
		if(ans!=0)
			printf("%d\n",ans+1);
		else
			printf("No!\n");
	}
	return 0;
}