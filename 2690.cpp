#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>




int main()
{
    int e,f,c;
    while(scanf("%d %d %d",&e,&f,&c)!=EOF)
    {
        int num=0;
        e=e+f;
        while(true)
        {
            if(e>=c)
            {
                num+=e/c;
                e=e/c+e%c;
            }
            else
                break;


        }
        printf("%d\n",num);
    }
    return 0;
}//Parsed in 0.040 seconds
