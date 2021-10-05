#include<bits/stdc++.h>
using namespace std;

int n, q, l[105], r[105], a[105];
int f[105][105] = { 0 };
int Map[105][105];

void MakeTree(int v){
	for(int i = 1; i <= n; i++)
		if(Map[v][i] >= 0){
			l[v] = i;
			a[i] = Map[v][i];
			Map[v][i] = -1;
			Map[i][v] = -1;
			MakeTree(i);
			break;
		}
		
	for(int i = 1; i <= n; i++)
		if(Map[v][i] >= 0){
			r[v] = i;
			a[i] = Map[v][i];
			Map[v][i] = -1;
			Map[i][v] = -1;
			MakeTree(i);
			break;
		}
}

int DP(int i,int j){
	if(j == 0) return 0;
	if((l[i] == 0) && (r[i] == 0)) return a[i];
	if(f[i][j] > 0) return f[i][j];
	for(int k = 0; k <= j - 1; k++)
		f[i][j] = max(f[i][j], DP(l[i], k) + DP(r[i], j - k - 1) + a[i]);
	return f[i][j];
}

int main(){
	int x, y, z;
	cin >> n >> q;
	q++;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) 
			Map[i][j] = -1; 
	for(int i = 1; i <= n - 1; i++){
		cin >> x >> y >> z;
		Map[x][y] = z;
		Map[y][x] = z;
	}
	MakeTree(1);
	cout << DP(1, q) << endl;
	return 0;
}