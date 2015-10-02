#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int f(int a,int b)
{
    int con=0;
    while(a!=0&&b!=0)
    {
        if((a&1)!=(b&1))
            con++;
        a=a>>1;
        b=b>>1;
    }
    while(a!=0)
    {
        if((a&1)!=0)
            con++;
        a=a>>1;
    }
    while(b!=0)
    {
        if((b&1)!=0)
            con++;
        b=b>>1;
    }
    return con;
}


int main()
{
    int n,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}//Parsed in 0.041 seconds
