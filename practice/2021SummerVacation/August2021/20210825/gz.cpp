#include<bits/stdc++.h>
using namespace std;

#define MAXN (int)1e6 + 100
#define INFI (long long)1e18 + 1000

int n = 0;
int m = 0;

int a[MAXN] = { 0 };

bool is_enough(long long v){                // 每个袋子体积为 v 能否装完
	long long v0 = v; int m0 = m;
	for(int i = 1; i <= n; i++){
		if(a[i] <= v0){
			v0 -= a[i];
		}
		else{
            while(a[i] > v0){
			    m0 -= 1;
			    v0 = v;
                if(m0 < 0){
                    return false;
                }
            }
		}
	}
    return true;
}

int main(){
	scanf("%d%d", &n, &m);
	long long L = 0; long long R = INFI;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] > L){
            L = a[i];
        }
	}

	while(L < R){
		long long mid = (L + R) >> 1;
		if(is_enough(mid)){
			R = mid;
		}
		else{
			L = mid + 1;
		}
	}

	printf("%lld\n", L);
	return 0;
}

/*

果园里有 n 课果树, 每颗果树有一个编号 i 每颗果树果子的体积为 ai.
小明拿来 m 个袋子把这些果子都装进袋子里. 每个袋子体积为 v

如果这棵树的果子能全部装进袋子, 那就装进去. 如果不能, 就关上袋子, 打开下一个袋子继续装.

小明希望在能装下所有果子的情况下 v 尽量小

3 3
1 2 3

*/