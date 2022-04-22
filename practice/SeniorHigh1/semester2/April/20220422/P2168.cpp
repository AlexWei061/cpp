#include<bits/stdc++.h>
using namespace std;
#define int long long
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

struct Tnode{
	int w; int h;
	Tnode() { w = 0; h = 0; }
	Tnode(int w, int h) : w(w), h(h) {}
	bool operator < (const Tnode &rhs) const {
		return w == rhs.w ? (h > rhs.h) : (w > rhs.w);
	}
};

int n = 0; int k = 0;
priority_queue<Tnode> q;

signed main(){
	n = in; k = in; int h = 0; int ans = 0;
	for(int i = 1; i <= n; i++) { int x = in; q.push(Tnode(x, 1)); }
	while((q.size() - 1) % (k - 1) != 0) q.push(Tnode(0, 1));
	while(q.size() >= k){
		int temp = 0;
		for(int i = 1; i <= k; i++){
			Tnode x = q.top(); q.pop();
			h = max(h, x.h); temp += x.w;
		}
		q.push(Tnode(temp, h + 1)); ans += temp;
	}
	cout << ans << '\n' << h << '\n';
	return 0;
}