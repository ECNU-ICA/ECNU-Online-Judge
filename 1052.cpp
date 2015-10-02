#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <set>


using namespace std;


int dp[100005];
struct E
{
    int w,p;
}s[25];
int main()
{
    //freopen("in.txt","r",stdin);
    int N,n,M;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&n,&M);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&s[i].w,&s[i].p);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=M;j>=s[i].w;--j)
            {
                dp[j]=max(dp[j],dp[j-s[i].w]+s[i].p);
            }
        }
        printf("%d\n",dp[M]);
    }
    return 0;
}//Parsed in 0.034 seconds
