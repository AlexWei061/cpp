#include<bits/stdc++.h>
using namespace std;

string numStr;

bool isHuiwen(string num){
	bool is_huiwen = false;
	int len = num.size();
	for(int i = 0; i <= (len-1)/2; i++){
		if(num[i] != num[len-i-1]){
			return is_huiwen;
		}
	}
	is_huiwen = true;
	return is_huiwen;
}

int main(){
	freopen("repre.in", "r", stdin);
	freopen("repre.out", "w", stdout);
	cin >> numStr;
	int len = numStr.size();
	bool ans = false;
	if(isHuiwen(numStr) == true){
		ans = true;
	}
	else if(numStr[len-1] == '0'){
		while(numStr[len-1] == '0'){
			numStr = numStr.erase(len-1, 1);
			len--;
			if(isHuiwen(numStr) == true){
				ans = true;
				break;
			}
		}
	}
	ans ? printf("Yes") : printf("No");
	return 0;
}
