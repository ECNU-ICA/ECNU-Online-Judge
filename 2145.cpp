#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<set>
#include<vector>


using namespace std;


int f[260];


int main ()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","r",stdout);
    f[0]=0;
    for(int i=1;i<256;i++)
    {
        f[i]=i*2*2+(i*2-2)*2;
    }
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=f[i]*(n-i+1);
        }
        printf("%d\n",sum);
    }
    return 0;
}//Parsed in 0.025 seconds
