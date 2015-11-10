__int64 exGcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
    if(b==0)
	{
        x=1;
        y=0;
        return a;
    }
    __int64 g=exGcd(b,a%b,x,y);
    __int64 temp=x;
    x=y;
    y=temp-(a/b)*y;
    return g;
}