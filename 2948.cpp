#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>


using namespace std;


int getNum(char c)
{
    switch(c)
    {
    case 'A':
    case 'B':
    case 'C':return 2;


    case 'D':
    case 'E':
    case 'F':return 3;


    case 'G':
    case 'H':
    case 'I':return 4;


    case 'J':
    case 'K':
    case 'L':return 5;


    case 'M':
    case 'N':
    case 'O':return 6;


    case 'P':
    case 'Q':
    case 'R':
    case 'S':return 7;


    case 'T':
    case 'U':
    case 'V':return 8;


    case 'W':
    case 'X':
    case 'Y':
    case 'Z':return 9;
    }
    return -1;
}


struct In
{
    char num[10];
}s[110];


int cmp(const void *a , const void *b)
{
	return strcmp( (*(In *)a).num , (*(In *)b).num );
}


int main()
{
    int n;
    char tmp[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",tmp);
        int len=strlen(tmp);
        int index=0;
        for(int j=0;j<len;j++)
        {
            if('0'<=tmp[j]&&tmp[j]<='9')
                s[i].num[index++]=tmp[j];
            else if('A'<=tmp[j]&&tmp[j]<='Z')
                {s[i].num[index++]=getNum(tmp[j])+'0';}
        }
        s[i].num[index++]='\0';
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
    {
        //printf("%s\n",s[i].num);
        int con=1,t=i;
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(s[i].num,s[j].num)==0)
            {
                con++;
                i=j;
            }
            else
            {
                break;
            }
        }
        printf("%c%c%c%c-%c%c%c%c %d\n",s[t].num[0],s[t].num[1],s[t].num[2],s[t].num[3],s[t].num[4],s[t].num[5],s[t].num[6],s[t].num[7],con);
    }
    return 0;
}//Parsed in 0.141 seconds
