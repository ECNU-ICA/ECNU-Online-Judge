#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>




using namespace std;


int money[8]={0,100,50,20,10,5,2,1};
int res[8];


int main()
{
    int n,sum;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&sum);
        memset(res,0,sizeof(res));
        for(int i=1;i<8;i++)
        {
            res[i]+=sum/money[i];
            sum=sum%money[i];
        }
        for(int i=1;i<8;i++)
        {
            if(i!=1)
            {
                printf(" %d",res[i]);
            }
            else
                printf("%d",res[i]);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.047 seconds
