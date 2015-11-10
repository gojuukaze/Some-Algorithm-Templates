#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
int arry[10]={12,6,77,9,8,0,1,34,5,2};

struct node
{
	int i,j,max;
	node *pr,*pl;
};

node *TREE(int a,int b)
{
	node *p=new node;
	p->i=a;
	p->j=b;	
	if(a+1!=b)
	{
		p->pl=TREE(a,(a+b)/2);
		p->pr=TREE((a+b)/2,b);
	}
	if(a+1==b)
		p->max=arry[a-1]>arry[b-1]?arry[a-1]:arry[b-1];
	else
		p->max=p->pl->max > p->pr->max?p->pl->max:p->pr->max;

	return p;
}
show(int a,int b,node *p)
{
	if(p->i==a && p->j==b)
		return p->max;
	else
	{
		
		if(b<=(p->i+p->j)/2)
			return show(a,b,p->pl);
		else if(a>=(p->i+p->j)/2)
		{		
				return show(a,b,p->pr);
		}
		else
		{
			int tempa,tempb;
			tempa=show(a,(p->i+p->j)/2,p->pl);
			tempb=show((p->i+p->j)/2,b,p->pr);
			return tempa>tempb?tempa:tempb;
		}
	}
}
int main()
{
	node *root;
	root=TREE(1,10);
	printf("(1,2) %d \n",show(1,2,root));
	printf("(3,5) %d \n",show(3,5,root));
	printf("(5,10) %d\n",show(5,10,root));
	printf("(4,7) %d \n",show(4,7,root));
	printf("(4,8) %d \n",show(4,8,root));
return 0;
}