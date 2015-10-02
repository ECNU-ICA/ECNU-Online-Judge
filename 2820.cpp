#include<cstdio>
#include<cstring>
#include<cstdlib>


using namespace std;


char str[55];


int main()
{
    while(gets(str))
    {
        int n=1;
        int maxn=-1;
        int len=strlen(str);
        if(len==0)
        {
            printf("0\n");
            continue;
        }
        for(int i=1; i<len; i++)
        {
            if(str[i]!=str[i-1])
            {
                n++;
            }
            else
            {
                if(maxn<n)
                    maxn=n;
                n=1;
            }
        }
        if(maxn<n)
            maxn=n;
        printf("%d\n",maxn);
    }
    return 0;
}//Parsed in 0.036 seconds
