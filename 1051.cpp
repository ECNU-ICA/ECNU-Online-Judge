#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <set>


using namespace std;


long long dp[55][55];//dp[i][j] 第i个矩阵到第j个矩阵的最优解
int x[55],y[55];


int main()
{
    //freopen("in.txt","r",stdin);
    int N,n;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        memset(dp,0x7f,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            dp[i][i]=0;
        }
        //当i<j m[i][j] = min{ m[i][k]+m[k+1][j]+Pi-1*Pk*Pj }
        for(int l=2;l<=n;l++)//矩阵长度
        {
            for(int i=1;i<=n-l+1;i++)// i开始坐标
            {
                int j=i+l-1;// j结束坐标
                int mini;
                for(int k=i;k<j;k++)
                {
                    mini=dp[i][k]+dp[k+1][j]+x[i]*y[k]*y[j];
                    //printf("i=%d j=%d %I64d %I64d %I64d %d\n",i,j,dp[i][j],dp[i][k],dp[k+1][j],x[i]*y[k]*y[j]);
                    if(dp[i][j]>mini)
                        dp[i][j]=mini;
                }
            }
        }
        printf("%I64d\n",dp[1][n]);


    }
    return 0;
}//Parsed in 0.095 seconds
