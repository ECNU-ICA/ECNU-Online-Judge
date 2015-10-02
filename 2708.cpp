#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>


using namespace std;


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            printf("1\n");
        else if(n==1)
            printf("0\n");
        else
        {
            if(n%2==0)
            {
                for(int i=0;i<n/2;i++)
                {
                    printf("8");
                }
            }
            else
            {
                printf("4");
                for(int i=0;i<(n-1)/2;i++)
                {
                    printf("8");
                }
            }
            printf("\n");
        }
    }


    return 0;
}//Parsed in 0.046 seconds
