#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>


struct In
{
    char key[20];
    char value[20];
}s[6];


int main()
{
    strcpy(s[0].key,"E");strcpy(s[0].value,"Excellent");
    strcpy(s[1].key,"C");strcpy(s[1].value,"Cheer");
    strcpy(s[2].key,"N");strcpy(s[2].value,"Nice");
    strcpy(s[3].key,"U");strcpy(s[3].value,"Ultimate");
    strcpy(s[4].key,"Impossible");strcpy(s[4].value,"I'm possible");
    strcpy(s[5].key,"ACM");strcpy(s[5].value,"Accept More");
    int N;
    char input[20];
    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",input);
        for(int i=0;i<6;i++)
        {
            if(strcmp(s[i].key,input)==0)
            {
                printf("%s\n",s[i].value);
                break;
            }
        }
    }
    return 0;
}//Parsed in 0.093 seconds
