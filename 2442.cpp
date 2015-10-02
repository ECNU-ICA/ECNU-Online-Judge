#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>


using namespace std;
char mmap[]="0102030405060708091011121314151617181920212223242526";
// 0 2 4 6 8
char str[110];
int main ()
{
    int n;
    scanf("%d",&n);getchar();
    while(n--)
    {
        gets(str);
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            int in=2*(str[i]-'a');
            printf("%c%c",mmap[in],mmap[in+1]);
        }
        printf("\n");
    }
    return 0;
}//Parsed in 0.029 seconds
