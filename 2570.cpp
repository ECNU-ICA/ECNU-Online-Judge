#include <cstdio>
#include <cstring>
#include <cmath>


int main()
{
    int prime[10010];
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=2;i<10010;i++)
    {
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                prime[i]=0;
                break;
            }
        }
    }
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int N,c=0;
        scanf("%d",&N);
        int a=1,b=N;
        for(int i=1;i<=N;i++)
        {
            if(prime[a]&&prime[b])
                c++;
            a++;
            b--;
        }
        printf("%d\n",c);
    }
    return 0;
}//Parsed in 0.066 seconds
