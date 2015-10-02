#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<set>
#include<vector>


using namespace std;


const int maxSize = 200000;
struct E  //ÁÚ½ÓÁ´±íÖÐµÄÁ´±íÔªËØ½á¹¹Ìå
{
    int next; //´ú±íÖ±½ÓÏàÁÚµÄ½áµã
    int c; //´ú±í¸Ã±ßµÄÈ¨Öµ(³¤¶È)
};
vector<E> edge[maxSize];//ÁÚ½ÓÁ´±í
//±ê¼Ç,µ±mark[j]ÎªtrueÊ±±íÊ¾½áµãjµÄ×î¶ÌÂ·¾¶³¤¶ÈÒÑ¾­µÃµ½,
//¸Ã½áµãÒÑ¾­¼ÓÈë¼¯ºÏK
bool mark[maxSize];
//¾àÀëÏòÁ¿,µ±mark[i]ÎªtrueÊ±,±íÊ¾ÒÑµÃµÄ×î¶ÌÂ·¾¶³¤¶È;
//·ñÔò,±íÊ¾ËùÓÐ´Ó½áµã1³ö·¢£¬¾­¹ýÒÑÖªµÄ×î¶ÌÂ·¾¶´ïµ½
//¼¯ºÏKÖÐµÄÄ³½áµã£¬ÔÙ¾­¹ýÒ»Ìõ±ßµ½´ï½áµãiµÄÂ·¾¶ÖÐ×î¶ÌµÄ¾àÀë
int dist[maxSize];
int path[maxSize];
//////¶Ñ--ÓÃÓÚÓÅ»¯//////
struct rec
{
    //µÚÒ»¹Ø¼ü×Öx±íÊ¾¾àÀë
    //µÚ¶þ¹Ø¼ü×ÖnextP±íÊ¾µãµÄ±àºÅ
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
void dijkstra_heap(int start)//´Óstart¿ªÊ¼
{
    rec a;
    a.dis=0;//µÚÒ»¹Ø¼ü×Ödis±íÊ¾¾àÀë
    a.nextP=start;//µÚ¶þ¹Ø¼ü×ÖnextP±íÊ¾µãµÄ±àºÅ
    a.pre=-1;
    h.insert(a);//½«a²åÈëÐòÁÐÖÐ
    dist[start] = 0; //µÃµ½×î½üµÄµãÎª½áµã1,³¤¶ÈÎª0
    int newP; //¼¯ºÏKÖÐÐÂ¼ÓÈëµÄµãÎª½áµã1
    while(!h.empty())//h¼¯ºÏÖÐµÄÔªËØÊÇ·ñÎª¿Õ
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
            int t = edge[newP][j].next;//¸Ã±ßµÄÁíÒ»¸ö½áµã
            int c = edge[newP][j].c;//¸Ã±ßµÄ³¤¶È
            //ÈôÁíÒ»¸ö½áµãÒ²ÊôÓÚ¼¯ºÏK,ÔòÌø¹ý
            if (mark[t] == true) continue;
            //Èô¸Ã½áµãÉÐ²»¿É´ï,
            if (dist[t] == - 1)
            {
                dist[t] = dist[newP] + c;
                a.dis=c;
                a.nextP=t;
                a.pre=newP;
                h.insert(a);
            }
            //¸Ã½áµã´ÓÐÂ¼ÓÈëµÄ½áµã¾­¹ýÒ»Ìõ±ßµ½´ïÊ±±ÈÒÔÍù¾àÀë¸ü¶Ì
            else if(dist[t] > dist[newP] + c)
            {
                a.dis=dist[t];
                a.nextP=t;
                ptr=h.upper_bound(a);//ÕÒµ½ÐòÁÐhÖÐaÖ®ºóµÄÔªËØµÄµØÖ·
                ptr--;//µØÖ·¼õÒ»¾ÍÊÇaËùÔÚµÄµØÖ·
                h.erase(ptr);//É¾µôa


                a.dis=dist[newP] + c;
                dist[t]=a.dis;//¸üÐÂ×î¶ÌÂ·µÄÖµ
                a.pre=newP;
                h.insert(a);//²åÈë
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
        //³õÊÔ»¯ÁÚ½ÓÁ´±í
        for (int i = 1; i <= n; i ++) edge[i].clear();
        while(!h.empty()) h.clear();
        while(m --)
        {
            int a , b , c;
            scanf ("%d%d%d",&a,&b,&c);
            //½«ÁÚ½ÓÐÅÏ¢¼ÓÈëÁÚ½ÓÁ´±í,ÓÉÓÚÔ­Í¼ÎªÎÞÏòÍ¼,
            //¹ÌÃ¿Ìõ±ßÐÅÏ¢¶¼ÒªÌí¼Óµ½ÆäÁ½¸ö¶¥µãµÄÁ½Ìõµ¥Á´±íÖÐ
            E tmp;
            tmp.next = b;
            tmp.c = c;
            edge[a].push_back(tmp);
            //tmp.next = a;
            //edge[b].push_back(tmp);
        }
        for (int i = 1; i <= n; i ++) //³õÊ¼»¯
        {
            dist[i] = -1; //ËùÓÐ¾àÀëÎª-1£¬¼´²»¿É´ï
            mark[i] = false; //ËùÓÐ½áµã²»ÊôÓÚ¼¯ºÏK
            path[i]=-1;
        }
        dijkstra_heap(1);
        printf("%d\n",dist[n]); //Êä³ö
    }
    return 0;
}

//Parsed in 0.253 seconds
