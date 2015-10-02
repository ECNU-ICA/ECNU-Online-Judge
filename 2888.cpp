#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int main ()
{
    int k,m;
    double sal;
    while(scanf("%lf %d %d",&sal,&k,&m)!=EOF)
    {
        int year=1;
        double room=270;
        double sum=sal;
        for(;year<=30;year++)
        {
            if(sum>=room)
                break;
            room=room*(1+k/100.0);
            sal =sal *(1+m/100.0);
            sum+=sal;
        }
        if(year>30)
            printf("Impossible\n");
        else
            printf("%d\n",year);
    }
    return 0;
}//Parsed in 0.056 seconds
