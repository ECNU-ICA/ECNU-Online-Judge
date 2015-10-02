#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;


//¶þÎ¬Êý×é,Æä³õÊ¼Öµ¼´Îª¸ÃÍ¼µÄÁÚ½Ó¾ØÕó
int ans[201][201];
int main ()
{
    int n , m;
    while (scanf ("%d %d",&n,&m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                ans[i][j] = -1;
            }
            ans[i][i] = 0;
        }
        while(m --)
        {
            int a , b , c;
            scanf ("%d %d %d",&a,&b,&c);
            ans[a][b] = c;
        }
        for (int k = 1; k <= n; k ++)
        {
            for (int i = 1; i <= n; i ++)
            {
                for (int j = 1; j <= n; j ++)
                {
                    if (ans[i][k] == -1 || ans[k][j] == -1) continue;
                    if (ans[i][k] + ans[k][j] > ans[i][j])
                    {
                        ans[i][j] = ans[i][k] + ans[k][j];
                    }
                }
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            int a , b;
            scanf ("%d %d",&a,&b);
            printf("%d\n",ans[a][b]);
        }
    }
    return 0;
}//Parsed in 0.072 seconds
