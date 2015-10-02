#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int s[110];


int main()
{
    int n;
    double avg,dev;
    while(scanf("%d",&n)!=EOF)
    {
        avg=0;
        dev=0;
        for(int i=0;i<n;i++)
        {
            scanf("%*s %d",&s[i]);
            avg+=s[i];
        }
        avg=1.0*avg/n;
        for(int i=0;i<n;i++)
        {
            dev+=pow(s[i]-avg,2);
        }
        dev=dev/(n-1);
        dev=sqrt(dev);
        printf("%.2lf %.2lf\n",avg,dev);
    }
    return 0;
}//Parsed in 0.053 seconds
