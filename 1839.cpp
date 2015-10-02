#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>


using namespace std;


char mmap[205][205];
bool vis[205][205];
struct N
{
    int x;
    int y;
    int t;
    vector<int> rx;
    vector<int> ry;
};
int n,m;
int go[][2]=
{
    0,-1,
    -1,0,
    0,1,
    1,0
};
queue<N> Q;
int bfs()
{
    while(!Q.empty())
    {
        N now;
        for(int i=0;i<4;i++)
        {
            now=Q.front();
            int nx=now.x+go[i][0];
            int ny=now.y+go[i][1];
            if(0<=nx&&nx<n&&0<=ny&&ny<m&&!vis[nx][ny]&&mmap[nx][ny]!='*')
            {
                vis[nx][ny]=true;
                now.x=nx;
                now.y=ny;
                now.t++;
                now.rx.push_back(nx);
                now.ry.push_back(ny);
                Q.push(now);
                if(mmap[nx][ny]=='E')
                {
                    printf("%d\n",now.t);
                    for(int i=0;i<now.rx.size();i++)
                    {
                        printf("%d %d\n",now.rx[i],now.ry[i]);
                    }
                    return 0;
                }
            }
        }
        Q.pop();
    }
    return -1;
}
int main()
{
    int x,y;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",mmap[i]);
            for(int j=0;j<m;j++)
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
        tmp.rx.clear();
        tmp.ry.clear();
        tmp.rx.push_back(x);
        tmp.ry.push_back(y);
        Q.push(tmp);
        int res=bfs();
        if(res==-1)
            printf("-1\n");
    }
    return 0;
}//Parsed in 0.173 seconds
