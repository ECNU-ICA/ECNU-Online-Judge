#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;


int dp[105][105];


int main ()
{
    //freopen("in.txt","r",stdin);
    int cas,n;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                scanf("%d",&dp[i][j]);
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}//Parsed in 0.033 seconds
