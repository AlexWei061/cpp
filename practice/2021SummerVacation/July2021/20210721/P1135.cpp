#include<bits/stdc++.h>
using namespace std;

int n = 0;
int a = 0;
int b = 0;
int ki[205] = { 0 };
int  f[205] = { 0 };

struct qNode{
	int x;
	int depth;
}q[1000];

int head = 0;
int tail = 0;

void expand(int x, int step){
	//向上
	int nx = x + ki[x];
	//printf("up nx = %d\n", nx);
	if(nx <= n and f[nx] != 1){
		q[tail].x = nx;
		q[tail].depth = step + 1;
		//printf("q[tail].x = %d q[tail].depth = %d\n", q[tail].x, q[tail].depth);
		tail++;
		f[nx] = 1;
	}
	
	//向下
	nx = x - ki[x];
	if(nx >= 1 and f[nx] != 1){
		q[tail].x = nx;
		q[tail].depth = step + 1;
		tail++;
		f[nx] = 1;
	} 
}

int bfs(int a){
	f[a] = 1;
	head = 1;
	tail = 1;
	q[tail].x = a;
	q[tail].depth = 1;
	tail++;
	while(head != tail){
		int i = q[head].x;
		int step = q[head].depth;
		//printf("i = %d step = %d\n", i, step);
		head++;
		if(i == b){
			return step-1;
		}
		else{
			expand(i, step);
		}
	}
	return -1;
}

int main(){
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 1; i <= n ; i++){
		scanf("%d", &ki[i]);
	}
	
	printf("%d", bfs(a));
	
	return 0;
}
