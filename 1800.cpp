#include <stdio.h>   
int main() {   
    int a[1025],n,q,k,i;   
    scanf("%d",&n);   
    for(i=0;i<n;i++)     
      scanf("%d",&a[i]);   
    scanf("%d",&q);   
    while(q--)  {   
      scanf("%d",&k);   
      if(k<=0||k>n) printf("-1\n");   
      else {   
         printf("%d\n",a[k-1]);   
         for(i=k-1;i<n-1;i++)   
            a[i]=a[i+1];   
         n--;            
      }   
    }   
}//Parsed in 0.047 seconds
