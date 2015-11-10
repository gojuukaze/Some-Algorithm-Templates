#include<cstdio>

main() 
{ 
	//	freopen("in.txt","r",stdin);

	int a,i,temp; 

	while(~scanf("%d",&a))
	{
	printf("%d=",a); 
	temp=a; 
	for(i=2;a>=i;i++) 
	{ 
		while(temp!=i)
		{
			if(temp%i==0) 
			{ 
				printf("%d*",i); 
				temp=temp/i;
		//	i--; 
			} 
			else 
			{
				a=temp/i;
				break;
			}
		}
	} 
	printf("%d\n",temp); 
	}
}