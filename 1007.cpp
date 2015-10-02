#include <cstdio>
#include <cstring>//c
#include <string>//C++
#include <cmath>
#include <cstdlib>


using namespace std;


double const PI =3.14159265358979;
double const E  =2.718281828459;
/*
log10(125)=2.0969100130080564143587833158265
ÕûÊý²¿·Ö¼Ó1£¬Îª125µÄÎ»Êý
ÕûÊý²¿·ÖÈ¥µô£¬10^0.0969100130080564143587833158265=1.2499999999999 ×î¸ßÎ»ÊÇ1
*/


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double sum=0;
        if(n<=100)
            for(int i=1;i<=n;i++)
            {
                sum+=log10(i);
            }
        else
        {
            sum+=log10(pow(2*PI*n,0.5))+n*log10(n/E);
        }


        sum=sum-floor(sum);


        printf("%d\n",(int)pow(10.0,sum));
    }
    return 0;
}//Parsed in 0.048 seconds
