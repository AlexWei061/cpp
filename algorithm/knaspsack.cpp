#include<bits/stdc++.h>
using namespace std;

/*
Dynamic transfer equation :
    V[i, j] = max{V[i-1, j], V[i-1, j-w[i]] + p[i]}
*/


#define M 8
#define N 4

void kanspsack01(int v[N + 1][M + 1], int p[N + 1], int w[N + 1]){
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
    int p[N + 1] = { 0, 1, 2, 5, 6 };
    int w[N + 1] = { 0, 2, 3, 4, 5 };
    int v[N + 1][M + 1];
    kanspsack01(v, p, w);
    int i = N;
    int j = M;
    int bp = v[N][M];
    cout << "Include : ";
    while(i > 0 and j >= 0){
        if(v[i][j] == v[i - 1][j]){
            i--;
        }
        else{
            cout << i << "th object and "; 
            j -= w[i];
            i--;
        }
    }
    cout << "None" << endl << "The biggest p is : " << v[N][M] << endl;
    return 0;
}
