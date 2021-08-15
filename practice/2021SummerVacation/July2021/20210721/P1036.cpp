#include<bits/stdc++.h>
using namespace std;

int n = 0;
int k = 0;
int numlist[30] = { 0 };
long long ans = 0;

int a[30] = { 0 };
bool is_used[30];

bool isPrime(int x){
    if(1 == x){
        return false;
    }
    for(int i = 2; i <= sqrt(x); i++){
        if (x%i == 0){
            return false;
        }
    }
    return true;
}

void print(){
	for(int i = 1; i <= k; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

long long calcFac(int num){
	long long fac = 1;
	for(int i = 1; i <= num; i++){
		fac *= i;
	}
	return fac;
}

void calcAns(){
	int num = 0;
	for(int i = 1; i <= k; i++){
		num += a[i];
	}
	if(isPrime(num)){
		ans++;
	}
	//printf("%d\n", num);
}

void dfs(int depth){
	if(depth == k){
		//print();
		calcAns();
		return;
	}
	for(int i = 1; i <= n; i++){
		if(is_used[i] == false){
			is_used[i] = true;
			a[depth+1] = numlist[i];
			dfs(depth+1);
			is_used[i] = false;
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &numlist[i]);
	}
	
	dfs(0);
	
	printf("%d", ans/calcFac(k));
	
	return 0;
}
