// 因为 FSYo 大佬的代码有注释我就直接放过来了
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000050

int n = 0; int m = 0;
char s[MAXN];                                          // 原串
int x[MAXN] = { 0 };                                   // 排序时需要用
int y[MAXN] = { 0 };
int tmp[MAXN] = { 0 };
int c[MAXN] = { 0 };                                   // 排序时的桶
int SA[MAXN] = { 0 };

void Sort(){
	for(int i = 1; i <= m; i++) c[i] = 0;
	for(int i = 1; i <= n; i++) c[x[i]]++;
	for(int i = 2; i <= m; i++) c[i] += c[i - 1]; 
	/* c[i] 求前缀和 , 表示以第一关键字排到第几名 
	比如有 3个a , 2个b , 那么第一关键字为 b 的第二关键字最大的就是第 5名 */ 
	for(int i = n; i >= 1; i--) SA[c[x[y[i]]]--] = y[i];
	// 接着把存b的桶减一个 ,  第一关键字为 b 的第二关键字第二大的就是第 4名 
}

void getSA(){
	//y[i] 表示第二关键字为第i名的在的后缀位置 
	for(int i = 1; i <= n; i++) x[i] = s[i] , y[i] = i;
	Sort();
	for(int k = 1; k <= n; k <<= 1){
		int cnt = 0; // y 数组下标
		for(int i = n - k + 1; i <= n; i++) y[++cnt] = i; // 最右边一块的第二关键字为 0
		for(int i = 1; i <= n; i++) if(SA[i] > k) y[++cnt] = SA[i] - k;
		/*排名为 i 的数 在数组中是否在第k位以后
		如果满足 (sa[i] > k) 那么它可以作为别人的第二关键字，就把它的第一关键字的位置添加进 y 就行了*/
		Sort(); swap(x, tmp); x[SA[1]] = 1; int num = 1;
		for(int i = 2; i <= n; i++){
			if(tmp[SA[i]] == tmp[SA[i - 1]] and tmp[SA[i] + k] == tmp[SA[i - 1] + k])
			// 第一二关键字都相同 
				x[SA[i]] = num;
			else x[SA[i]] = ++num;
		} m = num; 
	}
}
int main(){
	scanf("%s",s + 1);
	n = strlen(s + 1); m = 127;
	getSA();
	for(int i = 1; i <= n; i++) printf("%d ", SA[i]);
	return 0;
} 

————————————————
版权声明：本文为CSDN博主「lAWTYl」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/ID246783/article/details/123446790
