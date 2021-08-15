#include<bits/stdc++.h>
using namespace std;

/*
问题描述
罗老师被邀请参加一个舞会，是在城市，而罗老师当前所处的城市为,附近还有很多城市，有
些城市之间没有直接相连的路，有些城市之间有直接相连的路，这些路都是双向的，当然也可能有多
条。
现在给出直接相邻城市的路长度，罗老师想知道从城市到城市，最短多少距离。

输入格式
输入n和m，表示个城市和条路;
接下来行，每行， 表示城市与城市有长度为的路。

输出格式
输出到的最短路。如果到达不了，就输出-1。
*/

#define INFI 65535

int N = 0;
int M = 0;
int gragh[][2001] = { 0 };
int     l[2001] =   { 0 };
bool is_s[2001] =   { false };

void initialize(int gragh[][2001], int l[]){
    for(int k = 2; k <= N; k++){
        if(gragh[1][k] != 0){
            l[k] = gragh[1][k];
        }
        else{
            l[k] = INFI;
        }
    }
}

void dijkstra(int gragh[][2001], int l[], bool is_s[]){
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
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++){
		int a = 0;
		int b = 0;
		int c = 0;
		scanf("%d%d%d",&a, &b, &c);
		gragh[a][b] = c;
		gragh[b][a] = c;
	}
    dijkstra(gragh, l, is_s);
    if(l[N] == INFI){
    	printf("%d", -1);
	}else{
		printf("%d", l[N]);	
	}
    cout << endl;
    return 0;
}
