#include<bits/stdc++.h>
using namespace std;

struct Star{
	int x;
	int y;
};

int n = 0;
Star starlist[150010] = { 0 };
int levellist[150010] = { 0 };

int main(){
	freopen("starmap.in", "r", stdin);
	freopen("starmap.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &starlist[i].x, &starlist[i].y);		
	}
	
	for(int i = 1; i <= n; i++){
		int leveli = 0;
		for(int j = 1; j <= n; j++){
			if(starlist[j].x <= starlist[i].x and starlist[j].y <= starlist[i].y){
				leveli++;
			}
		}
		//printf("level%d = %d\n", i, leveli);
		levellist[leveli-1]++;
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", levellist[i]);		
	}
	
	return 0;
}


/*
5
1 1 
5 1
7 1
3 3
5 5
*/
