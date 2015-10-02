#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>


using namespace std;


int go[][2]=
{
    -1,-2,
    1 ,-2 ,
    -2,-1,
    2 ,-1,
    -2, 1,
    2 , 1,
    -1, 2,
    1 , 2
};
bool vis[30][30];
int path[30][2];//记录坐标
int sum;
int p,q;
bool isput;
void dfs(int x,int y,int step)
{//  1~p   1~q
    if(isput)
        return;
    if(step>=sum)
    {
        for(int i=1;i<=sum;i++)
        {
            printf("%c%d",path[i][1]+'A'-1,path[i][0]);
        }
        printf("\n");
        isput=true;
        return;
    }
    for(int i=0;i<8;i++)
    {
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(1<=nx&&nx<=p&&1<=ny&&ny<=q&&!vis[nx][ny])
        {
            vis[nx][ny]=true;
            path[step+1][0]=nx;
            path[step+1][1]=ny;
            dfs(nx,ny,step+1);
            vis[nx][ny]=false;
        }
    }
}
int main ()
{
    int cas;
    scanf("%d",&cas);
    int cnt=1;
    while(cas--)
    {
        scanf("%d %d",&p,&q);
        memset(vis,false,sizeof(vis));
        sum=q*p;
        vis[1][1]=true;
        path[1][0]=1;
        path[1][1]=1;
        isput=false;
        printf("Scenario #%d:\n",cnt++);
        dfs(1,1,1);
        if(!isput)
        {
            printf("impossible\n");
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.137 seconds
