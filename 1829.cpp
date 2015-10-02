#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


struct team
{
    int score;
    int win_cnt;
    int fail_cnt;
    int no;
}t[15];
int cmp( const void *a , const void *b )
{
	struct team *c = (team *)a;
	struct team *d = (team *)b;
	if(c->score != d->score) return d->score - c->score;
	else if(c->win_cnt != d->win_cnt) return d->win_cnt - c->win_cnt;
	else if(c->fail_cnt != d->fail_cnt) return c->fail_cnt - d->fail_cnt;
	else return c->no - d->no;
}


int main ()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    int a,b,c;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        for(int i=1;i<=n;i++)
        {
            t[i].fail_cnt=0;
            t[i].no=i;
            t[i].score=0;
            t[i].win_cnt=0;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                t[a].score+=3;
                t[a].win_cnt++;
                t[b].score-=1;
                t[b].fail_cnt++;
            }
            else if(c==-1)
            {
                t[b].score+=3;
                t[b].win_cnt++;
                t[a].score-=1;
                t[a].fail_cnt++;
            }
            else
            {
                t[a].score+=1;
                t[b].score+=1;
            }
        }
        qsort(t+1,n,sizeof(t[0]),cmp);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",t[i].no);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.086 seconds
