#include<bits/stdc++.h>
using namespace std;

#define N     7
#define INFI  65535

void initialize(int gragh[][N + 1], int l[]){
    for(int i = 1; i <= N; i++){
        if(i == 1){
            l[i] = 0;
        }
        else{
            l[i] = INFI;
        }
    }
}

void bellman_ford(int gragh[][N + 1], int l[]){
    initialize(gragh, l);
    for(int k = 1; k < N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(gragh[i][j] != 0 and gragh[i][j] + l[i] < l[j]){
                    l[j] = gragh[i][j] + l[i];
                }
            }
        }
    }
}

int main(){
    int gragh[][N + 1] = 
    {
        /*0, 1, 2, 3, 4, 5, 6, 7*/
/*0*/   { 0, 0, 0, 0, 0, 0, 0, 0 },
/*1*/   { 0, 0, 6, 5, 5, 0, 0, 0 },
/*2*/   { 0, 0, 0, 0, 0,-1, 0, 0 },
/*3*/   { 0, 0,-2, 0, 0, 1, 0, 0 },
/*4*/   { 0, 0, 0,-2, 0, 0,-1, 0 },
/*5*/   { 0, 0, 0, 0, 0, 0, 0, 3 },
/*6*/   { 0, 0, 0, 0, 0, 0, 0, 3 },
/*7*/   { 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    int l[N + 1];
    bellman_ford(gragh, l);
    for(int i = 1; i <= N; i++){
        cout << i << " --> " << l[i] << endl;
    }
    return 0;
}
