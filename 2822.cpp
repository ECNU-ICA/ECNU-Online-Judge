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
        for (i=0; s[i]; i++) if (s[i]=='.') break; //判断是否含小数点
        if(s[i])//含小数点的字符串表示一个浮点数
        {
            //字符串表示的浮点数转换为一个浮点数
            double f=atof(s);
            int len=sizeof(double);
            for (i=0; i<len; i++) //依次输出浮点数的每个字节值
                //不同编译环境中的字节数可能不同
                //字节的存放顺序也可能不同,与运行程序的CPU体系结构有关
                //如：Intel CPU的存放顺序为： 低字节-->高字节
                printf("%02x ",((unsigned char*)&f)[i]); //按16进制格式输出&f开始的每个字节，一次输出一个字节
        }
        else//不含小数点的字符串表示一个整数
        {
            //字符串表示的整数转换为一个整数
            int d=atoi(s);
            int len=sizeof(int);
            for (i=0; i<len; i++)
                printf("%02x ",((unsigned char*)&d)[i]);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.084 seconds
