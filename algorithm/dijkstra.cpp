#include<bits/stdc++.h>
using namespace std;

#define N     6
#define INFI  65535

void initialize(int gragh[][N + 1], int l[]){
    for(int k = 2; k <= N; k++){
        if(gragh[1][k] != 0){
            l[k] = gragh[1][k];
        }
        else{
            l[k] = INFI;
        }
    }
}

void dijkstra(int gragh[][N + 1], int l[], bool is_s[]){
    initialize(gragh, l);
    for(int i = 1; i <= N; i++){
        int mmin = 0;
        int minn = 65535;
        if(is_s[i] == false){
            if(minn > l[i]){
                mmin = i;
            }
        }
        for(int j = 1; j <= N; j++){
            if(gragh[mmin][j] != 0 and gragh[mmin][j] + l[mmin] < l[j]){
                l[j] = gragh[mmin][j] + l[mmin];
            }
        }
    }
}

int main(){
    int gragh[][N + 1] = 
    {
         /*0   1   2   3   4   5   6*/
    /*0*/{ 0,  0 , 0 , 0 , 0 , 0 , 0 },
    /*1*/{ 0,  0 , 50, 45, 10, 0 , 0 },
    /*2*/{ 0,  0 , 0 , 10, 15, 0 , 0 },
    /*3*/{ 0,  0 , 0 , 0 , 0 , 30, 0 },
    /*4*/{ 0,  10, 0 , 0 , 0 , 15, 0 },
    /*5*/{ 0,  0 , 20, 35, 0 , 0 , 0 },
    /*6*/{ 0,  0 , 0 , 0 , 0 , 3 , 0 }
    };

    int     l[N + 1] = { 0 };  /*0,0,50,infinity,10,infinity,infinity*/
    bool is_s[N + 1] = { false };
    dijkstra(gragh, l, is_s);
    for(int i = 1; i <= N; i++){
        cout << l[i] << " ";
    }
    cout << endl;
    return 0;
}
