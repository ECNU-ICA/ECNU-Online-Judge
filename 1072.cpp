#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>




using namespace std;


struct In {
   char str[35];
}s[10005];




int cmp ( const void *a , const void *b )
{
	return strcmp( (*(In *)a).str , (*(In *)b).str );
}




int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i].str);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            if(strcmp(s[i-1].str,s[i].str)==0)
                continue;
            else
                printf("%s\n",s[i].str);
        }
        else
            printf("%s\n",s[i].str);
    }
    return 0;
}//Parsed in 0.070 seconds
