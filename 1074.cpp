#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <set>


using namespace std;


int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    double res;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        res=n*log10(n);
        res=res-floor(res);
        printf("%d\n",(int)pow(10,res));
    }
    return 0;
}//Parsed in 0.035 seconds
