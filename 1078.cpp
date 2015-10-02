#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <set>


using namespace std;


#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0


int dayOfMonth[13][2] =
{
    {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},
    {30,30},{31,31},{31,31},{30,30},
    {31,31},{30,30},{31,31}
}; //预存每月的




int main()
{
    //freopen("in.txt","r",stdin);
    int T,month,day;
    int sumDay=0;
    for(int i=1;i<10;i++)
    {
        sumDay+=dayOfMonth[i][ISYEAP(2006)];
    }
    sumDay+=21;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&month,&day);
        int tmpDay=0;
        for(int i=0;i<month;i++)
        {
            tmpDay+=dayOfMonth[i][ISYEAP(2006)];
        }
        tmpDay+=day;
        if(tmpDay<sumDay)
        {
            printf("%d\n",sumDay-tmpDay);
        }
        else if(tmpDay==sumDay)
        {
            printf("It's today!!\n");
        }
        else
        {
            printf("What a pity, it has passed!\n");
        }
    }
    return 0;
}//Parsed in 0.061 seconds
