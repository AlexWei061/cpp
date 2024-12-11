#include<bits/stdc++.h>
using namespace std;

int T = 0;


int main(){
	cin >> T;
	while(T--){
		string s;
		int n = 0, m = 0, k = 0;
		cin >> n >> m >> k;
		cin >> s;
//		printf("len = %d\n", len);
//		cout << "S : " << s << endl;
		int cnt = 0, ans = 0;
		for(int i = 0; i < n; i++){
//			printf("  i = %d\n", i); 
			if(s[i] == '1') continue;
			cnt = 0;
			int beg = i;
			while(s[i] == '0') { cnt++, i++; }
//			printf("    cnt = %d\n", cnt);
//			cout << s << '\n';
			cnt -= (m - 1);
			if(cnt <= 0 ) continue;
			int temp = ceil((double)cnt / (double)(m + k - 1));
			ans += temp;
			for(int j = 1; j <= k; j++)
				if(beg + temp * (m - 1) + (temp - 1) * k + j - 1 > n) break;
				else s[beg + temp * (m - 1) + (temp - 1) * k + j - 1] = '1';
//			cout << s << endl;
		}
		cout << ans << endl;
	}
	return 0;
} 
