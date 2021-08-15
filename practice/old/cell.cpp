#include<iostream>
#include<string.h>
using namespace std;

int n, m;
int ans = 0; 
int way[105][105];
char Map[105][105];
const int fx[5] = {0,-1,0,1, 0};
const int fy[5] = {0, 0,1,0,-1};

int dfs(int x, int y){
    for (int i = 1; i <= 4; i++){
        int nx = x + fx[i];
        int ny = y + fy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m){
            continue;
        }
        if (way[nx][ny] != 1 && Map[nx][ny] != '0'){
            way[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
}

int main(){
    freopen("cell.in","r",stdin);
    freopen("cell.out","w",stdout);
    printf("program started");
    scanf("%d%d\n",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%s",Map[i]+1);
    }
    memset(way,0,sizeof(way));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (Map[i][j] != '0' && way[i][j] != 1){
                way[i][j] = 1;
                ans++;
                dfs(i,j);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
