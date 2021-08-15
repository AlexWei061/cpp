#include<bits/stdc++.h>
using namespace std;

int T = 0;
string word;
int n = 0;

string processWord(string word, int n){
	int len = word.size();
	n = n % len;
	if(n == 0){
		return word;
	}
	int m = len - n;
	string subl = word.substr(0, m);
	string subr = word.substr(m, n);
	string newWord = subr + subl;
	return newWord;
}

int main(){
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		cin >> word >> n;
		string newStr = processWord(word, n);
		cout << newStr << endl;
	}
	return 0;
}
