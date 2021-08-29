#include<bits/stdc++.h>
using namespace std;

#define MAXN 20020

int n = 0, m = 0;

struct Tword{
	string word;
	int page;
}words[MAXN];

/*

runtime complexity : O(mn) = 2 * 10^8 Òª³¬Ê± 

*/

int main(){
	freopen("scanwords.in", "r", stdin);
	freopen("scanwords.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		cin >> words[i].word >> words[i].page;
	}
	
	scanf("%d", &m);
	for(int i = 0; i <  m; i++){
		string temp;
		cin >> temp;
		for(int j = 0; j < n; j++){
			if(temp == words[j].word){
				printf("%d\n", words[j].page);
				break;
			}
		}
	}
	
	return 0;
}
