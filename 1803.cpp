#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


typedef struct Node
{
    int num;
    struct Node *next;
} Node;
Node *head;
void print(Node *p)
{
    p=p->next;
    printf("%d",p->num);
    while(p->next!=NULL)
    {
        p=p->next;
        printf(" %d",p->num);
    }
    printf("\n");
}
void ins1(Node *p,int x)
{
    while(p->next!=NULL)
    {
        p=p->next;
    }
    Node *t=(Node *)malloc(sizeof(Node));
    t->num=x;
    t->next=p->next;
    p->next=t;
}
void ins2(Node *p,int x,int y)
{
    while(p!=NULL)
    {
        if(p->num==x)
        {
            Node *t=(Node *)malloc(sizeof(Node));
            t->num=y;
            t->next=p->next;
            p->next=t;
        }
        p=p->next;
    }
}


int main()
{
    //freopen("in.txt","r",stdin);
    int n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        head=(Node *)malloc(sizeof(Node));
        head->next=NULL;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            ins1(head,a);
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            ins2(head,a,b);
            print(head);
        }
    }
    return 0;
}//Parsed in 0.101 seconds
