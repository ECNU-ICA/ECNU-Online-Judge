#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>




using namespace std;


char adj[1005][1005];
char tmp[1005];


int main()
{
    int T,n,m;
    scanf("%d",&T);
    int k=0;
    while(T--)
    {
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
        {
            scanf("%s",adj[i]);
        }
        int count_=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]=='.')
                    count_++;
            }
        }
        printf("case #%d:\n%d\n",k++,count_);
    }
    return 0;
}//Parsed in 0.060 seconds
