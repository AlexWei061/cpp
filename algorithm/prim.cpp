#include<iostream>
#include<cstring>
using namespace std;

//生成树:在一个有k个节点的无向连通图中，取其中v-1条边，并连接所有的节点，所得的子图成为原图的一棵生成树  

//最小生成树:在一个无向连通图中，各边权最小的一棵生成树

/*
最小生成树:Prim
 
	1.输入和初始化(d[0] = 0; d[i] = INF) 
	2.计算生成树 
		(1) 选一个未标记的点k,d[k]要最小
		(2)把k放入Va
		(3)修改d[]
	3.得到最小生成树T 
*/ 

/*
	Va[]:已经在生成树中的节点
	Vb[]:还没放进去的
	 d[]:当前i 在当前生成树中的点有连边的边长的最小值
   vst[]:点i是否在Va中 
*/ 

/*
输入格式
	输入n个节点和m条边 
	分m次输入x道y的边权 
*/ 

#define INF 65535
int    vst[505];
int      d[505];
int g[505][505];
int n, m, ans = 0;     //ans为边权和 

void read(){           //输入图 
	int x, y;          //坐标
	int    w;          //数值
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; i++){
		cin >> x >> y >> w;
		g[x][y] = g[y][x] = w;       //无向图 
	}
}

void prim(int v){          //算法开始 
	int mmin = INF;        //最小值
	int k;                 //当前节点
	memset(vst, 0, sizeof(vst));   //初始化此时Va没有任何元素
	//开始初始化d[]
	for(int i = 1; i <= n; i++){
		d[i] = INF; 
	} 
	d[1] = 0;
	//ans = 0;
	//选n个点
	for(int i = 0; i <= n; i++){
		mmin = INF; 
		//选最小的边权
		for(int j = 1; j < n; j++){
			if(vst[j] == 0 and d[j] < mmin){
				//小于当前最小且不在Va里
				mmin = d[j];
				k = j;                //更新当前最小 
			} 
		}
		vst[k] = 1;                   //标记道Va中
		ans += d[k];                  //边权和 更新
		//修改d[]
		for(int j = 1; j <= n; j++){
			if(vst[j] == 0 and d[j] > g[k][j]){
				//当前最小大于本身边权且此节点不在Va中 
				d[j] = g[k][j];       //更新最小 
		    }
		}
	}
}

int main(){
	read();
	prim(1);
	cout << ans << endl;
	return 0;
}
