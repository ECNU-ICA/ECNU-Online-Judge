#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <set>


using namespace std;


int num[10005];
int cmp ( const void *a , const void *b )
{
	return *(int *)a - *(int *)b;
}


int main()
{
    int N,n;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        qsort(num,n,sizeof(num[0]),cmp);
        long long sum=0;
        for(int i=n-1;i>0;i--)
        {
            sum+=i*num[n-i-1];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}//Parsed in 0.032 seconds
