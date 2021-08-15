#include<bits/stdc++.h>
using namespace std;

 int Plus(int a, int b) {
	int ans = 0;                                    //答案 
	int al[10001] = { 0 };                          //利用数组把数字a装起来 
	int bl[10001] = { 0 };                          //利用数组把数字a装起来 
	int cl[10001] = { 0 };                          //装答案的数组 
	int j = 0; 
	int k = 0;
	for (int i = 1; i < a; i *= 10) {               //把a存入al中 
		al[j] = (a / i) % 10;
		//cout << al[j] << ' ';
		j++;
	}
	for (int i = 1; i < b; i *= 10) {               //把b存入bl中 
		bl[k] = (b / i) % 10;
		//cout << bl[k] << ' ';
		k++;
	}
	int h = 0;
	while(al[h] != 0 || bl[h] != 0){                //计算答案数组 
		cl[h] = al[h] + bl[h];
		if (cl[h] >= 10) {                          //满十进一 
			cl[h] -= 10;
			cl[h + 1] += 1;
		}
		//cout << cl[h] << ' ';
		h++;
	 }
	int i = h;
	do {                                            //把数组转成数字 
		ans = ans * 10 + cl[i];
		i--;
	}while(cl[i] != 0);
	
	return ans;                                     //返回答案 
}

int a = 0;
int b = 0;

int main(){
	cin >> a >> b;
	int c = Plus(a,b);
	cout << c;
}
