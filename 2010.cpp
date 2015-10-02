#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>


using namespace std;


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n-i;j++)
            {
                //printf("-");
                printf(" ");
            }
            for(int j=0;j<2*i+1;j++)
            {
                printf("*");
            }
            for(int j=0;j<n-i;j++)
            {
                //printf("-");
                printf(" ");
            }
            printf("\n");
        }
        for(int i=0;i<2*n+1;++i)
        {
            printf("*");
        }
        printf("\n");
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i+1;j++)
            {
                //printf("-");
                printf(" ");
            }
            for(int j=0;j<2*(n-i)-1;j++)
            {
                printf("*");
            }
            for(int j=0;j<i+1;j++)
            {
                //printf("-");
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}//Parsed in 0.122 seconds
