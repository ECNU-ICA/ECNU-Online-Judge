#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int adj[105][105];
int n,cnt;
int num;
// 0 1 2 3
void dfs(int x,int y,int dir)
{
    if(cnt>num)
        return ;
    if(dir==0)
    {
        if(y+1<n&&adj[x][y+1]==-1)
        {
            adj[x][y+1]=cnt++;


            dfs(x,y+1,dir);
        }
        else
        {
            dfs(x,y,1);
        }
    }
    else if(dir==1)
    {
        if(x+1<n&&adj[x+1][y]==-1)
        {
            adj[x+1][y]=cnt++;
            dfs(x+1,y,dir);
        }
        else
        {
            dfs(x,y,2);
        }
    }
    else if(dir==2)
    {
        if(y-1>=0&&adj[x][y-1]==-1)
        {
            adj[x][y-1]=cnt++;
            dfs(x,y-1,dir);
        }
        else
        {
            dfs(x,y,3);
        }
    }
    else
    {
        if(x-1>=0&&adj[x-1][y]==-1)
        {
            adj[x-1][y]=cnt++;
            dfs(x-1,y,dir);
        }
        else
        {
            dfs(x,y,0);
        }
    }
}


int main ()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(adj,-1,sizeof(adj));
        adj[0][0]=1;
        cnt=2;
        num=n*n;
        dfs(0,0,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    printf("%d",adj[i][j]);
                else
                    printf(" %d",adj[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}//Parsed in 0.083 seconds
