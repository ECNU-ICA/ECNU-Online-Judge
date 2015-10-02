#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;


struct Stu
{
    int h;
    int no;
}s[55];
int cmp( const void *a ,const void *b)
{
	return (*(Stu *)b).h - (*(Stu *)a).h;
}


int main()
{
    //freopen("out.txt","w",stdout);
    int cas,n,m,t;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&s[i].h);
            s[i].no=i;
        }
        qsort(s+1,n,sizeof(s[0]),cmp);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&t);
            if(i==1)
                printf("%d",s[t].no);
            else
                printf(" %d",s[t].no);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.077 seconds
