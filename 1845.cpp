#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


char str[210];


int main ()
{
    //freopen("in.txt","r",stdin);
    while(gets(str))
    {
        string s(str);
        while(s.find("<br>")!=s.npos)
        {
            s.replace(s.find("<br>"),4,"\n");
        }
        printf("%s\n",s.c_str());
    }
    return 0;
}//Parsed in 0.021 seconds
