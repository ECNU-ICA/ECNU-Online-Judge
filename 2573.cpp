#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>


struct Mmap
{
    int a,b;
    int cost;
}mmap[15005];


int cmp( const void *a ,const void *b)
{
	return (*(Mmap *)a).cost > (*(Mmap *)b).cost ? 1 : -1;
}
int const MAX=1005;


int father[MAX];


/* 初始化集合*/
void Make_Set(int x)
{
    father[x] = x;
}


/* 查找x元素所在的集合,回溯时压缩路径*/
int Find_Set(int x)
{
    if (x != father[x])
    {
        father[x] = Find_Set(father[x]); //这个回溯时的压缩路径是精华
    }
    return father[x];
}


/* 并集 */
int Union(int x, int y)
{
    x = Find_Set(x);
    y = Find_Set(y);
    if (x == y)
        return 0;
    father[x] = y;
        return 1;
}


int main()
{
    int N,M;
    int a,b,c,i,msum;
    while(scanf("%d %d",&N,&M)!=EOF)
    {
        i=0;
        msum=0;
        int t=M;
        while(M--)
        {
            scanf("%d %d %d",&a,&b,&c);
            mmap[i].a = a;
            mmap[i].b = b;
            mmap[i++].cost = c;
        }
        qsort(mmap,t,sizeof(mmap[0]),cmp);
        for(i=1;i<MAX;i++)
        {
            Make_Set(i);
        }
        for(i=0;i<t;i++)
        {
            if(Union(mmap[i].a,mmap[i].b))
            {
                msum+=mmap[i].cost;
            }
        }
        printf("%d\n",msum);
    }
    return 0;
}//Parsed in 0.083 seconds
