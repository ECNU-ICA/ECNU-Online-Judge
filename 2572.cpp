#include <cstdio>
#include <cstring>
#include <cmath>




int main()
{
    int N,K,t;
    int arr[100010];
    memset(arr,0,sizeof(arr));
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&t);
        arr[t]++;
    }
    int arr2[100010];
    int index=1;
    for(int j=0; j<100010; j++)
    {
        if(arr[j]!=0)
        {
            for(int k=0; k<arr[j]; k++)
            {
                arr2[index++]=j;
            }
        }
    }
    scanf("%d",&K);
    while(K--)
    {
        scanf("%d",&t);
        printf("%d\n",arr2[t]);
    }
    return 0;
}//Parsed in 0.033 seconds
