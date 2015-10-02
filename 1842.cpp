#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int const maxSize=1000010;
int *prime;     //±£´æÉ¸µÃµÄËØÊý
int primeSize;          //±£´æµÄËØÊýµÄ¸öÊý
//Èômark[x]Îªtrue,Ôò±íÊ¾¸ÃÊýxÒÑ±»±ê¼Ç³É·ÇËØÊý
bool *isPrime;
void init()//ËØÊýÉ¸·¨
{
    prime=(int*)malloc(maxSize*sizeof(int));
    isPrime=(bool*)malloc((maxSize+1)*sizeof(bool));
    //#include <cstring>
    //³õÊ¼»¯£¬ËùÓÐÊý×Ö¾ùÃ»±»±ê¼Ç
    memset(isPrime,true,(maxSize+1)*sizeof(bool));
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
    //ÒÔÏÂ¸ù¾ÝÐèÒª½øÐÐÐÞ¸Ä£¬·µ»Øindex
    //if(index>=len||A[index]!=key)
        //index= -1; //²éÕÒÊ§°Ü
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
}//Parsed in 0.124 seconds
