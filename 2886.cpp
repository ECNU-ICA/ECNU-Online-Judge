#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


double getRat(double x)
{
    double ret=0;
    if(x<=1500)
        ret=0;
    else if(1500<x&&x<=3000)
        ret=0.05;
    else if(3000<x&&x<=5000)
        ret=0.1;
    else if(5000<x&&x<=10000)
        ret=0.15;
    else
        ret=0.2;
    return ret;
}


int main ()
{
    double salary;
    while(scanf("%lf",&salary)!=EOF)
    {
        printf("%.2lf\n",getRat(salary)==0?0:((salary-1500)*getRat(salary)));
    }
    return 0;
}//Parsed in 0.055 seconds
