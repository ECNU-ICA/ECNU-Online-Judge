#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int const maxSize=1000010;
int *prime;     //保存筛得的素数
int primeSize;          //保存的素数的个数
//若mark[x]为true,则表示该数x已被标记成非素数
bool *isPrime;
void init()//素数筛法
{
    prime=(int*)malloc(maxSize*sizeof(int));
    isPrime=(bool*)malloc((maxSize+1)*sizeof(bool));
    //#include <cstring>
    //初始化，所有数字均没被标记
    memset(isPrime,true,(maxSize+1)*sizeof(bool));
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
        for(int j=i*i; j<=maxSize&&j>=0; j+=i)
        {
            isPrime[j]=false;
        }
    }
}
int lowerBound(int A[],int key,int len)
{
    int low=-1,high=len,mid;
    while(low+1!=high)
    {
        mid=low+(high-low)/2;
        if(A[mid]<key)
            low=mid;
        else
            high=mid;
    }
    int index=high;
    //以下根据需要进行修改，返回index
    //if(index>=len||A[index]!=key)
        //index= -1; //查找失败
    return index;
}


int main ()
{
    //freopen("in.txt","r",stdin);
    init();
    int cas;
    scanf("%d",&cas);
    int n;
    while(cas--)
    {
        scanf("%d",&n);
        int res=lowerBound(prime,n,primeSize);
        if(prime[res]==n)
            printf("%d\n",n);
        else
        {
            if(res-1>=0&&n-prime[res-1]<=prime[res]-n)
                printf("%d\n",prime[res-1]);
            else
                printf("%d\n",prime[res]);
        }
    }
    free(prime);
    free(isPrime);
    return 0;
}//Parsed in 0.133 seconds
