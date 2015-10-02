#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


char mmap[35][35];
bool vis[35][35];
int go[][2]=
{
    0,-1,
    -1,0,
    0, 1,
    1, 0
};
int cnt;
int n,m;// m row  n col
void dfs(int x,int y)
{
    for(int i=0; i<4; i++)
    {
        int nx,ny;
        nx=x+go[i][0];
        ny=y+go[i][1];
        if(1<=nx&&nx<=m&&1<=ny&&ny<=n)
        {
            if(!vis[nx][ny]&&mmap[nx][ny]=='.')
            {
                vis[nx][ny]=true;
                cnt++;
                dfs(nx,ny);
            }
        }
    }
}
int main ()
{
    int x,y;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        for(int i=1; i<=m; i++)
        {
            scanf("%s",mmap[i]+1);
            for(int j=1; j<=n; j++)
            {
                if(mmap[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        vis[x][y]=true;
        cnt=1;
        dfs(x,y);
        printf("%d\n",cnt);
    }
    return 0;
}//Parsed in 0.061 seconds
