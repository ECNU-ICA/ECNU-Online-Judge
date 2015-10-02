#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>


using namespace std;


char str[105];
char sp[105][105];


char getLower(char c)
{
    if('A'<=c&&c<='Z')
    {
        c=c+'a'-'A';
    }
    return c;
}


int main()
{
    //freopen("in.txt","r",stdin);
    while(gets(str))
    {
        int len=strlen(str);
        int row=0,index=0;
        int wl=0;
        memset(sp,'\0',sizeof(sp));
        for(int i=0; i<len; ++i)
        {
            if(str[i]!=' '&&str[i]!='-')
            {
                sp[row][index++]=getLower(str[i]);
                wl++;
                //printf("-->  %s\n",sp[row]);
            }
            else
            {
                sp[row][wl]='\0';
                if(!(strcmp(sp[row],"a")==0||strcmp(sp[row],"an")==0||strcmp(sp[row],"and")==0||strcmp(sp[row],"the")==0||strcmp(sp[row],"of")==0||strcmp(sp[row],"for")==0))
                {
                    //printf("%s\n",sp[row]);
                    printf("%c",str[i-wl]);
                }
                row++;
                index=0;
                wl=0;
            }
        }
        sp[row][wl]='\0';
        if(!(strcmp(sp[row],"a")==0||strcmp(sp[row],"an")==0||strcmp(sp[row],"and")==0||strcmp(sp[row],"the")==0||strcmp(sp[row],"of")==0||strcmp(sp[row],"for")==0))
        {
            printf("%c",str[len-wl]);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.171 seconds
