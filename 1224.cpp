#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>


using namespace std;


char mmap[205][205];
bool vis[205][205];
int n,m;
struct N
{
    int x;
    int y;
    int t;
    bool operator < (const N &b)const // Ö»ÄÜÖØÔØÐ¡ÓÚºÅ
    {
        return t>b.t;
    }


};
int go[][2]=
{
    0,-1,
    -1,0,
    0,1,
    1,0
};
priority_queue<N> Q;
int bfs()
{
    while(!Q.empty())
    {
        N now=Q.top();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=now.x+go[i][0];
            int ny=now.y+go[i][1];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&!vis[nx][ny]&&mmap[nx][ny]!='#')
            {
                //printf("---->%d %d\n",nx,ny);
                vis[nx][ny]=true;
                N tmp;
                tmp.x=nx;
                tmp.y=ny;
                if(mmap[nx][ny]=='X')
                    tmp.t=now.t+2;
                else if(mmap[nx][ny]=='T')
                    return now.t+1;
                else
                   tmp.t=now.t+1;
                Q.push(tmp);
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int x,y;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",mmap[i]+1);
            for(int j=1;j<=m;j++)
            {
                if(mmap[i][j]=='S')
                {
                    x=i;y=j;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        vis[x][y]=true;
        while(!Q.empty()) Q.pop();
        N tmp;
        tmp.x=x;
        tmp.y=y;
        tmp.t=0;
        Q.push(tmp);
        int ret=bfs();
        if(ret==-1)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d\n",ret);
        }
    }
    return 0;
}//Parsed in 0.132 seconds
