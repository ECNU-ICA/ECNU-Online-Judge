#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int s[1000010];
int cmp ( const void *a , const void *b )
{
	return *(int *)a - *(int *)b;
}




int main()
{
    //freopen("in.txt","r",stdin);
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("%d",s[0]);
        k--;int j=1;
        while(k)
        {
            //if(s[j]!=s[j-1])
            //{
                printf(" %d",s[j]);
                k--;
            //}
            j++;
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.036 seconds
