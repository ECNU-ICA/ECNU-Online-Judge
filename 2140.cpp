#include <cstdio>
#include <cstring>//c
#include <string>//C++
#include <cmath>
#include <cstdlib>


using namespace std;


int A[1005][1005];
int B[1005][1005];
int main()
{
    int c,m,n;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&B[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                A[i][j]+=B[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j!=0)
                    printf(" %d",A[i][j]);
                else
                    printf("%d",A[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}//Parsed in 0.068 seconds
