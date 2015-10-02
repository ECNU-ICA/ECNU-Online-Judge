#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<stack>


using namespace std;


char mmap[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
stack<char> Q;


int main()
{
    int n,a,r;
    scanf("%d",&n);
    bool mark;
    while(n--)
    {
        while(!Q.empty()) Q.pop();
        scanf("%d %d",&a,&r);
        mark=false;
        if(a<0)
        {
            a=-a;
            mark=true;
        }
        while(a!=0)
        {
            Q.push(mmap[a%r]);
            a=a/r;
        }
        if(mark)
            printf("-");
        while(!Q.empty())
        {
            printf("%c",Q.top());
            Q.pop();
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.037 seconds
