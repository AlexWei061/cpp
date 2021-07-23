#include<bits/stdc++.h>
using namespace std;

int n = 0;
int q = 0;
int t, a, b;
int x = 0;                                 //操作二的次数

string s;
string sl, sr;                             //分别存储前半部分和后半部分

void process(int t, int a, int b){
	if(t == 1){
		if(x % 2 == 0){                    //前后交换了偶数次相当于没换

			if(a >= n and b >= n){         //a，b的位置在sr里
				a -= n;
				b -= n;
				swap(sr[a], sr[b]);
			}
			else if(a < n and b >= n){     //a在sl，b在sr
				b -= n;
				swap(sl[a], sr[b]);
			}
			else{                          //ab都在sl
				swap(sl[a], sl[b]);
			}
		}

		else{                              //交换了奇数次相当于换了一次
			if(a >= n and b >= n){         //a，b的位置在sr里
				a -= n;
				b -= n;
				swap(sl[a], sl[b]);
			}
			else if(a < n and b >= n){     //a在sl，b在sr
				b -= n;
				swap(sr[a], sl[b]);
			}
			else{                          //ab都在sl
				swap(sr[a], sr[b]);
			}
		}	
	}
	else{
		x++;
	}
}

int main(){                                //优化
	cin >> n >> s >> q;
	sl = s.substr(0, n);
	sr = s.substr(n, n);

	for(int i = 1; i <= q; i++){
		scanf("%d%d%d", &t, &a, &b);
		a--;                               //对应字符串的存储位置
		b--;
		process(t, a, b);
	}

	if(x % 2 == 0){
		cout << sl << sr << endl;
	}
	else{
		cout << sr << sl << endl;
	}

	return 0;
}

/*
会RE的代码
#include<bits/stdc++.h>
using namespace std;

int n = 0;
char S[400001];
int q = 0;
int t, a, b;

void process(int t, int a, int b){
	if(t == 1){
		swap(S[a], S[b]);
	}
	if(t == 2){
		for(int i = 1; i <= n; i++){
			swap(S[i], S[i+n]);
		}
	}
}

int main(){
	freopen("oper.in", "r", stdin);
	freopen("oper.out", "w", stdout);
	scanf("%d", &n);
	scanf("\n");
	for(int i = 1; i <= n; i++){
		scanf("%c", &S[i]);
	}
	for(int i = n+1; i <= 2*n; i++){
		scanf("%c", &S[i]);
	}
	
	scanf("%d", &q);
	
	for(int i = 1; i <= q; i++){
		scanf("%d%d%d", &t, &a, &b);
		process(t, a, b);
	}
	
	//process(2, 0, 0);
		
	for(int i = 1; i <= 2*n; i++){
		printf("%c", S[i]);
	}
	
	return 0;
}
*/