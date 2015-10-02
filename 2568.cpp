#include<iostream>
#include<stdio.h>
using namespace std;
int main ()
{
    int n;
    int j;
    int i;
    int a[110];
    int b[110];
    int c[110];
    while (scanf ("%d",&n) != EOF)
    {
        for (i = 0; i < n; i ++)
        {
            scanf ("%d",&a[i]);
            scanf ("%d",&b[i]);
        }
        for(i=0; i<n; i++)
        {
            c[i]=a[i]+b[i];
        }
        int k[110];
        for(i=0; i<n; i++)
        {
            j=c[i];
            int p=0;
            while(j!=0)
            {
                j=j/10;
                p++;
            }
            k[i]=p;
        }
        for(i=0; i<n; i++)
        {
            cout<<k[i]<<endl;
        }
    }
}//Parsed in 0.070 seconds
