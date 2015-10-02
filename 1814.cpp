#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


int main()
{
    int bitree[1025],n,r,i,a,b;
    memset(bitree,0,sizeof(bitree));
    scanf("%d %d",&n,&r);
    if(n%2 == 0)
    {
        printf("no\n");
        return 0;
    }
    bitree[r] = 1;
    for(i = 1; i <= n-1; i++)
    {
        scanf("%d %d",&a,&b);
        bitree[a]++;
        bitree[b]++;


    }
    for(i = 1; i <= n; i++)
    {
        if(bitree[i] != 3 && bitree[i] != 1)
        {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
}//Parsed in 0.058 seconds
