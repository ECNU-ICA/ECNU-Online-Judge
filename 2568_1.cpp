#include <cstdio>
#include <cstring>
#include <cmath>


int main()
{
    int n;
    int sum;
    int a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a,&b);
        sum=a+b;
        int i=1;
        while(sum)
        {
            sum=sum/10;
            if(sum!=0)
                i++;
        }
        printf("%d\n",i);
    }
    return 0;
}//Parsed in 0.035 seconds
