#include<bits/stdc++.h>
using namespace std;

const int px[] = { 0, 0, 1, 0, -1 };
const int py[] = { 0, 1, 0, -1, 0 };

int n = 0;
int m = 0;
int mmap[505][505] = { 0 };

struct node{
    int x;
    int y;
};

queue<node> q;

void expand(int x, int y){
    for(int i = 1; i <= 4; i++){
        int nx = x + px[i];
        int ny = y + py[i];
        if(nx >= 0 and nx <= n+1 and ny >= 0 and ny <= m+1 and mmap[nx][ny] == 0){
            mmap[nx][ny] = 1;
            q.push((node){nx, ny});
        }
    }
}

void bfs(int x, int y){
    mmap[x][y] = 1;
    //printf("x = %d y = %d\n", x, y);
    q.push((node){x, y});
    while(!q.empty()){
        //printf("%d\n", 1);
        node t = q.front();
        //printf("t.x = %d t.y = %d\n", t.x, t.y);
        q.pop();
        expand(t.x, t.y);
    }
    return;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == '0'){
                mmap[i][j] = 0;
            }
            if(c == '*'){
                mmap[i][j] = 1;
            }
        }
    }

    bfs(0, 0);
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mmap[i][j] == 0){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    /*
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            printf("%d ", mmap[i][j]);
        }
        printf("\n");
    }
    */

    return 0;
}


/*

4 5
00000
00*00
0*0*0
00*00

*/