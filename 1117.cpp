#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


typedef __int64 LL;
LL extgcd(LL a, LL b, LL &x, LL &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    LL d = extgcd(b,a%b,x,y);
    LL t = x;
    x = y;
    y = t - a/b*y;
    return d;
}
//Çó½âÄ£ÏßÐÔ·½³Ì×éx mod ai =bi
LL China_Reminder(int len, LL* a, LL* n)
{
    int i;
    LL N = 1;
    LL result = 0;
    for(i = 0; i < len; i++)
        N = N*n[i];
    for(i = 0; i < len; i++)
    {
        LL m = N/n[i];
        LL x,y;
        extgcd(m,n[i],x,y);
        x = (x%n[i]+n[i])%n[i];
        result = (result + m*a[i]*x%N)%N;
    }
    return result;
}
LL a[1005],b[1005];


int main ()
{
    int cas,n;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%I64d",&a[i]);
        for(int i = 0; i < n; i++)
            scanf("%I64d",&b[i]);
        printf("%I64d\n",China_Reminder(n,b,a));
    }
    return 0;
}//Parsed in 0.066 seconds
