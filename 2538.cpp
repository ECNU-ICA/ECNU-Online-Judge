#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>




using namespace std;
int res[4005];
int top;
void getYinZi(int n)
{
    top=0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
            res[top++]=i;
    }
}
int getYinZiSum()
{
    int sum=0;
    for(int i=0;i<top;i++)
        sum+=res[i];
    return sum;
}
void print()
{
    for(int i=0;i<top;i++)
        printf(" %d",res[i]);
}


int main()
{
    for(int i=1;i<=4000;i++)
    {
        getYinZi(i);
        //print();
        //system("pause");
        //printf("<- %d %d ->\n",i,getYinZiSum());
        if(i==getYinZiSum())
        {
            printf("%d its factors are",i);
            print();
            printf("\n");
        }
    }
    return 0;
}//Parsed in 0.066 seconds
