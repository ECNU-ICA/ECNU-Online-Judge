#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>


using namespace std;


char a[2001], b[2001];  //Êý×éa¼ÈÊÇÓÃÓÚ´æ·ÅÊäÈë£¬ÓÖÓÃÀ´µ±×÷ÏßÐÔÕ»´¦Àí


int main()
{   int i, j, k, len, m = 0;    //i×÷ÎªÊý×éAµÄÏÂ±ê£¬jÓÃÓÚÊý×éBµÄÐ¡±ê£¬k×÷ÎªÕ»µÄÏÂ±ê´¦Àí


    while(gets(a))  //Ñ­»·´¦ÀíÊäÈë£¬Ö±ÖÁÊäÈëCTRL+Z½áÊøÑ­»·
    {   i = 0;
        j = 0;
        k = 0;
        len = strlen(a);


        for(; i<len; i++)   //½«ÖÐ×º»»³Éºó×ºÊ½£¬´æ·Åµ½Êý×ébÖÐ
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




        for(j = 0, k = 0; j<len; j++)   //ºó×ºÊ½ÇóÖµ
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
        printf("Expression %d: %c\n", ++m, a[0]);   //Ñ­»·½áÊøÊ±a[0]Ò»¶¨Îª×îÖÕµÄ½á¹û
    }
    return 0;
}//Parsed in 0.202 seconds
