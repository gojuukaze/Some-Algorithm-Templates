/*
����2��
���Ҷ��ӵĸ��ף�Ȼ���Ҹ��׵ĸ��ס�
�ҵ����յĸ��׺󣬸ղŵ��������ж��ӣ���Ѷ��Ӷ����ൽ���ո����£�ѭ��ֱ��û�ж��ӣ���û���Ӿ�ֱ�ӹ��ൽ���ո�����

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL __int64
#define max 100


struct SON
{
	bool f;
	int son[max];
	int count;
}a_son[max];
int father[max];
bool have_f[max];

int main()
{

	int i,j,z,x,y,n,m,k,biaoji;
	int temp[max];
	bool end;
	memset(father,-1,sizeof(father));
	memset(have_f,0,sizeof(have_f));
	for(i=0;i<max;i++)
	{
		a_son[i].count=0;
		a_son[i].f=0;
	}

	scanf("%d%d",&n,&num);//n:��n���ϵ��num:�������ݣ���ʾ��0-num��������
	int a,b;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		father[b]=a;
		have_f[b]=1;
		a_son[a].f=1;
		a_son[a].son[a_son[a].count]=b;
		a_son[a].count++;

	}
	for(i=0;i<num;i++)
	{
		biaoji=m=0;
		end=0;
		if(have_f[i])
		{
			temp[m++]=i;
			j=father[i];
			z=i;
			//�Ҹ���
			while(have_f[j])
			{
				have_f[z]=0;
				temp[m++]=j;
				z=j;
				j=father[j];
			}
			have_f[z]=0;
			a_son[j].f=1;
			//�Ҷ���
			while(!end)
			{
				end=1;
				z=biaoji;
				biaoji=m;
				for(;z<biaoji;z++)
				{
					if(a_son[temp[z]].f)
					{
						a_son[temp[z]].f=0;
						end=0;
						for(x=0;x<a_son[temp[z]].count;x++)
						{
							temp[m++]=a_son[temp[z]].son[x];
							
						}
					}
				}
			}
			for(z=0;z<m;z++,a_son[j].count++)
			{
				a_son[j].son[a_son[j].count]=temp[z];
			}
		}
	}

	for(i=0;i<a_son[0].count;i++)
		cout<<a_son[0].son[i]<<" ";
	cout<<endl;

    return 0;
} 

