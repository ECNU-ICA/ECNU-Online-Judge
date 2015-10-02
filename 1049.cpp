#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <set>


using namespace std;


int num[100005];
int cmp ( const void *a , const void *b )
{
	return *(int *)a - *(int *)b;
}
int f(int x,int n)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num[mid]<x)
        {
            low=mid+1;
        }
        else if(num[mid]>x)
        {
            high=mid-1;
        }
        else
            break;
    }
    while(mid-1>=0)
    {
        if(num[mid-1]==x)
            mid--;
        else
            break;
    }
    if(num[mid]==x)
        return mid;
    else
        return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,t,con;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        qsort(num,n,sizeof(num[0]),cmp);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&t);
            int index=f(t,n);
            //printf("index--> %d \n",index);
            if(index==-1)
                printf("0\n");
            else
            {
                con=0;
                while(num[index]==t)
                {
                    con++;
                    index++;
                    if(index==n)
                        break;
                }
                printf("%d\n",con);
            }
        }
    }
    return 0;
}//Parsed in 0.113 seconds
