#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>


using namespace std;


int const maxSize=10010;
int prime[maxSize];     //保存筛得的素数
int primeSize;          //保存的素数的个数
//若mark[x]为true,则表示该数x已被标记成非素数
bool isPrime[maxSize+1];
void init()//素数筛法
{
    //#include <cstring>
    //初始化，所有数字均没被标记
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    primeSize = 0; //得到的素数个数为0
    //依次遍历2到maxSize所有数字
    for (int i=2; i<= maxSize; i++)
    {
        //若该数字已经被标记,则跳过
        if(!isPrime[i]) continue;
        //否则,又新得到一个新素数
        prime[primeSize++]=i;
        //并将该数的所有倍数均标记成非素数
        for (int j=i*i; j<=maxSize &&j>=0; j+=i)
        {
            isPrime[j]=false;
        }
    }
}


int cnt[maxSize];
int cnt2[maxSize];


int main()
{
    init();
    int cas;
    int con=0;
    int a,b;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d",&a,&b);
        memset(cnt,0,sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        for (int i = 0; i < primeSize; i ++)
        {
            while (a % prime[i] == 0)
            {
                cnt[i] ++;
                a /= prime[i];
            }
        }
        for (int i = 0; i < primeSize; i ++)
        {
            while (b % prime[i] == 0)
            {
                cnt2[i] ++;
                b /= prime[i];
            }
        }
        bool flag=true;
        printf("case #%d:\n",con++);
        for (int i = 0; i < primeSize; i ++)
        {
            if(cnt[i]!=0&&cnt2[i]!=0)
            {
                printf("Yes %d\n",prime[i]);
                flag=false;
                break;
            }
        }
        if(flag)
            printf("No\n");
    }
    return 0;
}//Parsed in 0.090 seconds
