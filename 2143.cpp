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
    int n,a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a,&b);
        int sum=0;
        while(a!=0)
        {
            if(a>=5*b)
            {
                sum+=7;
                a-=5*b;
            }
            else if(a>=3*b)
            {
                sum+=4;
                a-=3*b;
            }
            else
            {
                if(a>=b)
                {
                    sum++;
                    a-=b;
                }
                else
                    break;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}//Parsed in 0.069 seconds
