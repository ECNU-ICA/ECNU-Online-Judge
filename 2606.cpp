#include<cstdio>
#include<cstring>
#include<cstdlib>


using namespace std;


int main()
{
    int T,A,B,H;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&A,&B,&H);
        printf("%0.2lf\n",(1.0*B/A)*H);
    }
    return 0;
}//Parsed in 0.014 seconds
