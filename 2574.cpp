#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <cctype>


using namespace std;


char ex[110];
int index;
bool A();
bool B();
bool C();
bool A()
{
    if(ex[index]=='x')
    {
        index++;
        while(ex[index]==' ') index++;
        return true;
    }
    if(ex[index]=='(')
    {
        index++;
        while(ex[index]==' ') index++;
        if(B()&&ex[index]==')')
        {
            index++;
            while(ex[index]==' ') index++;
            return true;
        }
    }
    return false;
}
bool B()
{
    return A()&&C();
}
bool C()
{
    while(ex[index]=='+')
    {
        index++;
        while(ex[index]==' ') index++;
        //return A();
        if (!A())
            return false;
    }
    return true;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N;
    scanf("%d",&N);
    getchar();
    while(N--)
    {
        gets(ex);
        index=0;
        printf("%s\n",A()&&ex[index]=='\0'?"Good":"Bad");
    }
    return 0;
}//Parsed in 0.107 seconds
