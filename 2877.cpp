#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int const maxSize=20010;
int prime[maxSize];     //±£´æÉ¸µÃµÄËØÊý
int primeSize;          //±£´æµÄËØÊýµÄ¸öÊý
//Èômark[x]Îªtrue,Ôò±íÊ¾¸ÃÊýxÒÑ±»±ê¼Ç³É·ÇËØÊý
bool isPrime[maxSize+1];
void init()//ËØÊýÉ¸·¨
{
    //#include <cstring>
    //³õÊ¼»¯£¬ËùÓÐÊý×Ö¾ùÃ»±»±ê¼Ç
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    primeSize = 0; //µÃµ½µÄËØÊý¸öÊýÎª0
    //ÒÀ´Î±éÀú2µ½maxSizeËùÓÐÊý×Ö
    for (int i=2; i<= maxSize; i++)
    {
        //Èô¸ÃÊý×ÖÒÑ¾­±»±ê¼Ç,ÔòÌø¹ý
        if(!isPrime[i]) continue;
        //·ñÔò,ÓÖÐÂµÃµ½Ò»¸öÐÂËØÊý
        prime[primeSize++]=i;
        //²¢½«¸ÃÊýµÄËùÓÐ±¶Êý¾ù±ê¼Ç³É·ÇËØÊý
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
}//Parsed in 0.062 seconds
