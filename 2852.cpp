#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>


using namespace std;


char str[3100];
int num[26];


int main()
{
    while(gets(str))
    {
        int len=strlen(str);
        memset(num,0,sizeof(num));
        int len_v=0;
        for(int i=0;i<len;i++)
        {
            if('a'<=str[i]&&str[i]<='z')
            {
                num[str[i]-'a']++;
                len_v++;
            }
        }
        int index=0;
        int maxn=num[0];
        for(int i=1;i<26;i++)
        {
            if(maxn<num[i])
            {
                maxn=num[i];
                index=i;
            }
        }
        //for(int i=index;i<26;i++)
            //if(num[i]==maxn)
                printf("%c %.2lf\n",index+'a',1.0*num[index]/len_v);
    }
    return 0;
}//Parsed in 0.075 seconds
