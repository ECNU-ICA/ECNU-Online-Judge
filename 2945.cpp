#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


struct Node
{
    char url[110];
    int con;
}s[25];


int main ()
{
    //freopen("out.txt","w",stdout);
    int cas,maxn;
    while(scanf("%d",&cas)!=EOF)
    {
        maxn=-1;
        for(int i=0;i<cas;i++)
        {
            scanf("%s %d",s[i].url,&s[i].con);
            if(maxn<s[i].con)
                maxn=s[i].con;
        }
        for(int i=0;i<cas;i++)
        {
            if(maxn==s[i].con)
                printf("%s\n",s[i].url);
        }
    }
    return 0;
}//Parsed in 0.056 seconds
