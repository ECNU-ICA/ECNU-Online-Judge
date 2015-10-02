#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>


using namespace std;
int const maxSize=105;
int A[maxSize][maxSize];
int B[maxSize][maxSize];
int C[maxSize][maxSize];


int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&A[i][j]);
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&B[i][j]);
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                C[i][j]=0;
                for(int k=0;k<n;k++)
                {
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j!=0)
                    printf(" %d",C[i][j]);
                else
                    printf("%d",C[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}//Parsed in 0.105 seconds
