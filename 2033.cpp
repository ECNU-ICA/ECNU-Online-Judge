#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>


using namespace std;


char str[10005];


int main()
{
    while(gets(str))
    {
        int len=strlen(str);
        for(int i=len-1;i>=0;--i)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.017 seconds
