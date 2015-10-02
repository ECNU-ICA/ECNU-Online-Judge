#include <cstdio>
#include <cstring>
#include <cmath>


int main()
{
    int n;
    int mmap[35][35];
    for(int i=1;i<35;i++)
    {
        mmap[i][1]=1;
        mmap[i][i]=1;
    }
    for(int i=3;i<35;i++)
    {
        for(int j=2;j<i;j++)
        {
            mmap[i][j]=mmap[i-1][j]+mmap[i-1][j-1];
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(j!=1)
                {
                    printf(" ");
                }
                printf("%d",mmap[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.072 seconds
