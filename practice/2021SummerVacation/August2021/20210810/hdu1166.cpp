#include<bits/stdc++.h>
using namespace std;

#define MAXN 50050

int t = 0;
int n = 0;
int tree[MAXN] = { 0 };

char str[MAXN];
int a, b;

int lowbit(int x){
     return x & (-x);
}

int update(int i, int x){
    while(i <= n){
        tree[i] += x;
        i += lowbit(i);
    }
}

int query(int m){
    int sum = 0;
    while(m > 0){
        sum += tree[m];
        m -= lowbit(m);
    }
    return sum;
}

int operation(char str[], int i, int j){
    if(str[0] == 'Q'){
        return query(j) - query(i-1);
    }
    else if(str[0] == 'A'){
        update(i, j);
    }
    else if(str[0] == 'S'){
        update(i, -j);
    }
    return -1;
}

int main(){
	freopen("a.out", "w", stdout);
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	memset(tree, 0, sizeof(tree));
        scanf("%d", &n);
        printf("Case %d:\n", i);
        for(int j = 1; j <= n; j++){
            int temp;
            scanf("%d", &temp);
            update(j, temp);
        }
        while(scanf("%s", str) and strcmp(str, "End")){
        	scanf("%d%d", &a, &b);
            int ans = operation(str, a, b);
            if(ans != -1){
                printf("%d\n", ans);
            }
		}
    }
    return 0;
}

/*

1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End

*/