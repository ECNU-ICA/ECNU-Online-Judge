#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int gcd(int a,int b)
{
    if(a==0)
        return b;
    else
        return b==0?a:gcd(b,a%b);
}




int main ()
{
    //freopen("out.txt","w",stdout);
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d\n",gcd(a,b));
    }


    return 0;
}//Parsed in 0.018 seconds
