#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<stack>


using namespace std;


int main()
{
    int n,t;
    bool isfull;
    while(scanf("%d",&n)!=EOF)
    {
        int istrue[31];
        memset(istrue,-1,sizeof(istrue));
        isfull=true;
        for(int i=0; i<n; i++)
        {
            while(scanf("%d",&t)!=EOF)
            {
                if(t==-1)
                    break;
                istrue[t]=1;
            }
        }
        for(int i=1; i<=30; i++)
        {
            if(istrue[i]==-1)
            {
                isfull=false;
                break;
            }
        }
        if(isfull)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}//Parsed in 0.074 seconds
