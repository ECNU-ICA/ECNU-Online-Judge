#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int const maxSize=20010;
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
        for (int j=i*i; j<=maxSize; j+=i)
        {
            isPrime[j]=false;
        }
    }
}
int cnt[maxSize];


int main ()
{
    //freopen("out.txt","w",stdout);
    init();
    int cas,a;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&a);
        memset(cnt,0,sizeof(cnt));
        for (int i = 0; i < primeSize; i ++)
        {
            //对a分解素因数
            while (a % prime[i] == 0)
            {
                cnt[i] ++;
                a /= prime[i];
            }//计算a中素因数prime[i]对应的幂指数
        }
        for (int i = 0; i < primeSize; i ++)
        {
                if(cnt[i]!=0)
                    printf("(%d,%d)",prime[i],cnt[i]);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.119 seconds
