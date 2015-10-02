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
            //¶Ôa·Ö½âËØÒòÊý
            while (a % prime[i] == 0)
            {
                cnt[i] ++;
                a /= prime[i];
            }//¼ÆËãaÖÐËØÒòÊýprime[i]¶ÔÓ¦µÄÃÝÖ¸Êý
        }
        for (int i = 0; i < primeSize; i ++)
        {
                if(cnt[i]!=0)
                    printf("(%d,%d)",prime[i],cnt[i]);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.089 seconds
