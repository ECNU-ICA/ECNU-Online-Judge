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


char mmap[1000+10][80+10];
bool mark[1000+10][80+10];
int gox[]= {-1,-1,0,1,1, 1, 0,-1};
int goy[]= { 0, 1,1,1,0,-1,-1,-1};
int w,h;


void dfs(int x,int y)
{
    int nx,ny;
    for(int i=0; i<8; i++)
    {
        nx=x+gox[i];
        ny=y+goy[i];
        if(nx>=0&&nx<h&&ny>=0&&ny<w&&mark[nx][ny]==false&&mmap[nx][ny]=='*')
        {
            mark[nx][ny]=true;
            dfs(nx,ny);
        }
    }
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&w,&h)!=EOF)
    {
        for(int i=0; i<h; i++)
        {
            scanf("%s",mmap[i]);
        }
        memset(mark,false,sizeof(mark));
        int con=0;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(mmap[i][j]=='*'&&mark[i][j]==false)
                {
                    dfs(i,j);
                    con++;
                }
            }
        }
        printf("%d\n",con);
    }
    return 0 ;
}//Parsed in 0.109 seconds
