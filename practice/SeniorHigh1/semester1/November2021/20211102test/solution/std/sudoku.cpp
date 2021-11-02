#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[110][12][12];
void print(int x,int y)
{
	const char s[]="+-+-+-+-+-+-+-+-+-+";
	for(int i=1;i<=9;i++)
	{
		printf("%s\n",s);
		for(int j=1;j<=9;j++)
		{
			printf("|%d",num[y][i][j]);
			num[x][i][j]=num[y][i][j];
		}
		printf("|\n");
	}
	printf("%s\n",s);
}
int ck(int a,int b,int c,int d)
{
	if(a==c||b==d)
		return 1;
	if((a-1)/3==(c-1)/3&&(b-1)/3==(d-1)/3)
		return 1;
	return 0;
}
void insert(int i,int j,int k,int xx,int yy)
{
	for(int z=1;z<=9;z++)
		for(int w=1;w<=9;w++)
			num[xx][z][w]=num[yy][z][w];
	if(num[yy][i][j])
	{
		printf("Error!\n");
		return;
	}
	for(int x=1;x<=9;x++)
		if(num[yy][i][x]==k)
		{
			printf("Error:row!\n");
			return;
		}
	for(int x=1;x<=9;x++)
		if(num[yy][x][j]==k)
		{
			printf("Error:column!\n");
			return;
		}	
	for(int x=1;x<=9;x++)
		for(int y=1;y<=9;y++)
		{
			if((x-1)/3==(i-1)/3&&(y-1)/3==(j-1)/3)
				if(num[yy][x][y]==k)
				{
					printf("Error:square!\n");
					return;
				}
		}
	num[xx][i][j]=k;
	printf("OK!\n");
}
void del(int i,int j,int xx,int yy)
{
	for(int z=1;z<=9;z++)
		for(int w=1;w<=9;w++)
			num[xx][z][w]=num[yy][z][w];
	if(num[xx][i][j]==0)
		printf("Error!\n");
	else
		printf("OK!\n");
	num[xx][i][j]=0;
}
int is[12];
void fi(int i,int j,int xx,int yy)
{
	for(int z=1;z<=9;z++)
		for(int w=1;w<=9;w++)
			num[xx][z][w]=num[yy][z][w];
	if(num[xx][i][j])
	{
		printf("Error!\n");
		return;
	}
	memset(is,0,sizeof(is));
	for(int k=1;k<=9;k++)
		for(int l=1;l<=9;l++)
			if(ck(i,j,k,l))
				is[num[xx][k][l]]=1;
	int t=0;
	for(int k=1;k<=9;k++)
		if(is[k]==0)
			t++;
	printf("%d\n",t);
	for(int k=1;k<=9;k++)
		if(is[k]==0)
			printf("%d\n",k);
}
char s[25];
void get()
{
	for(int i=1;i<=19;i++)
	{
		scanf("%s",s);
		if(i%2==0)
		{
			for(int j=1;j<19;j+=2)
				num[0][i/2][j/2+1]=s[j]-48;
		}
	}
}
void merge(int i,int j,int k)
{
	int a=0,b=0;
	for(int x=1;x<=9;x++)
		for(int y=1;y<=9;y++)
		{
			if(num[j][x][y]!=0)
			{
				int can=1;
				for(int z=1;z<=9;z++)
					for(int w=1;w<=9;w++)
						if(num[i][z][w]==num[j][x][y]&&ck(x,y,z,w))
							can=0;
				if(can)
				{
					num[i][x][y]=num[j][x][y];
					a++;
					continue;
				}
			}
			if(num[k][x][y]!=0)
			{
				int can=1;
				for(int z=1;z<=9;z++)
					for(int w=1;w<=9;w++)
						if(num[i][z][w]==num[k][x][y]&&ck(x,y,z,w))
							can=0;
				if(can)
				{
					num[i][x][y]=num[k][x][y];
					b++;
					continue;
				}
			}		
		}
	printf("%d %d\n",a,b);
}		
int main()
{
	freopen ("sudoku.in","r",stdin);
	freopen ("sudoku.out","w",stdout);
	get();
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		scanf("%s",s);
		if(s[0]=='P')
		{
			print(i,i-1);
		}
		else
			if(s[0]=='I')
			{
				int t1,t2,t3;
				scanf("%d%d%d",&t1,&t2,&t3);
				insert(t1,t2,t3,i,i-1);
			}
			else
				if(s[0]=='Q')
				{
					int t1,t2;
					scanf("%d%d",&t1,&t2);
					fi(t1,t2,i,i-1);
				}
				else
					if(s[0]=='D')
					{
						int t1,t2;
						scanf("%d%d",&t1,&t2);
						del(t1,t2,i,i-1);
					}
					else
					{
						int t1,t2;
						scanf("%d%d",&t1,&t2);
						merge(i,t1,t2);
					}				
	}
	return 0;				
}    