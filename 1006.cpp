#include <cstdio>
#include <cstring>//c
#include <string>//C++
#include <cmath>
#include <cstdlib>


using namespace std;
int const mmax=1000005;
bool isPrime[1000005];


void FilterPrime()
{
	for(int i=2;i<=mmax;++i)
        isPrime[i] = true;
	isPrime[0]=isPrime[1]=false;
	for(int j=2;j<=mmax;++j){
		if(isPrime[j]==true)
			for(int m=2;j*m<=mmax;++m)
                isPrime[j*m] = false;
	}
}


int main()
{
    FilterPrime();
    int a,b,c;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        c=0;
        for(int i=a;i<=b;i++)
        {
            if(isPrime[i])
                ++c;
        }
        printf("%d\n",c);
    }
    return 0;
}//Parsed in 0.063 seconds
