#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>


using namespace std;


#define LN printf("\n")
#define PP printf(" ")
#define mem(x,y) memset(x,y,sizeof(x))
typedef long long LL;
const int INF= 0x3f3f3f3f;
const int BINF= 0x3f;
const long long LINF= 0x3F3F3F3F3F3F3F3FLL;
const double eps = 1e-8;
template<class T> inline bool insize(T c,T l,T r) {
    if (c>=l&&c<=r) return true;
    return false;
}
int dx[] = {0,1,0,-1, 1, 1, -1, -1};//Right Down Left Up
int dy[] = {1,0,-1,0, 1, -1, 1, -1};
//---------------------------
#define rep(i,a,b)  for(int (i)=(a);(i)<=(b);(i)++)
#define rp(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b,c) for(int i=a;(c>0)?(i<=b):(i>=b);i+=c)
#define du freopen("in.txt","r",stdin)
#define xie freopen("out.txt","w",stdout)
#define DO(n) while(n--)
//---------------------------
//return a^i%n
LL pow_mod(LL a,LL i,LL n){
    if(i==0)
        return 1%n;
    LL temp=pow_mod(a,i>>1,n);
    temp=temp*temp%n;
    if(i&1) temp=(LL)temp*a%n;
    return temp;
}


bool test(int n,int a,int d){
    if(n==2) return true;
    if(n==a) return true;
    if((n&1)==0) return false;
    while(!(d&1)) d=d>>1;
    LL t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1)){
        t=(LL)t*t%n;
        d=d<<1;
    }
    return (t==n-1||(d&1)==1);
}


bool isPrime(int n){
    if(n<2) return false;
    int a[]={2,3,61};
    for(int i=0;i<=2;++i)
        if(!test(n,a[i],n-1))
            return false;
    return true;
}


int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%s\n",isPrime(n)?"YES":"NO");
    }
    return 0;
}//Parsed in 0.139 seconds
