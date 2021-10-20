#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
#define INFI 1e20 + 7

int n = 0;
double disLis[MAXN] = { 0 }; 
double r;
double x, y;

double ans = INFI;
double dis;
bool chosen[MAXN] = { 0 };

void dfs(int x, double now){
	if(x > n){
		if(now >= dis) ans = min(now, ans);
		return;
	}
	chosen[x] = 1;
	dfs(x + 1, now + disLis[x]);
	chosen[x] = 0;
	dfs(x + 1, now);
}

int main(){
	freopen("gogogo.in", "r", stdin);
	freopen("gogogo.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lf", &disLis[i]);
	}
	scanf("%lf", &r);
	scanf("%lf%lf", &x, &y);
	dis = sqrt((x * x) + (y * y)) - r;
	//printf("%.3lf\n", dis);
	dfs(0, double(0));
	printf("%.3lf", ans);
	return 0;
}
