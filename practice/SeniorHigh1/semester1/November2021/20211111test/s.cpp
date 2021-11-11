#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAXN 2020

int n = 0;
int a[MAXN][MAXN] = { 0 };

int main(){
	scanf("%d", &n);
	if(n % 2 == 1){
		for(int i = 1; i <= n * n; i++){
			if(i % n == 0) cout << i << endl;
			else cout << i << ' ';
		}
	}
	else{
		if(n == 2) cout << -1 << endl;
		else{
			if(n % 4 == 0){
				for(int i = 1; i <= n; i++)
					for(int j = 1; j <= n; j++)
						a[i][n-j+1] = i * n - j + 1;
				for(int i = 1; i <= n / 2; i++){
					swap(a[2*i-1][n/2+1], a[2*i][1]);
				}
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++)
						cout << a[i][j] << ' ';
					cout << endl;
				}
			}
			else{
				for(int i = 1; i <= n; i++)
					for(int j = 1; j <= n; j++)
						a[i][n-j+1] = i * n - j + 1;
				for(int i = 1; i < n / 2; i++){
					swap(a[2*i-1][n/2+1], a[2*i][1]);
				}
				swap(a[n-1][n/2+2], a[n][2]);
				swap(a[1][2], a[1][n/2+2]);
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++)
						cout << a[i][j] << ' ';
					cout << endl;
				}
			}
		}
	}
	return 0;
}
