#include <cstdio>
#include <cmath>


int main()
{
    int n;
    int num[55];
    num[1]=1;
    num[2]=1;
    num[3]=1;
    for(int i=4;i<55;i++)
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
}//Parsed in 0.018 seconds
