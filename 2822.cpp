#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;


#define N 80


int main()
{
    int i;
    char s[N];
    while(scanf("%s",s)!=EOF)
    {
        for (i=0; s[i]; i++) if (s[i]=='.') break; //ÅÐ¶ÏÊÇ·ñº¬Ð¡Êýµã
        if(s[i])//º¬Ð¡ÊýµãµÄ×Ö·û´®±íÊ¾Ò»¸ö¸¡µãÊý
        {
            //×Ö·û´®±íÊ¾µÄ¸¡µãÊý×ª»»ÎªÒ»¸ö¸¡µãÊý
            double f=atof(s);
            int len=sizeof(double);
            for (i=0; i<len; i++) //ÒÀ´ÎÊä³ö¸¡µãÊýµÄÃ¿¸ö×Ö½ÚÖµ
                //²»Í¬±àÒë»·¾³ÖÐµÄ×Ö½ÚÊý¿ÉÄÜ²»Í¬
                //×Ö½ÚµÄ´æ·ÅË³ÐòÒ²¿ÉÄÜ²»Í¬,ÓëÔËÐÐ³ÌÐòµÄCPUÌåÏµ½á¹¹ÓÐ¹Ø
                //Èç£ºIntel CPUµÄ´æ·ÅË³ÐòÎª£º µÍ×Ö½Ú-->¸ß×Ö½Ú
                printf("%02x ",((unsigned char*)&f)[i]); //°´16½øÖÆ¸ñÊ½Êä³ö&f¿ªÊ¼µÄÃ¿¸ö×Ö½Ú£¬Ò»´ÎÊä³öÒ»¸ö×Ö½Ú
        }
        else//²»º¬Ð¡ÊýµãµÄ×Ö·û´®±íÊ¾Ò»¸öÕûÊý
        {
            //×Ö·û´®±íÊ¾µÄÕûÊý×ª»»ÎªÒ»¸öÕûÊý
            int d=atoi(s);
            int len=sizeof(int);
            for (i=0; i<len; i++)
                printf("%02x ",((unsigned char*)&d)[i]);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.055 seconds
