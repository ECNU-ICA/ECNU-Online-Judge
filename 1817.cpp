#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<set>
#include<vector>


using namespace std;


const int maxSize = 200000;
struct E  //邻接链表中的链表元素结构体
{
    int next; //代表直接相邻的结点
    int c; //代表该边的权值(长度)
};
vector<E> edge[maxSize];//邻接链表
//标记,当mark[j]为true时表示结点j的最短路径长度已经得到,
//该结点已经加入集合K
bool mark[maxSize];
//距离向量,当mark[i]为true时,表示已得的最短路径长度;
//否则,表示所有从结点1出发，经过已知的最短路径达到
//集合K中的某结点，再经过一条边到达结点i的路径中最短的距离
int dist[maxSize];
int path[maxSize];
//////堆--用于优化//////
struct rec
{
    //第一关键字x表示距离
    //第二关键字nextP表示点的编号
    int dis,nextP,pre;
};
struct cmp
{
    bool operator()(const rec&a,const rec&b)
    {
        return (a.dis<b.dis)||(a.dis==b.dis&&a.nextP<b.nextP);
    }
};
multiset<rec,cmp> h;
////////////////////////
void dijkstra_heap(int start)//从start开始
{
    rec a;
    a.dis=0;//第一关键字dis表示距离
    a.nextP=start;//第二关键字nextP表示点的编号
    a.pre=-1;
    h.insert(a);//将a插入序列中
    dist[start] = 0; //得到最近的点为结点1,长度为0
    int newP; //集合K中新加入的点为结点1
    while(!h.empty())//h集合中的元素是否为空
    {
        __typeof(h.begin()) ptr=h.begin();
        newP=(*ptr).nextP;
        mark[newP] = true;
        path[newP] =(*ptr).pre;
        //printf("p--->%d\n",newP);
        h.erase(ptr);
        int num=edge[newP].size();
        for(int j = 0; j < num ; j ++)
        {
            int t = edge[newP][j].next;//该边的另一个结点
            int c = edge[newP][j].c;//该边的长度
            //若另一个结点也属于集合K,则跳过
            if (mark[t] == true) continue;
            //若该结点尚不可达,
            if (dist[t] == - 1)
            {
                dist[t] = dist[newP] + c;
                a.dis=c;
                a.nextP=t;
                a.pre=newP;
                h.insert(a);
            }
            //该结点从新加入的结点经过一条边到达时比以往距离更短
            else if(dist[t] > dist[newP] + c)
            {
                a.dis=dist[t];
                a.nextP=t;
                ptr=h.upper_bound(a);//找到序列h中a之后的元素的地址
                ptr--;//地址减一就是a所在的地址
                h.erase(ptr);//删掉a


                a.dis=dist[newP] + c;
                dist[t]=a.dis;//更新最短路的值
                a.pre=newP;
                h.insert(a);//插入
            }
        }
    }
}
int main ()
{
    //freopen("in.txt","r",stdin);
    int n, m;
    while (scanf ("%d%d",&n,&m) != EOF)
    {
        if (n == 0 && m == 0) break;
        //初试化邻接链表
        for (int i = 1; i <= n; i ++) edge[i].clear();
        while(!h.empty()) h.clear();
        while(m --)
        {
            int a , b , c;
            scanf ("%d%d%d",&a,&b,&c);
            //将邻接信息加入邻接链表,由于原图为无向图,
            //固每条边信息都要添加到其两个顶点的两条单链表中
            E tmp;
            tmp.next = b;
            tmp.c = c;
            edge[a].push_back(tmp);
            //tmp.next = a;
            //edge[b].push_back(tmp);
        }
        for (int i = 1; i <= n; i ++) //初始化
        {
            dist[i] = -1; //所有距离为-1，即不可达
            mark[i] = false; //所有结点不属于集合K
            path[i]=-1;
        }
        dijkstra_heap(1);
        printf("%d\n",dist[n]); //输出
    }
    return 0;
}

//Parsed in 0.272 seconds
