#include<cstdio>
#include<cstring>
#include<cstdlib>


using namespace std;


int num[1010];


int main()
{
    char cmd;
    scanf("%c",&cmd);
    memset(num,0,sizeof(num));
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        num[n]++;
    }
    bool isFirst=true;
    if(cmd=='A')
    {
        for(int i=0; i<1010; i++)
        {
            if(num[i]!=0&&isFirst)
            {
                printf("%d",i);
                isFirst=false;
            }
            else if(num[i]!=0)
            {
                printf(" %d",i);
            }
        }
    }
    else
    {
        for(int i=1009; i>=0; i--)
        {
            if(num[i]!=0&&isFirst)
            {
                printf("%d",i);
                isFirst=false;
            }
            else if(num[i]!=0)
            {
                printf(" %d",i);
            }
        }
    }
    return 0;
}//Parsed in 0.093 seconds
