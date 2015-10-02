#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>


using namespace std;


char tmp[25];
char rtmp[25];


int main()
{
    int n;
    int con;
    int a,b;
    while(scanf("%d",&n)!=EOF)
    {
        con=0;
        while(true)
        {
            sprintf(tmp,"%d",n);
            int len1=strlen(tmp);
            int len2=len1;
            rtmp[len2--]='\0';
            for(int i=0; i<len1; i++)
            {
                rtmp[len2--]=tmp[i];
            }
            sscanf(tmp,"%d",&a);
            sscanf(rtmp,"%d",&b);
            if(a==b)
            {
                break;
            }
            con++;
            n=a+b;
        }
        printf("%d %d\n",con,a);
    }
    return 0;
}//Parsed in 0.042 seconds
