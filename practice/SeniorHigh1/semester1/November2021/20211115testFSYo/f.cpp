#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 2020
#define endl '\n'

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int n = 0;
int a[MAXN] = { 0 };
int b[MAXN] = { 0 };
unordered_map<int , int> s;
int cnt = 0;
int ans[MAXN] = { 0 };
bool comp(int x, int y){
	return x < y;
}

void check(int x){
	unordered_map <int, int> c;
	for(int i = 1; i <= n; i++) c[b[i]]++;
	for(int i = 1; i <= n; i++){
		if(!c[a[i] ^ x]) return;
		c[a[i] ^ x]--;
	}
	ans[++cnt] = x;
}

int main(){
	n = in;
	for(int i = 1; i <= n; i++) a[i] = in;
	for(int i = 1; i <= n; i++) b[i] = in;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			s[a[i] ^ b[j]]++;
	for(auto x : s)
		if(x.second >= n) check(x.first);
	sort(ans+1, ans+cnt+1, comp);
	cout << cnt << endl;
	for(int i = 1; i <= cnt; i++)
		cout << ans[i] << ' ';
	puts("");
	return 0;
}