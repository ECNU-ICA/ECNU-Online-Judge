#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <set>


using namespace std;


int num[105];


int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=0; i<N; i++)
            scanf("%d",&num[i]);
        int maxm=INT_MIN,j,t;
        for(j=0,t=0; j<N; j++)
        {
            t+=num[j];
            if(t>maxm)
            {
                maxm=t;
            }
            if(t<0)
            {
                t=0;
            }
        }
        printf("%d\n",maxm);
    }
    return 0;
}//Parsed in 0.038 seconds
