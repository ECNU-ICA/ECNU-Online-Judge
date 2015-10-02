#include <cstdio>


int main()
{
    int N;
    char str[40];
    scanf("%d",&N);
    getchar();
    while(N--)
    {
        scanf("%s",str);
        getchar();
        for(int i=0;i<4;i++)
        {
            int num=((str[0+i*8]-'0')<<7)+((str[1+i*8]-'0')<<6)+((str[2+i*8]-'0')<<5)+((str[3+i*8]-'0')<<4)+((str[4+i*8]-'0')<<3)+((str[5+i*8]-'0')<<2)+((str[6+i*8]-'0')<<1)+((str[7+i*8]-'0')<<0);
            printf("%d",num);
            if(i!=3)
                printf(".");


        }
        printf("\n");
    }
}//Parsed in 0.073 seconds
