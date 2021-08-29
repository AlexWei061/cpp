#include<bits/stdc++.h>
using namespace std;

struct T{
	string word;
	int page;
}a[20002];

string st;
int n = 0, m = 0;

bool comp(T a, T b){
	return a.word < b.word;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		cin >> a[i].word >> a[i].page;
	}

	sort(a+1, a+n+1, comp);

	scanf("%d", &m);
	int L = 0, R = 0;
	while(m--){
		cin >> st;
		L = 1; R = n;
		do{
			int mid = (L + R) >> 1;
			if(st == a[mid].word){
				printf("%d\n", a[mid].page);
				break;
			}
			if(st > a[mid].word){
				L = mid + 1;
			}
			if(st < a[mid].word){
				R = mid - 1;
			}
		}while(L <= R);
	}
	return 0;
}