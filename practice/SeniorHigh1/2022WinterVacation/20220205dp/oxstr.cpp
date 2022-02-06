#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100

int n = 0;

int main(){
    cin >> n;
    double p; double Ef = 0;
    double Ex = 0; double Exx = 0;
    for(int i = 1; i <= n; i++){
        cin >> p;
        Ef += (3 * Exx + 3 * Ex + 1) * p;
        Exx = (Exx + 2 * Ex + 1) * p;
        Ex = (Ex + 1) * p;
    }
    printf("%lf\n", Ef);
    return 0;
}