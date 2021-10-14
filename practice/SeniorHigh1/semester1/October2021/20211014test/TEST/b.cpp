#include<bits/stdc++.h>
using namespace std;
#define MAXN 505

int n = 0;
struct Tnode{
	int b[MAXN][MAXN];
	int depth;
}st;

bool isFull(Tnode a){
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(a.b[i][j]) cnt++;
		
	if(cnt == n * n) return true;
	else return false;
}

Tnode trans(int i, int j, Tnode a){
	Tnode c;
	c.depth = a.depth + 1;
	for(int e = 1; e <= n; e++)
		for(int f = 1; f <= n; f++)
			c.b[e][f] = a.b[e][f];
	
	for(int k = 1; k <= n; k++){
		c.b[k][j] = a.b[i][k];
	}
	return c;
}

queue<Tnode> q;
int bfs(Tnode st){
	q.push(st);
	while(!q.empty()){
		Tnode a = q.front(); q.pop();
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(a.b[i][j]) cnt++;
			
		if(cnt == n * n) return a.depth;
		else{
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					Tnode c = trans(i, j, a);
					q.push(c);
				}
			}
		}
	}
}

int main(){
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &n);
	int cnt = 0;
	st.depth = 0;
	for(int i = 1; i <= n; i++){
		scanf("\n");
		for(int j = 1; j <= n; j++){
			char temp;
			scanf("%c", &temp);
			if(temp == '#')
				st.b[i][j] = 1;
			else{
				cnt++;
				st.b[i][j] = 0;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			printf("%d ", st.b[i][j]);
		printf("\n");
	}
	
	
	if(cnt == n * n){
		printf("%d\n", -1);
		return 0;
	}
	else if(cnt == 0){
		printf("%d\n", 0);
		return 0;
	}
	else{
		int ans = bfs(st);
		printf("%d\n", ans);
	}
	return 0;
}
