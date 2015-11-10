/*
方法1：
找父亲(m)下的儿子，
如果儿子是其他数的父亲则把儿子下的数放到儿子的父亲(m)下，
若儿子的儿子下还有儿子再次循环，并放到父亲（m）下，直到儿子的儿子后面没有儿子
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
	bool f;//是否有儿子
	int son[max];
	int count;
}a_son[max];


int main()
{

	int i,j,z,x,y,n,m,k,biaoji,num;
	int temp[max];
	bool end;
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
		a_son[a].f=1;
		a_son[a].son[a_son[a].count]=b;
		a_son[a].count++;
	}
	for(i=0;i<num;i++)
	{
		m=0;
		end=0;
		if(a_son[i].f)
		{
			biaoji=m;
			for(j=0;j<a_son[i].count;j++)
			{
				temp[m++]=a_son[i].son[j];
			}

			while(!end)
			{
				z=biaoji;
				biaoji=m;
				end=1;
				for(z=0;z<biaoji;z++)
				{
					if(a_son[temp[z]].f)
					{a_son[temp[z]].f=0;
						end=0;
						for(x=0;x<a_son[temp[z]].count;x++)
							temp[m++]=a_son[temp[z]].son[x];
					}
				}
			}
			a_son[i].count=0;
			for(z=0;z<m;z++,a_son[i].count++)
			{
				a_son[i].son[a_son[i].count]=temp[z];
			}

		}
	}

	for(i=0;i<a_son[0].count;i++)
		cout<<a_son[0].son[i]<<" ";
	cout<<endl;

    return 0;
} 

