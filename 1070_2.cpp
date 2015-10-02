#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;


#define maxDigits 300


//高精度整数结构体
typedef struct bigInteger
{
    int digit[maxDigits];
    int size;
    void init()//初始化
    {
        for (int i = 0; i < maxDigits; i ++)
            digit[i] = 0;
        size = 0;
    }
    //用一个普通整数初始化高精度整数
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
        //从字符串中提取整数
        init(); //对结构体初始化
        int L = strlen(str); //计算字符串长度
        //从最后一个字符开始倒序遍历字符串,
        //j控制每4个字符转换为一个数字存入数组,
        //t临时保存字符转换为数字的中间值,
        //c表示当前位的权重,按1,10,100,1000顺序变化
        for (int i = L - 1,j = 0,t = 0,c = 1; i >= 0; i --)
        {
            //计算这个四位数中当前字符代表的数字,即数字乘以当前位权重
            t += (str[i] - '0') * c;
            j ++; //当前转换字符数增加
            c *= 10; //计算下一位权重
            //若已经连续转换四个字符,或者已经到达最后一个字符
            if (j == 4 || i == 0)
            {
                //将这四个字符代表的四位数存入数组,size移动到下一个数组单位
                digit[size ++] = t;
                j = 0;//重新开始计算下4个字符
                t = 0;//临时变量清0
                c = 1; //权重变为1
            }
        }
    }
    void output()//输出
    {
        for (int i = size - 1; i >= 0; i --)
        {
            if (i != size - 1) printf("%04d",digit[i]);
            else printf("%d",digit[i]);
        }
    }
    //高精度整数与普通整数的乘积
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
    //高精度整数与高精度整数的乘积
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
        //清除高位0
        while(ret.digit[ret.size-1]==0&&ret.size>=2)
        {
            ret.size--;
        }
        return ret;
    }
    //高精度整数之间的加法运算
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
    //高精度整数之间的减法运算，仅支持大数-小数
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
        //清除高位0
        while(ret.digit[ret.size-1]==0&&ret.size>=2)
        {
            ret.size--;
        }
        return ret;
    }
    //高精度整数除以普通整数，仅支持大数/小数
    bigInteger operator / (int x) const
    {
        bigInteger ret; //返回的高精度整数
        ret.init(); //返回值初始化
        int remainder = 0; //余数
        //从最高位至最低位依次完成计算
        for (int i = size - 1; i >= 0; i --)
        {
            //计算当前位数值加上高位剩余的余数的和对x求得的商
            int t = (remainder * 10000 + digit[i]) / x;
            //计算当前位数值加上高位剩余的余数的和对x求模后得的余数
            int r = (remainder * 10000 + digit[i]) % x;
            ret.digit[i] = t; //保存本位的值
            remainder = r; //保存至本位为止的余数
        }
        // 返回高精度整数的size 初始值为0,
        //即当所有位数字都为0时,digit[0]代表数字0,
        //作为最高有效位,高精度整数即为数字0
        ret.size = 0;
        for (int i = 0; i < maxDigits; i ++)
        {
            if (digit[i] != 0) ret.size = i;
        } //若存在非0位,确定最高的非0位,作为最高有效位
        //最高有效位的下一位即为下一个我们不曾使用的digit数组单元,确定为size的值
        ret.size ++;
        return ret; //返回
    }
    //高精度整数对普通整数求余数
    int operator % (int x) const
    {
        int remainder = 0; //余数
        for (int i = size - 1; i >= 0; i --)
        {
            //int t = (remainder * 10000 + digit[i]) / x;
            int r = (remainder * 10000 + digit[i]) % x;
            remainder = r;
        } //过程同高精度整数对普通整数求商
        return remainder; //返回余数
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
    //高精度整数除以高精度整数，仅支持大数/小数
    bigInteger operator / (const bigInteger &A) const
    {
        bigInteger ret; //返回的高精度整数
        ret.init(); //返回值初始化
        bigInteger remainder; //余数
        remainder.set(0);
        for(int i=0; i<size; ++i)
            ret.digit[i]=digit[i];
        ret.size=size;
        //寻找大体范围
        bigInteger beiShu;
        beiShu.set(1);
        while(true)
        {
            if( (A*beiShu)<=ret && ret<=(A*beiShu*10) )
                break;
            beiShu=beiShu*10;
        }
        //大体范围在(beiShu~10*beiShu)，采用二分查找
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
        if(ret<mid*A)//商修正
            mid=mid-_one;
        remainder=ret-mid*A;
        return mid;//返回
    }
    //高精度整数对高精度整数求余数
    bigInteger operator % (const bigInteger &A) const
    {
        bigInteger ret; //返回的高精度整数
        ret.init(); //返回值初始化
        bigInteger remainder; //余数
        remainder.set(0);
        for(int i=0; i<size; ++i)
            ret.digit[i]=digit[i];
        ret.size=size;
        //寻找大体范围
        bigInteger beiShu;
        beiShu.set(1);
        while(true)
        {
            if( (A*beiShu)<=ret && ret<=(A*beiShu*10) )
                break;
            beiShu=beiShu*10;
        }
        //大体范围在(beiShu~10*beiShu)，采用二分查找
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
        if(ret<mid*A)//商修正
            mid=mid-_one;
        remainder=ret-mid*A;
        return remainder;//返回
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
}//Parsed in 0.716 seconds
