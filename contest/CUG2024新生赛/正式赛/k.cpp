#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001000

int n = 0, m = 0, k = 0;
struct Tnode{
	int val, idx;
	bool operator < (const Tnode &rhs) const { return val > rhs.val; }
}p[MAXN];

int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++){
		cin >> p[i].val; p[i].idx = i; }
	sort(p + 1, p + k + 1);
	int l = 1, r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(k > mid * (m - 1) + n) l = mid + 1;
		else r = mid;
	}
	int poin = 1;
	for(int i = 1; i <= n - l; i++){
		for(int j = 1; j <= m; j++)
			if(i == poin) cout << p[poin++].idx << ' ';
			else cout << 0 << ' ';
		puts("");
	}
	int temp = 1;
	for(int i = 1; i <= l; i++){
		for(int j = 1; j <= m; j++)
			if(poin <= k){
				cout << p[k - (temp++) + 1].idx << ' '; poin++; }
			else cout << 0 << ' ';
		puts("");
	}
	return 0;
} 
