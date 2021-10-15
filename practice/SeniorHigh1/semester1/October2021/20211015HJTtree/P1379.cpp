#include<bits/stdc++.h>
using namespace std;

const int px[4] = { 1, 0, -1, 0 };
const int py[4] = { 0, 1, 0, -1 };

int n = 8;
char s[20];
int x = 0; int y = 0;                               // 0 的坐标 
string goal = "123804765";

int h(string current){                              // 现在位置和目标位置有几个位置是不同的 (评估函数) 
	int ans = 0;
	for(int i = 0; i < 9; i++){
		if(goal[i] != current[i] and goal[i] != 0) ans++;
	}
	return ans;
}  

struct Tnode{  
    int f, step;                                    // 当前评估函数的值和走的步数 
    string now;                                     // 当前排列 
	bool operator < (const Tnode &x) const {  
        return step + f > x.step + x.f;             // 以当前步数加上评估函数排序        
    }  
};

int ans = 0x7fffffff; 
priority_queue<Tnode> q;
map<string, int>  dis;
map<string, bool> way;

void bfs(char s[]){
	way[s] = 1; dis[s] = 0;
	q.push((Tnode){h(s), 0, s});                    // 起点入堆 
	while(!q.empty()){
		Tnode t = q.top(); q.pop();
		string cur = t.now;
		if(cur == "123804765"){
			printf("%d\n", t.step);
			exit(0);
		}
		int tx = 0; int ty = 0;
		for(int i = 0; i < 9; i++){                                    //  当前排列 0 的位置 
			if(cur[i] - '0' == 0){
				tx = i / 3 + 1; ty = i % 3 + 1; 
			}
		}
		int idx1 = (tx - 1) * 3 + ty - 1;                              // 在一维排列中的位置
		for(int i = 0; i < 4; i++){                                    // 扩展 
			int nx = tx + px[i]; int ny = ty + py[i];
			if(nx < 1 or nx > 3 or ny < 1 or ny > 3) continue;
			int idx2 = (nx - 1) * 3 + ny - 1;                          // 扩展之后的位置 
			swap(cur[idx1], cur[idx2]);
			if(!way[cur] or (way[cur] and (t.step + 1) < dis[cur])){
				dis[cur] = t.step + 1;
				q.push((Tnode){h(cur), t.step + 1, cur});
				way[cur] = 1;
			} 
			swap(cur[idx1], cur[idx2]);
		} 
	} 
}

int main(){
	scanf("%s", s);
	for(int i = 0; i < 9; i++){
		if(s[i] - '0' == 0){
			x = i / 3 + 1; y = i % 3 + 1;           // 0 的初始坐标 
		}
	}
	if(h(s) == 0){                                  // 初始状态及目标状态 ：直接返回 
		printf("%d\n", 0);
		return 0; 
	}
	while(!q.empty()) q.pop();
	bfs(s);                                         // 开始搜索 
	return 0;
}
