#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<set>
#include<vector>


using namespace std;


int main ()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
            break;
        int h=n/3600;
        n%=3600;
        int m=n/60;
        n%=60;
        int s=n;
        printf("%02d:%02d:%02d\n",h,m,s);
    }
    return 0;
}

//Parsed in 0.020 seconds
