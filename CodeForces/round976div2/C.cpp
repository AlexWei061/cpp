#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()
#define MAXN 101

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x;
}

int t = 0;
int b = 0, c = 0, d = 0;
struct Tnum{
	int val, cnt;
	bool arr[MAXN];
	Tnum() { val = cnt = 0; memset(arr, 0, sizeof(arr)); }
};

Tnum to(int val){
	Tnum ans;
	ans.val = val;
	while(val) ans.arr[++ans.cnt] = val % 2, val /= 2;
	int temp[MAXN];
//	for(int i = 1; i <= ans.cnt; i++) temp[ans.cnt - i + 1] = ans.arr[i];
//	for(int i = 1; i <= ans.cnt; i++) ans.arr[i] = temp[i];
	return ans;
}
void print(Tnum a) { for(int i = 1; i <= a.cnt; i++) cout << a.arr[i]; puts(""); }

int a[MAXN] = { 0 };
int solve(int b, int c, int d){
	Tnum bb = to(b), cc = to(c), dd = to(d);
//	print(bb); print(cc); print(dd);
	int n = max(max(bb.cnt, cc.cnt), dd.cnt);
	for(int i = 1; i <= n; i++){
		if((0 | bb.arr[i]) - (0 & cc.arr[i]) == dd.arr[i]) a[i] = 0;
		else if((1 | bb.arr[i]) - (1 & cc.arr[i]) == dd.arr[i]) a[i] = 1;
		else return -1;
	}
	int ans = 0;
//	for(int i = 1; i <= n; i++) cout << a[i]; puts("");
	for(int i = 1; i <= n; i++)
		if(a[i]) ans += pow(2, i - 1);
	return ans;
}

void clean(){
	memset(a, 0, sizeof(a));
}

signed main(){
	t = in;
	while(t--){
		b = in, c = in, d = in;
		cout << solve(b, c, d) << '\n';
		clean();
	}
	return 0;
} 
