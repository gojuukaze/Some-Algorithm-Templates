/*
方法2：
先找儿子的父亲，然后找父亲的父亲。
找到最终的父亲后，刚才的数，若有儿子，则把儿子都归类到最终父亲下（循环直到没有儿子），没儿子就直接归类到最终父亲下

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

	scanf("%d%d",&n,&num);//n:有n组关系。num:最大的数据（表示有0-num个数）。
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
			//找父亲
			while(have_f[j])
			{
				have_f[z]=0;
				temp[m++]=j;
				z=j;
				j=father[j];
			}
			have_f[z]=0;
			a_son[j].f=1;
			//找儿子
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

