#include<cstdio>
#include<cstring>
#include<queue>


using namespace std;


int dp[110];


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                    dp[j]+=dp[j-i];
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}//Parsed in 0.040 seconds
