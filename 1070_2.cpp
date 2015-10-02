#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;


#define maxDigits 300


//¸ß¾«¶ÈÕûÊý½á¹¹Ìå
typedef struct bigInteger
{
    int digit[maxDigits];
    int size;
    void init()//³õÊ¼»¯
    {
        for (int i = 0; i < maxDigits; i ++)
            digit[i] = 0;
        size = 0;
    }
    //ÓÃÒ»¸öÆÕÍ¨ÕûÊý³õÊ¼»¯¸ß¾«¶ÈÕûÊý
    void set (int x)
    {
        init();
        do
        {
            digit[size ++] = x % 10000;
            x /= 10000;
        }
        while(x != 0);
    }
    void set (__int64 x)
    {
        init();
        do
        {
            digit[size ++] = x % 10000;
            x /= 10000;
        }
        while(x != 0);
    }
    void set(char str[])
    {
        //´Ó×Ö·û´®ÖÐÌáÈ¡ÕûÊý
        init(); //¶Ô½á¹¹Ìå³õÊ¼»¯
        int L = strlen(str); //¼ÆËã×Ö·û´®³¤¶È
        //´Ó×îºóÒ»¸ö×Ö·û¿ªÊ¼µ¹Ðò±éÀú×Ö·û´®,
        //j¿ØÖÆÃ¿4¸ö×Ö·û×ª»»ÎªÒ»¸öÊý×Ö´æÈëÊý×é,
        //tÁÙÊ±±£´æ×Ö·û×ª»»ÎªÊý×ÖµÄÖÐ¼äÖµ,
        //c±íÊ¾µ±Ç°Î»µÄÈ¨ÖØ,°´1,10,100,1000Ë³Ðò±ä»¯
        for (int i = L - 1,j = 0,t = 0,c = 1; i >= 0; i --)
        {
            //¼ÆËãÕâ¸öËÄÎ»ÊýÖÐµ±Ç°×Ö·û´ú±íµÄÊý×Ö,¼´Êý×Ö³ËÒÔµ±Ç°Î»È¨ÖØ
            t += (str[i] - '0') * c;
            j ++; //µ±Ç°×ª»»×Ö·ûÊýÔö¼Ó
            c *= 10; //¼ÆËãÏÂÒ»Î»È¨ÖØ
            //ÈôÒÑ¾­Á¬Ðø×ª»»ËÄ¸ö×Ö·û,»òÕßÒÑ¾­µ½´ï×îºóÒ»¸ö×Ö·û
            if (j == 4 || i == 0)
            {
                //½«ÕâËÄ¸ö×Ö·û´ú±íµÄËÄÎ»Êý´æÈëÊý×é,sizeÒÆ¶¯µ½ÏÂÒ»¸öÊý×éµ¥Î»
                digit[size ++] = t;
                j = 0;//ÖØÐÂ¿ªÊ¼¼ÆËãÏÂ4¸ö×Ö·û
                t = 0;//ÁÙÊ±±äÁ¿Çå0
                c = 1; //È¨ÖØ±äÎª1
            }
        }
    }
    void output()//Êä³ö
    {
        for (int i = size - 1; i >= 0; i --)
        {
            if (i != size - 1) printf("%04d",digit[i]);
            else printf("%d",digit[i]);
        }
    }
    //¸ß¾«¶ÈÕûÊýÓëÆÕÍ¨ÕûÊýµÄ³Ë»ý
    bigInteger operator * (int x) const
    {
        bigInteger ret;
        ret.init();
        int carry = 0;
        for (int i = 0; i < size; i ++)
        {
            int tmp = x * digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size ++] = tmp;
        }
        if (carry != 0)
        {
            ret.digit[ret.size ++] = carry;
        }
        return ret;
    }
    //¸ß¾«¶ÈÕûÊýÓë¸ß¾«¶ÈÕûÊýµÄ³Ë»ý
    bigInteger operator * (const bigInteger &A) const
    {
        bigInteger ret;
        ret.init();
        ret.size=size+A.size+2;
        for(int j=0; j<A.size; ++j)
        {
            int carry = 0,i=0;
            for (i = 0; i < size; i ++)
            {
                if(j==0)
                {
                    int tmp = A.digit[j] * digit[i] + carry;
                    carry = tmp / 10000;
                    tmp %= 10000;
                    ret.digit[i+j] = tmp;
//                    printf("---->%d %d %d\n",carry,tmp,ret.digit[i+j]);
                }
                else
                {
                    int tmp = A.digit[j] * digit[i] + carry + ret.digit[j+i];
                    carry = tmp / 10000;
                    tmp %= 10000;
                    ret.digit[j+i] = tmp;
//                    printf("2---->%d %d %d\n",carry,tmp,ret.digit[i+j]);
                }
            }
            if (carry != 0)
            {
                ret.digit[i+j] = carry;
            }
//            for (int k = 3; k >= 0; k --)
//            {
//                if (k != 3) printf("%04d",ret.digit[k]);
//                else printf("%d",ret.digit[k]);
//            }
//            printf("\n");
//            printf("=====================\n");
        }
        //Çå³ý¸ßÎ»0
        while(ret.digit[ret.size-1]==0&&ret.size>=2)
        {
            ret.size--;
        }
        return ret;
    }
    //¸ß¾«¶ÈÕûÊýÖ®¼äµÄ¼Ó·¨ÔËËã
    bigInteger operator + (const bigInteger &A) const
    {
        bigInteger ret;
        ret.init();
        int carry = 0;
        for (int i = 0; i < A.size || i < size; i ++)
        {
            int tmp = A.digit[i] + digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size ++] = tmp;
        }
        if (carry != 0)
        {
            ret.digit[ret.size ++] = carry;
        }
        return ret;
    }
    //¸ß¾«¶ÈÕûÊýÖ®¼äµÄ¼õ·¨ÔËËã£¬½öÖ§³Ö´óÊý-Ð¡Êý
    bigInteger operator - (const bigInteger &A) const
    {
        bigInteger ret;
        ret.init();
        int carry = 0;
        for (int i = 0; i < A.size || i < size; i ++)
        {
            int tmp = digit[i] - A.digit[i] - carry;
            if( tmp < 0)
            {
                carry=1;
                tmp+=10000;
            }
            else
            {
                carry = 0;;
            }
            tmp %= 10000;
            ret.digit[ret.size ++] = tmp;
        }
        if (carry != 0)
        {
            ret.digit[ret.size ++] = carry;
        }
        //Çå³ý¸ßÎ»0
        while(ret.digit[ret.size-1]==0&&ret.size>=2)
        {
            ret.size--;
        }
        return ret;
    }
    //¸ß¾«¶ÈÕûÊý³ýÒÔÆÕÍ¨ÕûÊý£¬½öÖ§³Ö´óÊý/Ð¡Êý
    bigInteger operator / (int x) const
    {
        bigInteger ret; //·µ»ØµÄ¸ß¾«¶ÈÕûÊý
        ret.init(); //·µ»ØÖµ³õÊ¼»¯
        int remainder = 0; //ÓàÊý
        //´Ó×î¸ßÎ»ÖÁ×îµÍÎ»ÒÀ´ÎÍê³É¼ÆËã
        for (int i = size - 1; i >= 0; i --)
        {
            //¼ÆËãµ±Ç°Î»ÊýÖµ¼ÓÉÏ¸ßÎ»Ê£ÓàµÄÓàÊýµÄºÍ¶ÔxÇóµÃµÄÉÌ
            int t = (remainder * 10000 + digit[i]) / x;
            //¼ÆËãµ±Ç°Î»ÊýÖµ¼ÓÉÏ¸ßÎ»Ê£ÓàµÄÓàÊýµÄºÍ¶ÔxÇóÄ£ºóµÃµÄÓàÊý
            int r = (remainder * 10000 + digit[i]) % x;
            ret.digit[i] = t; //±£´æ±¾Î»µÄÖµ
            remainder = r; //±£´æÖÁ±¾Î»ÎªÖ¹µÄÓàÊý
        }
        // ·µ»Ø¸ß¾«¶ÈÕûÊýµÄsize ³õÊ¼ÖµÎª0,
        //¼´µ±ËùÓÐÎ»Êý×Ö¶¼Îª0Ê±,digit[0]´ú±íÊý×Ö0,
        //×÷Îª×î¸ßÓÐÐ§Î»,¸ß¾«¶ÈÕûÊý¼´ÎªÊý×Ö0
        ret.size = 0;
        for (int i = 0; i < maxDigits; i ++)
        {
            if (digit[i] != 0) ret.size = i;
        } //Èô´æÔÚ·Ç0Î»,È·¶¨×î¸ßµÄ·Ç0Î»,×÷Îª×î¸ßÓÐÐ§Î»
        //×î¸ßÓÐÐ§Î»µÄÏÂÒ»Î»¼´ÎªÏÂÒ»¸öÎÒÃÇ²»ÔøÊ¹ÓÃµÄdigitÊý×éµ¥Ôª,È·¶¨ÎªsizeµÄÖµ
        ret.size ++;
        return ret; //·µ»Ø
    }
    //¸ß¾«¶ÈÕûÊý¶ÔÆÕÍ¨ÕûÊýÇóÓàÊý
    int operator % (int x) const
    {
        int remainder = 0; //ÓàÊý
        for (int i = size - 1; i >= 0; i --)
        {
            //int t = (remainder * 10000 + digit[i]) / x;
            int r = (remainder * 10000 + digit[i]) % x;
            remainder = r;
        } //¹ý³ÌÍ¬¸ß¾«¶ÈÕûÊý¶ÔÆÕÍ¨ÕûÊýÇóÉÌ
        return remainder; //·µ»ØÓàÊý
    }
    bool operator < (const bigInteger &A) const
    {
        if(size != A.size)
            return size < A.size;
        for (int i = size-1; i>=0; i--)
        {
            if(digit[i]!=A.digit[i])
                return digit[i]<A.digit[i];
        }
        return false;
    }
    bool operator > (const bigInteger &A) const
    {
        if(size != A.size)
            return size > A.size;
        for (int i = size-1; i>=0; i--)
        {
            if(digit[i]!=A.digit[i])
                return digit[i] > A.digit[i];
        }
        return false;
    }
    bool operator <= (const bigInteger &A) const
    {
        if(size != A.size)
            return size < A.size;
        for (int i = size-1; i>=0; i--)
        {
            if(digit[i]!=A.digit[i])
                return digit[i] < A.digit[i];
        }
        return true;
    }
    bool operator >= (const bigInteger &A) const
    {
        if(size != A.size)
            return size > A.size;
        for (int i = size-1; i>=0; i--)
        {
            if(digit[i]!=A.digit[i])
                return digit[i] > A.digit[i];
        }
        return true;
    }
    bool operator == (const bigInteger &A) const
    {
        if(size != A.size)
            return false;
        for (int i = size-1; i>=0; i--)
        {
            if(digit[i]!=A.digit[i])
                return false;
        }
        return true;
    }
    bool operator != (const bigInteger &A) const
    {
        if(size != A.size)
            return true;
        for (int i = size-1; i>=0; i--)
        {
            if(digit[i]!=A.digit[i])
                return true;
        }
        return false;
    }
    //¸ß¾«¶ÈÕûÊý³ýÒÔ¸ß¾«¶ÈÕûÊý£¬½öÖ§³Ö´óÊý/Ð¡Êý
    bigInteger operator / (const bigInteger &A) const
    {
        bigInteger ret; //·µ»ØµÄ¸ß¾«¶ÈÕûÊý
        ret.init(); //·µ»ØÖµ³õÊ¼»¯
        bigInteger remainder; //ÓàÊý
        remainder.set(0);
        for(int i=0; i<size; ++i)
            ret.digit[i]=digit[i];
        ret.size=size;
        //Ñ°ÕÒ´óÌå·¶Î§
        bigInteger beiShu;
        beiShu.set(1);
        while(true)
        {
            if( (A*beiShu)<=ret && ret<=(A*beiShu*10) )
                break;
            beiShu=beiShu*10;
        }
        //´óÌå·¶Î§ÔÚ(beiShu~10*beiShu)£¬²ÉÓÃ¶þ·Ö²éÕÒ
        bigInteger low,high,mid,_one;
        _one.set(1);
        low=beiShu;
        high=beiShu*10;
        while(low<high)
        {
            mid=(low+high)/2;
            if(mid*A<ret)
                low=mid+_one;
            else
                high=mid-_one;
        }
        if(ret<mid*A)//ÉÌÐÞÕý
            mid=mid-_one;
        remainder=ret-mid*A;
        return mid;//·µ»Ø
    }
    //¸ß¾«¶ÈÕûÊý¶Ô¸ß¾«¶ÈÕûÊýÇóÓàÊý
    bigInteger operator % (const bigInteger &A) const
    {
        bigInteger ret; //·µ»ØµÄ¸ß¾«¶ÈÕûÊý
        ret.init(); //·µ»ØÖµ³õÊ¼»¯
        bigInteger remainder; //ÓàÊý
        remainder.set(0);
        for(int i=0; i<size; ++i)
            ret.digit[i]=digit[i];
        ret.size=size;
        //Ñ°ÕÒ´óÌå·¶Î§
        bigInteger beiShu;
        beiShu.set(1);
        while(true)
        {
            if( (A*beiShu)<=ret && ret<=(A*beiShu*10) )
                break;
            beiShu=beiShu*10;
        }
        //´óÌå·¶Î§ÔÚ(beiShu~10*beiShu)£¬²ÉÓÃ¶þ·Ö²éÕÒ
        bigInteger low,high,mid,_one;
        _one.set(1);
        low=beiShu;
        high=beiShu*10;
        while(low<high)
        {
            mid=(low+high)/2;
            if(mid*A<ret) low=mid+_one;
            else high=mid-_one;
        }
        if(ret<mid*A)//ÉÌÐÞÕý
            mid=mid-_one;
        remainder=ret-mid*A;
        return remainder;//·µ»Ø
    }
} bigInteger;


bigInteger a , b , c;


char str[10000];
char ans[10000];


int main ()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    char str1[1000],str2[1000];
    while(n--)
    {
        scanf("%s %s",str1,str2);
        a.set(str1);
        b.set(str2);
        //printf("a<b %d  \n",a<b);
        //printf("a>b %d  \n",a>b);
        //printf("a<=b %d  \n",a<=b);
        //printf("a>=b %d  \n",a>=b);
        //printf("a==b %d  \n",a==b);
        //printf("a!=b %d\n",a!=b);
        c=a*b;
        c.output();
        printf("\n");
    }
    return 0;
}//Parsed in 0.717 seconds
