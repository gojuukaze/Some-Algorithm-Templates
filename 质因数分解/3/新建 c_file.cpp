#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define LL __int64
//****************************************************************
// Miller_Rabin �㷨������������
//�ٶȿ죬���ҿ����ж� <2^63����
//****************************************************************
const int S=20;//����㷨�ж�������SԽ���д����ԽС


//���� (a*b)%c.   a,b����LL������ֱ����˿��������
//  a,b,c <2^63
LL mult_mod(LL a,LL b,LL c)
{
    a%=c;
    b%=c;
    LL ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}



//����  x^n %c
LL pow_mod(LL x,LL n,LL mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    LL tmp=x;
    LL ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}





//��aΪ��,n-1=x*2^t      a^(n-1)=1(mod n)  ��֤n�ǲ��Ǻ���
//һ���Ǻ�������true,��һ������false
bool check(LL a,LL n,LL x,LL t)
{
    LL ret=pow_mod(a,x,n);
    LL last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//����
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}

// Miller_Rabin()�㷨�����ж�
//����������true.(������α�����������ʼ�С)
//��������false;

bool Miller_Rabin(LL n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//ż��
    LL x=n-1;
    LL t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        LL a=rand()%(n-1)+1;//rand()��Ҫstdlib.hͷ�ļ�
        if(check(a,n,x,t))
            return false;//����
    }
    return true;
}


//************************************************
//pollard_rho �㷨�����������ֽ�
//************************************************
LL factor[100];//�������ֽ������շ���ʱ������ģ�
int tol;//�������ĸ���������С���0��ʼ

LL gcd(LL a,LL b)
{
    if(a==0)return 1;//???????
    if(a<0) return gcd(-a,b);
    while(b)
    {
        LL t=a%b;
        a=b;
        b=t;
    }
    return a;
}

LL Pollard_rho(LL x,LL c)
{
    LL i=1,k=2;
    LL x0=rand()%x;
    LL y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        LL d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
//��n���������ӷֽ�
void findfac(LL n)
{
    if(Miller_Rabin(n))//����
    {
        factor[tol++]=n;
        return;
    }
    LL p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}

int main()
{
    //srand(time(NULL));//��Ҫtime.hͷ�ļ�//POJ��G++���ܼ���仰
    LL n;
    while(scanf("%I64d",&n)!=EOF)
    {
        tol=0;
        findfac(n);
        for(int i=0;i<tol;i++)printf("%I64d ",factor[i]);
        printf("\n");
        if(Miller_Rabin(n))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}