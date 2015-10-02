#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


char str[100010];
char pat[100010];


int main ()
{
    while(scanf("%s %s",str,pat)!=EOF)
    {
        int len1=strlen(str);
        int len2=strlen(pat);
        int index=0;
        for(int i=0;i<len2;i++)
        {
            if(pat[i]==str[index])
            {
                index++;
            }
        }
        if(index==len1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}//Parsed in 0.051 seconds
