#include <cstdio>
#include <cstring>
#include <cmath>
int gcd(int a,int b)
{
    while(a!=b)
    {
        if (a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}


int main()
{
    int mgcd,mlcm;
    int N;
    int a,b;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&a,&b);
        mgcd=gcd(a,b);
        mlcm=(int)(1.0*a/mgcd)*b;
        printf("%d %d\n",mgcd,mlcm);
    }
    return 0;
}//Parsed in 0.042 seconds
