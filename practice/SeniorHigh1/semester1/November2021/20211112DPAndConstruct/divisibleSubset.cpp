#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
#define MAXA 100100

int n = 0;
int a[MAXN] = { 0 };
int s[MAXN] = { 0 };

struct Tnode{
	int idx[10];
	int cnt1, cnt2;
};
Tnode tong[MAXN] = { 0 };

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 0; i <= n; i++){
		s[i] = (s[i-1] + a[i]) % n;
		tong[s[i]].cnt1++; tong[s[i]].idx[++tong[s[i]].cnt2] = i; 
	}
	for(int i = 0; i <= n; i++)
		if(tong[s[i]].cnt1 > 1){
			cout << tong[s[i]].idx[1] + 1 << ' ' << tong[s[i]].idx[2] << endl;
			return 0;
		}
	return 0;
}