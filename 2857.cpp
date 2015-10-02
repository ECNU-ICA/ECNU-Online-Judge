#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <cctype>


using namespace std;


int dp[510][510];
char strA[510];
char strB[510];
int f(int i,int j)
{
    if(strA[i-1]==strB[j-1])
        return 0;
    return 1;
}
int mmin(int x,int y,int z)
{
    return min(min(x,y),z);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);getchar();
    while(n--)
    {
        gets(strA);
        gets(strB);
        int lenA=strlen(strA);
        int lenB=strlen(strB);
        for(int i=1;i<=lenA;i++)
        {
            dp[i][0]=i;
        }
        for(int i=1;i<=lenB;i++)
        {
            dp[0][i]=i;
        }
        dp[0][0]=0;
        for(int i=1;i<=lenA;i++)
        {
            for(int j=1;j<=lenB;j++)
            {
                dp[i][j]=mmin(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+f(i,j));
            }
        }
        printf("%d\n",dp[lenA][lenB]);
    }
    return 0 ;
}//Parsed in 0.092 seconds
