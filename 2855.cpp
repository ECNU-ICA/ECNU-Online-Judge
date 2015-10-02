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


int f[1010];
int h,w,t;
void init()
{
    f[0]=0;f[1]=1;
    for(int i=2;i<=1005;i++)
    {
        f[i]=(f[i-1]+f[i-2])%4;
    }
}
int gox[4]={-1,0,1,0};
int goy[4]={0,1,0,-1};
char mmap[110][110];
int dfs(int x,int y,int step)
{
    if(step==t+1)
        return 0;
    int res=0;
    if(mmap[x][y]!='.')
        res=mmap[x][y]-'0';
    //printf("t=%d -->   %d %d %d\n",step,x,y,res);
    int nx=gox[f[step]]+x;
    int ny=goy[f[step]]+y;
    int r=1;
    //printf("t=%d bef----> %d %d\n",step,nx,ny);
    while(nx<0||nx>=h||ny<0||ny>=w)
    {
        nx=gox[(f[step]+r)%4]+x;
        ny=goy[(f[step]+r)%4]+y;
        //printf("t=%d cag----> %d %d\n",step,nx,ny);
        r++;
    }
    return dfs(nx,ny,step+1)+res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    init();
    while(scanf("%d %d %d",&h,&w,&t)!=EOF)
    {
        for(int i=0;i<h;i++)
        {
            scanf("%s",mmap[i]);
        }
        printf("%d\n",dfs(0,0,0));
    }
    return 0 ;
}//Parsed in 0.056 seconds
