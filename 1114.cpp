#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;


/////////////2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67  71 73 83 89 93 97
int prime[]= {2,3,5,7,11,13,17,19,23,29,31,37};
bool vis[25];
int cycle[25];
int n;
bool check(int a,int b)
{
    for(int i=0; i<12; i++)
    {
        if(a+b==prime[i])
            return true;
    }
    return false;
}
void dfs(int x)
{
    if(x>1)
       if(!check(cycle[x],cycle[x-1])) return ;
    if(x==n)
    {
        if(check(cycle[n],cycle[1]))
        {
            for(int i=1; i<=n; i++)
            {
                if(i==1)
                    printf("%d",cycle[i]);
                else
                    printf(" %d",cycle[i]);
            }
            printf("\n");
        }
        return ;
    }
    for(int i=2; i<=n; i++)
    {
        if(!vis[i])
        {
            vis[i]=true;


            cycle[x+1]=i;
            dfs(x+1);
            vis[i]=false;
        }
    }
}
int main ()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,false,sizeof(vis));
        vis[1]=true;
        cycle[1]=1;
        dfs(1);
    }
    return 0;
}//Parsed in 0.111 seconds
