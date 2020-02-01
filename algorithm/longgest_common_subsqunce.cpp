#include<bits/stdc++.h>
using namespace std;

void LCS(int lcs[][100],char a[], char b[], int m, int n){
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 or j == 0){
                lcs[i][j] = 0;
            }
            else if(a[i] == b[j]){
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else{
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
}

int main(){
    string str2 = "longest";
    char a[] = {'s', 't', 'o', 'n', 'e'          };
    char b[] = {'l', 'o', 'n', 'g', 'e', 's', 't'};
    int m = sizeof(a) / sizeof(char);
    //cout << m << endl;
    int n = sizeof(b) / sizeof(char);
    //cout << n << endl;
    int lcs[100][100] = { 0 };
    LCS(lcs, a, b, m, n);
    /*
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }
    */
   cout << lcs[m][n] << endl;
    return 0;
}
