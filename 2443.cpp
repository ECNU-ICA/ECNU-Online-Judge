#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int getSum(int x)
{
    int ret=0;
    while(x!=0)
    {
        ret+=x%10;
        x/=10;
    }
    return ret;
}


int main ()
{
    int n,num;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&num);
        int res=getSum(num);
        while(res!=num)
        {
            num=res;
            res=getSum(num);
        }
        printf("%d\n",res);
    }
    return 0;
}//Parsed in 0.046 seconds
