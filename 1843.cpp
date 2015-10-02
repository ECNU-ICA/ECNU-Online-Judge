#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int go[][2]={2,1,1,2};
int w,h;//  (h,w)
int cnt;
void dfs(int x,int y)
{
    for(int i=0;i<2;i++)
    {
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(nx==h&&ny==w)
            cnt++;
        else if(nx<h&&ny<w)
        {
            dfs(nx,ny);
        }
    }
}


int main ()
{
    //freopen("in.txt","r",stdin);
    int cas,con=1;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d",&h,&w);
        cnt=0;
        dfs(1,1);
        printf("Chessboard #%d:%d\n",con++,cnt);
    }
    return 0;
}//Parsed in 0.043 seconds
