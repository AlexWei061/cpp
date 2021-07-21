#include<bits/stdc++.h>
using namespace std;

const int chairHeight         =  30  ;
int       taoHeight           =   0  ;
int       appleHeightList[11] = { 0 };

int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	scanf("%d", &taoHeight);
	for(int i = 1; i <= 10; i++){
		scanf("%d", &appleHeightList[i]);
	}
	
	int numOfApple = 0;
	int height = taoHeight + chairHeight;
	
	for(int i = 1; i <= 10; i++){
		if(height >= appleHeightList[i]){
			numOfApple++;
		}
	}
	printf("%d", numOfApple);
	
	return 0;
}
