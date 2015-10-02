#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>


using namespace std;


set<int>eg1;
set<int>eg2;
set<int>eg3;
set<int>::iterator set_iter;
bool isFirst;
void print()
{
    printf("{");
    isFirst=true;
    for(set_iter=eg3.begin(); set_iter!=eg3.end(); set_iter++)
    {
        if(isFirst)
        {
                printf("%d",*set_iter);
                isFirst=false;
        }
        else
            printf(",%d",*set_iter);
    }
    printf("}\n");
}
int main()
{
    int a,b,t;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        eg1.clear();
        eg2.clear();
        for(int i=0; i<a; i++)
        {
            scanf("%d",&t);
            eg1.insert(t);
        }
        for(int i=0; i<b; i++)
        {
            scanf("%d",&t);
            eg2.insert(t);
        }
        eg3.clear();
        set_intersection(eg1.begin(),eg1.end(),eg2.begin(),eg2.end(),insert_iterator<set<int> >(eg3,eg3.begin()));
        print();
        eg3.clear();
        set_union(eg1.begin(),eg1.end(),eg2.begin(),eg2.end(),insert_iterator<set<int> >(eg3,eg3.begin()));
        print();
        eg3.clear();
        set_difference(eg1.begin(),eg1.end(),eg2.begin(),eg2.end(),insert_iterator<set<int> >(eg3,eg3.begin()));
        print();
    }
    return 0;
}//Parsed in 0.109 seconds
