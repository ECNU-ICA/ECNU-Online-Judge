#include <cstdio>
#include <cstring>//c
#include <string>//C++
#include <cmath>
#include <cstdlib>


using namespace std;
//计算n的阶乘n！末尾的“0”的个数，可以转换为计算其因式分解中“5”的个数。
//n！= [5k * 5(k-1) * ... * 10 * 5] * a
/*
n<5
f(n!)=0;
n>=5
f(n!)=k+f(k!),k=n/5
*/
int f_i(int num)
{
    int mcount = 0;
    for (; num >= 5; num /= 5)
        mcount += num / 5;
    return mcount;
}


int main()
{
    int n, m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%d\n",f_i(m));
    }
    return 0;
}//Parsed in 0.021 seconds
