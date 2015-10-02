#include <cstdio>
#include <cstring>//c
#include <string>//C++
#include <cmath>
#include <cstdlib>


using namespace std;
int const MAXN = 100005;
struct Queue
{
    char name[20];
}q[MAXN];


int main()
{
    int f,r;
    int n;
    scanf("%d",&n);
    char in[20];
    f=r=0;
    while(n--)
    {
        scanf("%s",in);
        if(strcmp(in,"enqueue")==0)
        {
            scanf("%s",in);
            r=(r+1)%MAXN;
            strcpy(q[r].name,in);
        }
        else
        {
            if(f==r)
                printf("-1\n");
            else
            {
                f=(f+1)%MAXN;
                printf("%s\n",q[f].name);
            }
        }
    }
    return 0;
}//Parsed in 0.066 seconds
