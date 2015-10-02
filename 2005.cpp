#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>


using namespace std;


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=2;i<=n/2;++i)
        {
            if(n%i==0)
            {
                printf("%d %d\n",i,n/i);
                break;
            }
        }
    }
    return 0;
}//Parsed in 0.032 seconds
