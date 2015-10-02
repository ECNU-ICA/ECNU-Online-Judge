#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int dp[105][105][2];


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
                scanf("%d",&dp[i][j][0]);
                dp[i][j][1]=dp[i][j][0];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            int maxn=-1;
            for(int j=0;j<=i+1;j++)
                if(maxn<dp[i+1][j][0])
                    maxn=dp[i+1][j][0];
            for(int j=0;j<=i;j++)
            {
                dp[i][j][1]=max(maxn+dp[i][j][0],dp[i][j][1]+max(dp[i+1][j][1],dp[i+1][j+1][1]));
                dp[i][j][0]+=max(dp[i+1][j][0],dp[i+1][j+1][0]);
            }
        }
        printf("%d\n",dp[0][0][0]<dp[0][0][1]?dp[0][0][1]:dp[0][0][0]);
    }
    return 0;
}//Parsed in 0.093 seconds
