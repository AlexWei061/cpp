#include<bits/stdc++.h>
using namespace std;

/*
问题描述
Rainie要去购物，Rainie对每一个商品（每个商品只有一个）都有不同的高兴程度（高兴程度能够叠
加），但是有可能使她更快乐的商品会花费更多的钱，而她能够花的钱只有，Rainie就很想你帮助
她计算一下买哪些东西她才能最高兴呢。

输入格式
第一行两个整数，包含物品个数，总共的钱；
第二行至第行，每行包含两个整数，商品 的价格 ，以及商品高兴度 。

输出格式
输出有两行：
第一行包含一个整数，即Rainie最大能获得的高兴度；
第二行从小到大输出使得Rainie获得最大高兴度的商品编号（商品编号为输入时的顺序）。
*/

int M = 0;
int N = 0;
int p[1001] = { 0 };
int w[1001] = { 0 };
int v[1001][10001] = { 0 };

void kanspsack01(int v[][10001], int p[], int w[]){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i == 0 or j == 0){
                v[i][j] = 0;
            }
            else if(w[i] <= j){
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
            else{
                v[i][j] = v[i - 1][j];
            }
        }
    }
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d%d", &w[i + 1], &p[i + 1]);
	}
    kanspsack01(v, p, w);
    int i = N;
    int j = M;
    int bp = v[N][M];
    cout << endl << v[N][M] << endl;
    //int temp[100] = { 0 }; 
    //int qwe = 0;
    priority_queue <int, vector<int>,greater<int> > temp;
	while(i > 0 and j >= 0){
        if(v[i][j] == v[i - 1][j]){
            i--;
        }
        else{
            //cout << i << " "; 
            temp.push(i);
            j -= w[i];
            i--;
        }
    }
    /*
    for(int i = 100; i >= 0; i--){
    	if(temp[i] != 0){
    		cout << temp[i] << " ";
		}
	}
	*/ 
	while(!temp.empty()){
		printf("%d%c", temp.top(), ' ');
		temp.pop();
	}
    return 0;
}
