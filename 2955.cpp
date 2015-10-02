#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>


using namespace std;


int const maxSize=10010;
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
}//Parsed in 0.112 seconds
