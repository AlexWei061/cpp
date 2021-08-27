#include<bits/stdc++.h>
using namespace std;

#define INFI 0x3f3f3f3f
#define MAXN 10010
#define MAXE MAXN * (MAXN - 1)

int tot = 0;                                           // 现在有 tot 条边
int first[MAXN] = { 0 };                               // first[node] = edg : 第 node 个节点的第一条边是 edg 
int   nxt[MAXE] = { 0 };                               // nxt[edg1] = edg2 : 第 edg1 条边的下一条边是 edg2
int    to[MAXE] = { 0 };                               // to[edg] = node : 第 edg 条边所连接到的节点是node
int value[MAXE] = { 0 };                               // value[edg] = v : 第 edg 条边的边权是 v

void add(int x, int y, int v){                         // x 到 y 有一条边, 边权为 v
    nxt[++tot] = first[x];
    first[x] = tot;
    to[tot] = y;
    value[tot] = v;
}

int main(){
    
	return 0;
}