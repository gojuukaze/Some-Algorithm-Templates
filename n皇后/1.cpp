/*
x�����꣬��ʾ��
y�����꣬��ʾ��

*/


/*
��֦��
��Ϊ���з��ã�����Ŀ��Բ����жϡ�
���Ե�����棬��б�Ϸ�,��б�Ϸ�Ҳ���Բ��ж�

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

#define LL __int64

int vis[13][13];//���ڱ��
int vx[]={0,1,-1};
int vy[]={1,1,1};
LL theba;
//���
int biaoji(int x,int y,int m)
{
	vis[y][x]++;
	int i,a,b;
	for(i=0;i<3;i++)
	{
		for(a=x+vx[i],b=y+vy[i];a>=0 && a<m && b>=0 && b<m;a+=vx[i],b+=vy[i])
		{
			vis[b][a]++;
		}
	}
	return 0;
}
//����
int huisu(int x,int y,int m)
{
	if(vis[y][x]==0)
		return 0;
	int i,a,b;
	for(i=0;i<3;i++)
	{
		for(a=x+vx[i],b=y+vy[i];a>=0 && a<m && b>=0 && b<m;a+=vx[i],b+=vy[i])
		{
			if(vis[b][a]>0)
				vis[b][a]--;
		}
	}
	vis[y][x]--;
	return 0;
}
//��Ҫ�㷨
int bahuanghou(int x,int y,int num,int m)
{
	int i,j,ten;
	num++;
//	temp[y]=x+1;
	if(num>=m)
	{
		theba++;
		return 0;
	}
	else
	{
		biaoji(x,y,m);
		j=y+1;
		for(i=0;i<m;i++)
		{
			if(vis[j][i]==0)
			{
				bahuanghou(i,j,num,m);
				huisu(i,j,m);
			}
		}
	}
	return 0;
}
int main()
{
	int n,m,i,j,t;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			theba=0;
			scanf("%d",&m);
			//memset(ba,0,sizeof(ba));
			for(i=0;i<m;i++)
			{	
				memset(vis,0,sizeof(vis));
				bahuanghou(i,0,0,m);
			}
			
			printf("%I64d\n",theba);
		}
	}
	return 0;
}