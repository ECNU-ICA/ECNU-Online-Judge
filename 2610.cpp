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
    int t,m,k,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&k);
        int sum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&tmp);
            if(i<k)
                sum+=tmp;
        }
        printf("%d\n",sum);
    }
    return 0;
}//Parsed in 0.041 seconds
