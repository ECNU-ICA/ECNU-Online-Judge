#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<queue>


using namespace std;


priority_queue<int, vector<int>, greater<int> > Q;


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(!Q.empty()) Q.pop();
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            Q.push(t);
        }
        int sum=0,tmp;
        while(Q.size()>=2)
        {
            int x=Q.top();Q.pop();
            int y=Q.top();Q.pop();
            tmp=x+y;
            sum+=tmp;
            Q.push(tmp);
        }
        printf("%d\n",sum);
    }
    return 0;
}//Parsed in 0.058 seconds
