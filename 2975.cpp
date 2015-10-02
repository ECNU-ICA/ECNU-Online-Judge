#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>


using namespace std;
struct op
{
    bool operator()(const int&a,const int&b)
    {
        int ga=a%10;
        int gb=b%10;
        if(ga!=gb)
            return ga<gb;
        return a<b;
    }
};
set<int,op> s;


int main()
{
    int cas=0;
    int N,n,t;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        s.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%d",&t);
            s.insert(t);
        }
        printf("case #%d:\n",cas++);
        bool isfirst=true;


        set<int>::iterator iter;
        for(iter=s.begin(); iter!=s.end(); iter++)
        {
            if(isfirst)
            {
                printf("%d",*iter);
                isfirst=false;
            }
            else
                printf(" %d",*iter);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.095 seconds
