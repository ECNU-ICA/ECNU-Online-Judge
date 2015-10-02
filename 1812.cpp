#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


struct tree
{
    int left,right;
}tree[10010];


int getDis(int root)
{
    if(tree[root].left==0&&tree[root].right==0)
        return 1;
    return max(getDis(tree[root].left),getDis(tree[root].right))+1;
}


int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&tree[i].left,&tree[i].right);
        }
        printf("%d\n",getDis(1));
    }
    return 0;
}//Parsed in 0.031 seconds
