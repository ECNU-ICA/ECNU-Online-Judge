#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>


using namespace std;


int s[105];
int cmp ( const void *a , const void *b )
{
    return abs(*(int *)a) - abs(*(int *)b);
}




int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&s[i]);
        qsort(s,n,sizeof(s[0]),cmp);
        for(int i=0; i<n; i++)
        {
            if(i!=0)
            {
                printf(" %d",s[i]);
            }
            else
            {
                printf("%d",s[i]);;
            }
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.036 seconds
