#include<bits/stdc++.h>
using namespace std;

int c[][9] = 
{ 
       /*0  1  2  3  4  5  6  7  8*/
/*0*/  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/*1*/  { 0, 0, 2, 1, 3, 0, 0, 0, 0 },
/*2*/  { 0, 0, 0, 0, 0, 2, 3, 0, 0 },
/*3*/  { 0, 0, 0, 0, 0, 6, 7, 0, 0 },
/*4*/  { 0, 0, 0, 0, 0, 6, 8, 9, 0 },
/*5*/  { 0, 0, 0, 0, 0, 0, 0, 0, 6 },
/*6*/  { 0, 0, 0, 0, 0, 0, 0, 0, 4 },
/*7*/  { 0, 0, 0, 0, 0, 0, 0, 0, 5 },
/*8*/  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

int n = 8;
int s = 4;
int cost[9] = { 0 };
int    d[9] = { 0 };
int path[9] = { 0 };

int main(){
    for(int i = (n - 1); i >= 1; i--){
        int mmin = 65535;
        for(int k = (i + 1); k <= n; k++){
            if( c[i][k] != 0 and (c[i][k] + cost[k] < mmin) ){
                mmin = c[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = mmin;
    }
    path[1]     = 1;
    path[s] = n;
    for(int i = 2; i < s; i++){
        path[i] = d[path[i - 1]];
    }
    for(int k = 1; k <= s; k++){
        cout << path[k] << " --> ";
    }
    cout << endl << cost[1] << endl;
    return 0;
}
