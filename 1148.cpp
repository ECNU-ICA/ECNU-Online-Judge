#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <queue>


using namespace std;


int const maxSize=210;
int prime[maxSize];
int primeSize;
bool isPrime[maxSize+1];
void init()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    primeSize = 0;
    for (int i=2; i<= maxSize; i++) 
    {
        if(!isPrime[i]) continue; 
        prime[primeSize++]=i; 
        for (int j=i*i; j<=maxSize &&j>=0; j+=i) 
        {
            isPrime[j]=false;
        }
    }
}
int check(int x)
{
	for(int i=0;i<primeSize;i++)
	{
		if(x==prime[i])
			return 1;
	}
	return 0;
}
int maze[105][105];
int vis[105];
int n;
int num;
bool isout;
void dfs(int step)  //1 2 3
{
	if(isout)
		return;
	if(step>num)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j==0)
					printf("%d",maze[i][j]);
				else
					printf(" %d",maze[i][j]);
			}
			printf("\n");
		}
		isout=true;
		return ;
	}
	int x,y;
	x=(step-1)/n;
	y=step-1-x*n;
	//printf("%d %d %d\n",step,x,y);
	for(int i=1;i<=num;i++)
	{
		if(!vis[i])
		{
			if(x-1>=0&&y-1>=0)
			{
				vis[i]=true;
				if(check(i+maze[x][y-1])==1&&check(i+maze[x-1][y])==1)
				{
					maze[x][y]=i;
					dfs(step+1);
				}
				vis[i]=false;
			}
			else if(y-1>=0)
			{
				vis[i]=true;
				if(check(i+maze[x][y-1])==1)
				{
					maze[x][y]=i;
					dfs(step+1);
				}
				vis[i]=false;
			}
			else if(x-1>=0)
			{
				vis[i]=true;
				if(check(i+maze[x-1][y])==1)
				{
					maze[x][y]=i;
					dfs(step+1);
				}
				vis[i]=false;
			}
			else
			{
				vis[i]=true;
				maze[x][y]=i;
				dfs(step+1);
				vis[i]=false;
			}
		}
	}
}
char str6[]="1 2 3 4 7 6\n10 21 16 13 24 5\n19 22 25 18 23 14\n12 31 36 35 8 15\n29 30 17 26 33 28\n32 11 20 27 34 9";


char str7[]="1 2 3 4 7 6 5\n10 9 8 15 16 13 18\n19 22 21 46 37 24 23\n12 49 40 43 30 29 14\n35 48 31 36 17 44 39\n38 41 42 11 26 45 28\n33 20 47 32 27 34 25";


char str8[]="1 2 3 4 7 6 5 8\n10 9 14 15 16 13 18 11\n19 22 39 28 25 34 49 12\n24 37 64 33 46 55 54 17\n23 60 43 40 61 42 29 44\n56 41 30 31 36 47 32 27\n57 26 53 48 35 62 21 52\n50 63 20 59 38 45 58 51";


char str9[]="1 2 3 4 7 6 5 8 9\n10 21 16 13 24 17 12 11 20\n19 22 15 28 43 30 29 18 23\n34 25 46 33 40 31 42 41 38\n27 76 37 64 49 48 59 68 69\n52 61 36 67 60 53 44 39 70\n79 78 35 72 77 74 63 50 81\n58 73 66 65 62 75 26 57 32\n55 54 47 14 45 56 71 80 51";


char str10[]="1 2 3 4 7 6 5 8 9 10\n12 11 20 27 16 13 18 23 14 33\n17 26 21 32 15 28 19 24 29 38\n30 41 62 35 44 39 22 37 42 59\n31 48 65 36 53 50 51 46 25 54\n40 61 66 43 60 47 56 57 82 49\n63 76 73 58 91 90 83 74 75 88\n86 81 100 79 72 77 80 99 52 85\n93 70 97 34 67 96 71 68 45 64\n98 69 94 55 84 95 78 89 92 87";
int main ()
{
	//freopen("out.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
			printf("1\n");
		else if(n>=6)
		{
			if(n==6)
				printf("%s\n",str6);
			else if(n==7)
				printf("%s\n",str7);
			else if(n==8)
				printf("%s\n",str8);
			else if(n==9)
				printf("%s\n",str9);
			else
				printf("%s\n",str10);
		}
		else
		{
			memset(vis,false,sizeof(vis));
			num=n*n;
			isout=false;
			dfs(1);
			if(!isout)
				printf("no answer\n");
		}
	}
    return 0;
}//Parsed in 0.164 seconds
