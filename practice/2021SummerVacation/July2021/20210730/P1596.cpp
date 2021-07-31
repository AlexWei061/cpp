#include<bits/stdc++.h>
using namespace std;

const int px[10] = { 0, 1, 0, -1,  0, 1,  1, -1, -1 };
const int py[10] = { 0, 0, 1,  0, -1, 1, -1,  1, -1 };

int ans = 0;
int n = 0;
int m = 0;
int mmap[105][105] = { 0 };

struct Node{
    int x;
    int y;
}q[100001];
int head = 0;
int tail = 0;

void bfs(int x, int y){
    mmap[x][y] = 1;
    head = tail = 1;
    q[tail++] = (Node){x, y};
    while(head != tail){
        Node t = q[head++];
        for(int i = 1; i <= 8; i++){
            int nx = t.x + px[i];
            int ny = t.y + py[i];
            if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and mmap[nx][ny] == 1){
                q[tail++] = (Node){nx, ny};
                mmap[nx][ny] = 0;
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == 'W'){
                mmap[i][j] = 1;
            }
            if(c == '.'){
                mmap[i][j] = 0;
            }
        }
    }

    //bfs(1, 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mmap[i][j] == 1){
                bfs(i, j);
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d", mmap[i][j]);
        }
        printf("\n");
    }
    */

    return 0;
}

/*

[题目描述]
Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M
(1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.').
Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them,
where a square is considered adjacent to all eight of its neighbors. Given a diagram of Farmer John's field, determine how many ponds he has.

[输入格式]
Line 1: Two space-separated integers: N and M * Lines 2..N+1: M characters per line representing one row of Farmer John's field.
Each character is either 'W' or '.'. The characters do not have spaces between them.

[输出格式]
Line 1: The number of ponds in Farmer John's field.

[输入输出样例]
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

3

*/