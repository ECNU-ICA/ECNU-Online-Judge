#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int main()
{
    int a,b,t;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%.3lf\n",sqrt(a*a+b*b));
    }
    return 0;
}//Parsed in 0.021 seconds
