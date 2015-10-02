#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <set>


using namespace std;


int dp[20005];
int vv[35];


int main()
{
    //freopen("in.txt","r",stdin);
    int V,n;
    while(scanf("%d",&V)!=EOF)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&vv[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=V;j>=vv[i];j--)
            {
                dp[j]=max(dp[j],dp[j-vv[i]]+vv[i]);
            }
        }
        printf("%d\n",V-dp[V]);
    }
    return 0;
}//Parsed in 0.057 seconds
