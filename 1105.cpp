#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <set>


using namespace std;


int num[1030];


int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(int i=0; i<=k; i++)
            scanf("%d",&num[i]);
        int c=0,t=n;
        for(int i=0; i<=k;)
        {
            if(num[i]<t)
            {
                t=t-num[i++];
            }
            else
            {
                c++;
                if(t==n)
                {
                    printf("No Solution!\n");
                    break;
                }
                t=n;
            }
        }
        if(t!=n)
            printf("%d\n",c);
    }
    return 0;
}//Parsed in 0.067 seconds
