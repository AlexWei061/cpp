#include<bits/stdc++.h>
using namespace std;
#define in read()
#define MAXN 5050

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0'; c = getchar();
	}
	return x;
}

int T = 0; int n = 0;
bitset<MAXN> b[MAXN], e, o;

int main(){
	T = in;
	while(T--){
		n = in; bool flag = 0;
		for(int i = 1; i <= n; i++){
			b[i].reset(); int k = in;
			while(k--) b[i][in] = 1;
		}
		for(int i = 1; i <= n and (!flag); i++)
			for(int j = 1; j <= n; j++){
				o = (b[i] | b[j]);
				if(((b[i] & b[j]) != e) and ((b[i] != o) and (b[j] != o))){
					puts("YES"); cout << i << ' ' << j << '\n'; flag = 1; break;
				}
			}
		if(!flag) puts("NO");
	}
	return 0;
}