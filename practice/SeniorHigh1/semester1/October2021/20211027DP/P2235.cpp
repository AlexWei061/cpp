#include<bits/stdc++.h>
using namespace std;
#define BASE (int)1e8

int   m[1005] = { 0 };
int ans1[1005] = { 0 };
int ans2[1005] = { 0 };

inline void add(int a[], int x){                                   // 二进制加法 (在第 x 位加 1)
	while(a[x]) a[x++] = 0;
	a[x] = 1; a[0] = max(a[0], x);
}

void read(){                                                       // 转二进制 
	memset(m, 0, sizeof(m));
	memset(ans1, 0, sizeof(ans1));
	memset(ans2, 0, sizeof(ans2));
	char c = getchar();
	for(; !isdigit(c); c = getchar());
	for(; isdigit(c); c = getchar()){
		if(m[0] != 0){                                             // 处理进位 
			m[0] += 3;
			for(int i = m[0]; i >= 1; --i){
				m[i] = 0;
				if(i > 3 and m[i - 3]) add(m, i);
				if(i > 1 and m[i - 1]) add(m, i);
			}
		}
		switch(c){
			case '0' : break;
			case '1' : add(m, 1); break;                           // 0001
			case '2' : add(m, 2); break;                           // 0010
			case '3' : add(m, 1); add(m, 2); break;                // 0011
			case '4' : add(m, 3); break;                           // 0100
			case '5' : add(m, 3); add(m, 1); break;                // 0101
			case '6' : add(m, 3); add(m, 2); break;                // 0110
			case '7' : add(m, 3); add(m, 2); add(m, 1); break;     // 0111
			case '8' : add(m, 4); break;                           // 1000
			case '9' : add(m, 4); add(m, 1); break;                // 1001
		}
	}
}

bool isHuiwen(){                                                   // 判断二进制是否回文 
	int l = m[0] / 2 + 1, r = m[0] - l + 1;
	while(l <= m[0] and r >= 1){
		if(m[r] > m[l]) return true;
		if(m[r] < m[l]) return false;
		--r; ++l;
	}
	return true;
}

int main(){
	read();
	
	for(int i = 1; i < m[0]; ++i){ 
		int pos = (i - 1) / 2 + 1;
		add(ans1, pos);
	}
	for(int i = m[0] / 2 + 1, j = 1; i < m[0]; ++i, ++j){
		if(m[i])add(ans1, j);
	}
	if(isHuiwen()) add(ans1, 1);
	
	while(ans1[0]){
		int temp = ans1[ans1[0]--];
		for(int i = 1; i <= ans2[0]; ++i){
			ans2[i] = ans2[i] * 2 + temp;
			temp = ans2[i] / BASE;
			ans2[i] %= BASE;
		}
		while(temp){
			ans2[++ans2[0]] += temp;
			temp = ans2[ans2[0]] / BASE;
			ans2[ans2[0]] %= BASE;
		}
	}
	
	printf("%d", ans2[ans2[0]--]);
	while(ans2[0]){
		printf("%08d", ans2[ans2[0]--]);                             // 最高位补 0 
	}
	
	return 0;
}
