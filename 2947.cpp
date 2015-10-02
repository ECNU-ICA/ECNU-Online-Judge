#include<cstdio>
#include<cstring>
#include<cstdlib>


using namespace std;


struct Data
{
    int num[55];
}s[1010];
int top;
int cmp( const void *a , const void *b )
{
	struct Data *c = (Data *)a;
	struct Data *d = (Data *)b;
	for(int i=0;i<top-1;i++)
    {
        if( c->num[i] != d->num[i] )
            return d->num[i] - c->num[i];
    }
	return d->num[top-1] - c->num[top-1];
}
int main()
{
    int t,n,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        top=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<55;j++)
                s[i].num[j]=0;
            int index=0;
            while(scanf("%d",&tmp)!=EOF)
            {
                //printf("-->%d\n",tmp);
                if(tmp==-1)
                    break;
                s[i].num[index++]=tmp;
            }
            if(top<index)
                top=index;
        }
        qsort(s,n,sizeof(s[0]),cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<top;j++)
            {
                if(s[i].num[j]==0)
                    break;
                if(j==0)
                    printf("%d",s[i].num[j]);
                else
                    printf(" %d",s[i].num[j]);
            }
            printf("\n");
        }
    }
    return 0;
}//Parsed in 0.076 seconds
