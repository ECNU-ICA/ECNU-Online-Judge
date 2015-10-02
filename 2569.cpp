#include <cstdio>
#include <cstring>
#include <cmath>


int main()
{
    char str[5000];
    while( gets(str) )
    {
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            if('a'<=str[i]&&str[i]<='z')
                str[i]=str[i]-('a'-'A');
        }
        printf("%s\n",str);
    }
    return 0;
}//Parsed in 0.035 seconds
