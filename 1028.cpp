#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;


const int MAXM=INT_MAX;
int ans[110][110];
struct Rot
{
    char ip[50];
} r[110];
int top;
int f(char *ip)
{
    for(int i=1;i<top;i++)
    {
        if(strcmp(r[i].ip,ip)==0)
            return i;
    }
    return -1;
}
int main ()
{
    int n , m;
    char sour[50];
    char dis[50];
    while (scanf ("%d %d",&n,&m) != EOF)
    {
        top=1;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                ans[i][j] = MAXM;
            }
            ans[i][i] = 0;
        }
        while(m --)
        {
            int c;
            scanf ("%s %s %d",sour,dis,&c);
            int a=f(sour);
            if(a==-1)
            {
                a=top;
                strcpy(r[top++].ip,sour);
            }
            int b=f(dis);
            if(b==-1)
            {
                b=top;
                strcpy(r[top++].ip,dis);
            }
            ans[a][b] = ans[b][a] = c;
        }
        for (int k = 1; k <= n; k ++)
        {
            for (int i = 1; i <= n; i ++)
            {
                for (int j = 1; j <= n; j ++)
                {
                    if (ans[i][k] == MAXM || ans[k][j] == MAXM) continue;
                    if (ans[i][k] + ans[k][j] < ans[i][j])
                    {
                        ans[i][j] = ans[i][k] + ans[k][j];
                    }
                }
            }
        }
        scanf("%d",&m);
        while(m --)
        {


            scanf ("%s %s",sour,dis);
            int a=f(sour);
            int b=f(dis);
            if(a==-1||b==-1||ans[a][b]==MAXM)
                printf("-1\n");
            else
                printf("%d\n",ans[a][b]);
        }
    }
    return 0;
}//Parsed in 0.099 seconds
