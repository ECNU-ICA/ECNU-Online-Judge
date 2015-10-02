#include<cstdio>
#include<cstring>
#include<cstdlib>


using namespace std;


struct Stu
{
    char name[15];
    int score;
}s[110];
int cmp( const void *a ,const void *b)
{
	if((*(Stu *)a).score != (*(Stu *)b).score)
        return (*(Stu *)b).score - (*(Stu *)a).score;
    return strcmp((*(Stu *)a).name,(*(Stu *)b).name);
}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s %d",s[i].name,&s[i].score);
        }
        qsort(s,n,sizeof(s[0]),cmp);
        for(int i=0;i<n;i++)
        {
            if(s[i].score>=60)
                printf("%s %d\n",s[i].name,s[i].score);
            else
                break;
        }
    }
    return 0;
}//Parsed in 0.076 seconds
