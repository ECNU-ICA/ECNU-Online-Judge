#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<queue>


using namespace std;


typedef struct Graph
{
#define E 1000010
#define N 1000010
// i
//head[i]±íÊ¾ÒÔiÎªÆðµãµÄµÚ1Ìõ±ßµÄ´æ´¢Î»ÖÃ
//next[i]±íÊ¾ÓëµÚiÌõ±ßÍ¬ÆðµãµÄÏÂÒ»Ìõ±ßµÄ´æ´¢Î»ÖÃ
// pnt[j] xµ½iÎ»ÖÃµÄµã
// val[j] xµ½iÎ»ÖÃµÄ±ßµÄÈ¨Öµ
    int pnt[E], next[E];
    int val[E];
    //int parent[E];
    int head[N], nv, ne;
    int endTag;
    void init(const int v)
    {
        nv= v;
        endTag=-1;
        memset(head, endTag, sizeof(head));
        ne= 0;
    }
    //²»´øÈ¨Öµ
    void add(const int u, const int v)
    {
        pnt[ne]= v, next[ne]= head[u], head[u]= ne++;
        //parent[ne]=u;
    }
    //´øÈ¨Öµ
    void add(const int u, const int v, const int w)
    {
        pnt[ne]= v, val[ne]= w, next[ne]= head[u], head[u]= ne++;
        //parent[ne]=u;
    }
} Graph;
Graph g;
bool vis[1000010];
int num;
void bfs(int x)//±éÀúxµÄ
{
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    Q.push(x);
    while(!Q.empty())
    {
        int s=Q.front();
        Q.pop();
        for(int i=g.head[s]; i!=g.endTag; i=g.next[i])
        {
            if(!vis[g.pnt[i]])
            {
                vis[g.pnt[i]]=true;
                num++;
                Q.push(g.pnt[i]);
            }
        }
    }
}


int main()
{
    int n,m,u,v;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        g.init(n);
        memset(vis,false,sizeof(vis));
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            g.add(u,v);
            g.add(v,u);
        }
        vis[u]=true;
        num=1;
        bfs(u);
        if(num==n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}//Parsed in 0.151 seconds
