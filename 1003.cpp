#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>


using namespace std;


char a[2001], b[2001];  //数组a既是用于存放输入，又用来当作线性栈处理


int main()
{   int i, j, k, len, m = 0;    //i作为数组A的下标，j用于数组B的小标，k作为栈的下标处理


    while(gets(a))  //循环处理输入，直至输入CTRL+Z结束循环
    {   i = 0;
        j = 0;
        k = 0;
        len = strlen(a);


        for(; i<len; i++)   //将中缀换成后缀式，存放到数组b中
            switch(a[i])
            {   case 'V':
                case 'F':   b[j++] = a[i];
                            break;
                case '(':
                case '!':   a[k++] = a[i];
                            break;
                case '&':   for(; k>0 && a[k-1]=='!'; k--)//  !>&
                                b[j++] = a[k-1];
                            a[k++] = a[i];
                            break;
                case '|':   for(; k>0 && (a[k-1]=='&' || a[k-1]=='!'); k--)//  &>|  !>|
                                b[j++] = a[k-1];
                            a[k++] = a[i];
                            break;
                case ')':   for(; k>0 && a[k-1]!='('; k--)//
                                b[j++] = a[k-1];
                            k--;
                            break;
            }
        while(k>0)
            b[j++] = a[--k];
        b[j] = '\0';
        len = strlen(b);
        //printf("%s\n",b);




        for(j = 0, k = 0; j<len; j++)   //后缀式求值
            switch(b[j])
            {   case 'V':
                case 'F':   a[k++] = b[j];
                            break;
                case '!':   a[k-1] = (a[k-1]=='F')? 'V' : 'F';
                            break;
                case '&':   a[k-2] = (a[k-1]=='V' && a[k-2]=='V')? 'V' : 'F';
                            k--;
                            break;
                case '|':   a[k-2] = (a[k-1]=='F' && a[k-2]=='F')? 'F' : 'V';
                            k--;
                            break;
            }
        printf("Expression %d: %c\n", ++m, a[0]);   //循环结束时a[0]一定为最终的结果
    }
    return 0;
}//Parsed in 0.173 seconds
