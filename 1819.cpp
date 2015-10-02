#include <stdio.h>
#include <algorithm>
int a[4200000];
bool visit[4200000];
int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int i,j,n,t,k;
    char c;
    scanf("%d %d",&n,&k);
    getchar();
    for(i = j = 0; j < n; j++)
    {
        t = 0;
        while ('0' <= (c = getchar()) && c <= '9')
            t = t * 10 + (c - '0');
        if(visit[t]) continue;
        visit[t] = 1;
        a[i++] = t;
    }
    qsort(a,i,sizeof(int),cmp);
    for(j = 0; j < k; j++)
        printf("%d: %d\n",j+1,a[j]);
}//Parsed in 0.034 seconds
