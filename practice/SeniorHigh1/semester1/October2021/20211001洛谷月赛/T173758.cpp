#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int px[5] = { 0, 1, 0, -1,  0 };
const int py[5] = { 0, 0, 1,  0, -1 };

struct Tnode{
	ll x; ll y;
	ll depth;
	int lsd;                       // 上一次的方向 1 : down 2 : right 3 : up 4 : left
};

int n = 0;

map<pair<ll, ll> , int> way;

bool isV(ll x, ll y){            // 判断是否走过
	//return (way.find(make_pair(x, y)) != way.end() or );
	if(way.find(make_pair(x, y)) == way.end()){
		return false;
	}
	else if(way[make_pair(x, y)] >= 4){
		return true;
	}
	else{
		return false;
	}
}

void vis(ll x, ll y){            // 标记走过
	//way.insert(pair<pair<ll, ll> , bool>(make_pair(x, y), 1));
	if(way.find(make_pair(x, y)) != way.end()){
		way.insert(pair<pair<ll, ll> , int>(make_pair(x, y), 1));
	}
	else{
		way[make_pair(x, y)]++;
	}
}

queue<Tnode> q;
ll bfs(Tnode st, Tnode et){
	q = queue<Tnode>();
	way.clear();
	//printf("st.x = %lld st.y = %lld\n", st.x, st.y);
	q.push(st);
	while(!q.empty()){
		Tnode node = q.front();
		q.pop();
		//printf("x = %lld y = %lld depth = %lld\n", node.x, node.y, node.depth);
		for(int i = 1; i <= 4; i++){
			ll nx = node.x + px[i]; ll ny = node.y + py[i]; ll ndepth = node.depth + 1;
			//printf("	nx = %lld ny = %lld ndepth = %lld lsd = %d\n", nx, ny, node.depth + 1, i);
			Tnode n = {nx, ny, ndepth, i};
			if(n.lsd != node.lsd and !isV(n.x, n.y)){
				//printf("		in : x = %lld y = %lld depth = %lld lsd = %d\n", n.x, n.y, n.depth, n.lsd);
				q.push(n);
				vis(n.x, n.y);
				if(n.x == et.x and n.y == et.y){
					return n.depth;
				}
			}
		}
	}
	return -1;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		ll sx = 0; ll sy = 0;
		ll ex = 0; ll ey = 0;
		scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
		printf("%lld\n", bfs(Tnode{sx, sy, 0, 0}, Tnode{ex, ey, 0, 0}));
	}
	return 0;
}