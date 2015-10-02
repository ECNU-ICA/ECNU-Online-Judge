#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


int mpow(int x,int y)
{
    int ret=1;
    while(y--)
    {
        ret=ret*x;
    }
    return ret;
}


int main()
{
    int t,c,w;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d %d",&c,&w);
        int star=mpow(10,c-2);
        int end_=mpow(10,c-1);
        //printf("[%d,%d]\n",star,end_-1);
        int cnt=0;
        for(int i=star;i<end_;i++)
        {
            if((i*10+w)%3==0)
            {
                cnt++;
            }
        }
        printf("case #%d:\n",cas++);
        printf("%d\n",cnt);
    }
    return 0;
}//Parsed in 0.034 seconds
