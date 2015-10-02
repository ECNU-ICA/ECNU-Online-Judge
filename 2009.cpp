#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>


using namespace std;


int arr[100005];


int main()
{
    memset(arr,0,sizeof(arr));
    int n,q,t;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        arr[t]=1;
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&t);
        if(arr[t])
        {
            printf("yes!\n");
        }
        else
        {
            printf("no!\n");
        }
    }


    return 0;
}//Parsed in 0.050 seconds
