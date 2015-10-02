#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int main()
{
    int n;
    int num[60];
    num[1]=1;
    num[2]=2;
    num[3]=3;
    for(int i=4;i<60;i++)
    {
        num[i]=num[i-1]+num[i-3];
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        printf("%d\n",num[n]);
    }
    return 0;
}//Parsed in 0.032 seconds
