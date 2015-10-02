#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;






int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if(a==0&&b==0&&c==0)
            break;
        int ans=1;
        while(b!=0)
        {
            if(b%2==1)
            {
                ans*=a;
                ans%=c;
            }
            b/=2;
            a*=a;
            a%=c;
        }
        printf("%d\n",ans);
    }
    return 0;
}//Parsed in 0.025 seconds
