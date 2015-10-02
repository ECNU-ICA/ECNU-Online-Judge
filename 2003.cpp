#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>


using namespace std;


int main()
{
    double x,y;
    while(scanf("%lf %lf",&x,&y)!=EOF)
    {
        printf("%.3lf\n",pow(x,y));
    }
    return 0;
}//Parsed in 0.013 seconds
