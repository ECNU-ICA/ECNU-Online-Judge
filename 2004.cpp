#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>


using namespace std;


int main()
{
    bool flag=false;
    for(int i=1000;i<=9999;++i)
    {
        int a,b,c,d;
        a=i/1000;
        b=(i-a*1000)/100;
        c=(i-a*1000-b*100)/10;
        d=i%10;
        if(i==(pow(a,4)+pow(b,4)+pow(c,4)+pow(d,4)))
        {
            printf("%d\n",i);
            flag=true;
        }
    }
    if(!flag)
        printf("no answer\n");
    return 0;
}//Parsed in 0.025 seconds
