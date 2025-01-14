#include<bits/stdc++.h>
using namespace std;

int T = 0;

int main(){
	cin >> T;
	while(T--){
		int n = 0; string s;
		cin >> n >> s;
		int l = 0, r = n - 1;
		while(s[l] == 's') l++;
		while(s[r] == 'p') r--;
		bool flag = 1;
		if(r == -1 or l == n) flag = 1;
		else{
	//		printf("l = %d r = %d\n", l, r);
			int idx1 = -1, idx2 = -1;
			for(int i = l; i <= r; i++)
				if(s[i] == 's') { idx1 = i; break; }              // idx1 : 第一个 's' 
			for(int i = r; i >= l; i--)
				if(s[i] == 'p') { idx2 = i; break; }              // idx2 : 最后于一个 'p' 
	//		printf("idx1 = %d idx2 = %d\n", idx1, idx2);
			if(idx1 == -1 or idx2 == -1) flag = 1;
			else{
				int len1 = r - idx1 + 1, len2 = idx2 - l + 1;
				for(int i = 1; i <= len1; i++)
					if(s[l + i - 1] == 'p') { flag = 0; break; }
				for(int i = 1; i <= len2; i++)
					if(s[r - i + 1] == 's') { flag = 0; break; }
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
