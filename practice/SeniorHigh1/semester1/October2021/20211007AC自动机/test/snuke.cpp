#include<bits/stdc++.h>
using namespace std;

int H = 0; int W = 0;

int main(){
	freopen("snuke.in", "r", stdin);
	freopen("snuke.out", "w", stdout);
	
	scanf("%d%d", &H, &W);
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			char str[10];
			scanf("%s", &str);
			if(str[0] == 's' and str[1] == 'n' and str[2] == 'u' and str[3] == 'k' and str[4] == 'e'){
				printf("%c%d", 'A' + j - 1, i);
				return 0;
			}	
		}
	}

	return 0;
}