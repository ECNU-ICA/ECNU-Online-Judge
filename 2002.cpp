#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>


using namespace std;


int main()
{
    __int64 a,b;
    while(scanf("%I64d %I64d",&a,&b)!=EOF)
    {
        printf("%.3f\n",sqrt(a*a*1.0+b*b));
    }
    return 0;
}//Parsed in 0.022 seconds
