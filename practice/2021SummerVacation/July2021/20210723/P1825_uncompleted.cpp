#include<bits/stdc++.h>
using namespace std;

const int px[] = { 0, 0, 1, 0, -1 };
const int py[] = { 0, 1, 0, -1, 0 };

int n = 0;
int m = 0;
int     way[305][305] = { 0 };
char   mmap[305][305];
char  usual[305][305];
char portal[305][305];

int sx, sy;
int dx, dy;

struct qwq{
    int myx1, myy1;
    int myx2, myy2;
    int flag;
};
map<char, qwq> cs;

struct node{
    int x;
    int y;
    int depth;
};
queue<node> bfs;

void bbfs(){
    bfs.push((node){sx, sy, 0});
    while(!bfs.empty()){
        node t = bfs.front();
        for(int i = 1; i <= 4; i++){
            int nx = t.x + px[i];
            int ny = t.y + py[i];
            if(mmap[nx][ny] == '='){
                printf("%d\n", t.depth+1);
                return;
            }
            else if(mmap[nx][ny] >= 'A' and mmap[nx][ny] <= 'Z' and portal[nx][ny] != '#'){
                if(cs[mmap[nx][ny]].flag == 1){
                    portal[nx][ny] = '#';
                    bfs.push((node){nx, ny, t.depth+1});
                    continue;
                }
                portal[nx][ny] = '#';
                char flag2 = mmap[nx][ny];
                if(cs[flag2].myx1 == ny and cs[flag2].myy1 == ny){
                    nx = cs[flag2].myx2;
                    ny = cs[flag2].myy2;
                }
                else{
                    nx = cs[flag2].myx1;
                    ny = cs[flag2].myy1;
                }
                bfs.push((node){nx, ny, t.depth+1});
            }
            else if(mmap[nx][ny] == '.' and usual[nx][ny] == '.'){
                usual[nx][ny] = '#';
                bfs.push((node){nx, ny, t.depth+1});
            }
        }
        bfs.pop();
    }
    return;
}

int main(){
    scanf("%d%d", &n, &m);
    //scanf("\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mmap[i][j];
            usual[i][j] = mmap[i][j];
            portal[i][j] = mmap[i][j];
            if(mmap[i][j] >= 'A' and mmap[i][j] <= 'Z'){
                if(cs[mmap[i][j]].flag == 0){
                    cs[mmap[i][j]].myx1 = i;
                    cs[mmap[i][j]].myy1 = j;
                    cs[mmap[i][j]].flag++;
                }
                else{
                    cs[mmap[i][j]].myx2 = i;
                    cs[mmap[i][j]].myy2 = j;
                    cs[mmap[i][j]].flag++;
                }
                portal[i][j] = mmap[i][j];
            }
            else if(mmap[i][j] == '@'){
                sx = i;
                sy = j;
            }
        }
    }

    bbfs();

    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%c", mmap[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}