#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<stack>


using namespace std;


int main()
{
    __int64 n;
    while(scanf("%I64d",&n)!=EOF)
    {
        double x=1;
        int i;
        for (i=1; i<=10000; i++)
        {
            x = (x + n/x)/2;
        }


        printf("%I64d\n",(__int64)ceil(x));
    }
    return 0;
}//Parsed in 0.037 seconds
