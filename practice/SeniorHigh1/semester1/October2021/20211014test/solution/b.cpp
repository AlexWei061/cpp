#include<bits/stdc++.h>
using namespace std;
#define MAXN 505

int n = 0;
int mmap[MAXN][MAXN] = { 0 };
int cnt = 0;
int c = 0;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("\n");
		for(int j = 1; j <= n; j++){
			char temp;
			scanf("%c", &temp);
			if(temp == '#'){
				cnt++;
				mmap[i][j] = 1;
			}
		}
	}
	
	if(cnt == 0){
		printf("%d\n", -1);
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(mmap[j][i] == 0){
				c++; break;
			}
		}
	}
	
	int ans = 1 << 30;
	for(int i = 1; i <= n; i++){
		int x = 0; bool is = false;
		for(int j = 1; j <= n; j++){
			if(mmap[j][i]) is = true;
			if(!mmap[i][j]){
				x++;
			}
		}
		if(!is) x++;
		ans = min(x, ans);
	}
	
	printf("%d\n", ans + c);
	
	return 0;
}
