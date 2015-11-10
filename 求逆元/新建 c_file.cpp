//扩展欧几里德求逆元模板:
#include<iostream>

int mod;
int find(int x)  
{  
    int k=mod-2,ans=1;  
    while(k)  
    {  
        if (k&1) ans=(int)ans*x%mod;  
        x=(int)x*x%mod;  
        k>>=1;  
    }  
    return ans;  
}

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
		mod=c;
          int x=find(b)
			  cout<<(a*x)%c<<endl;
          }
    return 0;
    }
