#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<set>
#include<vector>


using namespace std;


int year[40];
int cmp ( const void *a , const void *b )
{
	return *(int *)a - *(int *)b;
}


int main ()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&year[i]);
        qsort(year,n,sizeof(year[0]),cmp);
        for(int i=0;i<n;i++)
            printf("%d\n",year[i]);
    }
    return 0;
}

//Parsed in 0.048 seconds
