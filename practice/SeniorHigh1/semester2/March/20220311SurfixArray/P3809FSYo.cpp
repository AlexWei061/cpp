#include<bits/stdc++.h>
#define N 1000050
using namespace std;
char s[N]; // 原串
int x[N],y[N],tmp[N]; // 排序时需要用 
int c[N]; // 排序时的桶
int SA[N]; 
int n,m;
void Sort(){
	for(int i=1;i<=m;i++) c[i] = 0;
	for(int i=1;i<=n;i++) c[x[i]]++;
	for(int i=2;i<=m;i++) c[i] += c[i-1]; 
	/* c[i] 求前缀和 , 表示以第一关键字排到第几名 
	比如有 3个a , 2个b , 那么第一关键字为b 的第二关键字最大的就是第5名 */ 
	for(int i=n;i>=1;i--) SA[c[x[y[i]]]--] = y[i];
	// 接着把存b的桶减一个 ,  第一关键字为b 的第二关键字第二大的就是第4名 
}
void get_SA(){
	//y[i] 表示第二关键字为第i名的在的后缀位置 
	for(int i=1;i<=n;i++) x[i] = s[i] , y[i] = i; Sort();
	for(int k=1;k<=n;k<<=1){
		int cnt = 0; // y数组下标
		for(int i=n-k+1;i<=n;i++) y[++cnt] = i; // 最右边一块的第二关键字为0
		for(int i=1;i<=n;i++) if(SA[i]>k) y[++cnt] = SA[i] - k;
		/*排名为i的数 在数组中是否在第k位以后
		如果满足(sa[i]>k) 那么它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y就行了*/
		Sort(); swap(x,tmp); x[SA[1]] = 1; int num = 1;
		for(int i=2;i<=n;i++){
			if(tmp[SA[i]] == tmp[SA[i-1]] && tmp[SA[i]+k] == tmp[SA[i-1]+k])
			// 第一二关键字都相同 
				x[SA[i]] = num;
			else x[SA[i]] = ++num;
		} m = num; 
	}
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%s",s+1); n = strlen(s+1); m = 127;
	get_SA(); for(int i=1;i<=n;i++) printf("%d ",SA[i]); return 0;
} 