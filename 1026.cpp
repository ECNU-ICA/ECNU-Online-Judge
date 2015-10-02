#include <cstdio>
#include <cmath>


int main()
{
    int n;
    float h;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        n--;
        if(n<=2)
            h=n*5;
        else
        {
            h=10+3*(n-2);
        }
        h+=1.75;
        printf("%.3f\n",sqrt(2*h/9.8));
    }
    return 0;
}//Parsed in 0.026 seconds
