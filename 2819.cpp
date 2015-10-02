#include<cstdio>
#include<cstring>
#include<cstdlib>


using namespace std;


int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int sum=n;
        while(n-3>=0)
        {
            sum++;
            n=n-2;
        }
        printf("%d\n",sum);
    }
    return 0;
}//Parsed in 0.017 seconds
