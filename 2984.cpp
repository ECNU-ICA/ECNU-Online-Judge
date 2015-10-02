#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


struct Node
{
    int m;
    int w;
    int c;
}buf[1000010];
int cmp( const void *a , const void *b )
{
	struct Node *c = (Node *)a;
	struct Node *d = (Node *)b;
	return (10000*c->m + 100*c->w + c->c) - (10000*d->m + 100*d->w + d->c);
}
int main ()
{
    //freopen("in.txt","r",stdin);
    int cas,cnt=0;
    scanf("%d",&cas);
    int n,k,top;
    while(cas--)
    {
        scanf("%d %d",&n,&k);
        top=0;
        for(int m=0;;m++)
        {
            int w=k-n-2*m;
            if(w<0)
                break;
            int c=n-w-m;
            if(m>=0&&w>=0&&c>=0)
            {
                buf[top].m=m;
                buf[top].w=w;
                buf[top++].c=c;
            }
        }
        qsort(buf,top,sizeof(buf[0]),cmp);
        printf("case #%d:\n",cnt++);
        for(int i=0;i<top;i++)
        {
            printf("%d %d %d\n",buf[i].m,buf[i].w,buf[i].c);
        }
        if(top==0)
            printf("-1\n");
    }
    return 0;
}//Parsed in 0.062 seconds
