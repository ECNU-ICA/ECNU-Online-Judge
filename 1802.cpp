#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<stack>


using namespace std;


stack<char> S;
char str[10];
int top;
void push(int x)
{
    for(int i=top; i<=x; i++)
    {
        S.push(i+'0');
    }
    top=x+1;
}


int main()
{
    //freopen("in.txt","r",stdin);
    int k,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %s",&k,str+1);
        while(!S.empty()) S.pop();
        top=1;
        push(str[1]-'0');
        bool mark=true;
        for(int i=1; i<=k; i++)
        {
            if(S.empty())
            {
                push(str[i]-'0');
                i--;
                continue;
            }
            if(S.top()==str[i])
            {
                S.pop();
            }
            else if( S.top()<str[i] )
            {
                push(str[i]-'0');
                i--;
            }
            else
            {
                mark=false;
                break;
            }
        }
        if(mark)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}//Parsed in 0.105 seconds
