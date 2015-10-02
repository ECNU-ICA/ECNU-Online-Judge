#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>


using namespace std;


int main()
{
    unsigned int num;
    while(scanf("%u",&num)!=EOF)
    {
        unsigned short high16,low16;
        high16=(unsigned short)(num&0xFFFF);
        low16=(unsigned short)(num>>16);


        low16=~low16;


        high16=high16^low16;


        unsigned int value=0;


        value=value|(high16<<16);
        value=value|low16;


        printf("%X\n",value);
    }
    return 0;
}//Parsed in 0.041 seconds
