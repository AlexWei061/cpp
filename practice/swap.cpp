#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {1,-1,1,1,-1,-1,0,0},
dy[8] = {0,0,1,-1,1,-1,-1,1};
char mine_field[110][110];
int n,m;

bool isValid(int x,int y){
	if (x >= 1 && x <= n && y >= 1 && y <= m && mine_field[x][y] == '*' ){
		return true;
	}
	return false;
}


int Search(int x,int y){
	int ans = 0;
	for (int i=0;i<8;++i){
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (isValid(new_x,new_y) == true)
			ans ++;
	}
	return ans;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for (int j=1;j<=m;++j)
			cin>>mine_field[i][j];

	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			{
				if (mine_field[i][j] == '*')
					cout << '*';
				if (mine_field[i][j] == '?')
					cout << Search(i,j);
				if (j == m)
					cout << endl;
			}
	return 0;
}
