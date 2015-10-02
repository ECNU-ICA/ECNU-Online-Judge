#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>


int main()
{
    int N;
    scanf("%d",&N);
    getchar();
    char str[10005];
    while(N--)
    {
        gets(str);
        int len=strlen(str);
        int zimu=0,shuzi=0,qita=0;
        for(int i=0;i<len;i++)
        {
            if(('a'<=str[i]&&str[i]<='z')||('A'<=str[i]&&str[i]<='Z'))
                zimu++;
            else if('0'<=str[i]&&str[i]<='9')
                shuzi++;
            else
                qita++;
        }
        printf("character:%d\nnumber:%d\nothers:%d\n",zimu,shuzi,qita);
    }
    return 0;
}//Parsed in 0.036 seconds
