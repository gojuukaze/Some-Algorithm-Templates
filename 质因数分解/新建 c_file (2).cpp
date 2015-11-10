#include<math.h> 
#include<stdio.h> 
main() 
{ 
	freopen("in.txt","r",stdin);
int a,b,c; 
	while(~scanf("%d",&a))
	{
printf("%d=",a); 
for(b=2;(int)sqrt((double)a)>=b;b++) 
{ 
c=a%b; 
if(c==0) 
{ 
printf("%d*",b); a=a/b;b--; 
} 
} 
printf("%d\n",a); 
	}
} 