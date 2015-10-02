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


int main()
{
    init();
    int n;
    int maxn,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        maxn=-1;
        for(int i=0; i<n; i++)
        {
            if(n-prime[i]<0)
                break;
            if(isPrime[n-prime[i]])
            {
                if( maxn<prime[i]*(n-prime[i]) )
                {
                    maxn=prime[i]*(n-prime[i]);
                    x=prime[i];
                    y=n-prime[i];
                }
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}//Parsed in 0.112 seconds
