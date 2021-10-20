#include<bits/stdc++.h>
using namespace std;

int npos, n, p, FLAG, fflag, ndir, num, stp, tim, t[1005], st[1005], ed[1005], dir[1005], vis[1005], in[1005];

int getout() {
	int res = 0;
	for(int i = 1; i <= n; i++)
		if(in[i] && ed[i] == npos)  in[i] = 0, ++res;
	if(res) {
		if(!stp)  stp = 1, printf("%02d:%02d The elevator stops at floor %d.\n", tim / 60, tim % 60, npos);
		printf("%02d:%02d %d people leave the elevator.\n", tim / 60, tim % 60, res);
		num -= res;
		return 1;
	}
	return 0;
}

int getin() {
	int res = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i])  continue;
		if(t[i] > tim)  break;
		if(st[i] == npos && dir[i] == ndir && num + 1 <= p)  vis[i] = in[i] = 1, ++num, ++res;
	}
	if(res) {
		if(!stp)  stp = 1, printf("%02d:%02d The elevator stops at floor %d.\n", tim / 60, tim % 60, npos);
		printf("%02d:%02d %d people enter the elevator.\n", tim / 60, tim % 60, res);
		return 1;
	}
	return 0;
}

void Go() {
	if(stp) {
		if(ndir == 1)  printf("%02d:%02d The elevator starts to move up from floor %d.\n", tim / 60, tim % 60, npos);
		if(ndir == -1)  printf("%02d:%02d The elevator starts to move down from floor %d.\n", tim / 60, tim % 60, npos);
	}
	stp = 0;
	npos = npos + ndir;
}

int canchangedir() {
	for(int i = 1; i <= n; i++) {
		if(vis[i])  continue;
		if(t[i] >= tim)  break;
		if(st[i] == npos && dir[i] == ndir)  return 0;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i])  continue;
		if(t[i] > tim)  break;
		if((ndir == 1 && st[i] > npos) || (ndir == -1 && st[i] < npos))  return 0;
	}
	return 1;
}

void chk(int &Nw, int Npos, int Nid) {
	if(st[Nw] == Npos) {
		if(st[Nid] == Npos && dir[Nid] == 1)  Nw = Nid;
		return ;
	}
	if(st[Nid] == npos)  {Nw = Nid; return ;}
	if(st[Nid] > Npos)  {Nw = Nid; return ;}
}

int main() {
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	stp = 1; FLAG = 1;
	cin>>npos>>n>>p, tim = 0;
	for(int i = 1; i <= n; i++)  cin>>t[i]>>st[i]>>ed[i], dir[i] = (ed[i] - st[i]) / abs(ed[i] - st[i]);
	for(tim = 0; tim <= 1200; ++tim) {
		if(num != 0) {
			if(getout())  continue;
			if(getin())  continue;
			Go(); continue;
		}
		int flag = 0;
		for(int i = 1; i <= n; i++) {
			if(t[i] > tim)  break;
			if(!vis[i])  flag = 1;
		}
		if(!flag)  {FLAG = 1; continue;}
		if(FLAG) {
			int id = -1;
			for(int i = 1; i <= n; i++) {
				if(t[i] > tim)  break;
				if(vis[i])  continue;
				if(id == -1)  id = i;
				else  chk(id, npos, i);
			}
			FLAG = 0; ndir = (st[id] == npos) ? dir[id] : (st[id] - npos) / abs(st[id] - npos);
		}
		if(getin())  continue;
		if(canchangedir()) {
			ndir = -ndir; fflag = 0;
			if(getin())  ++tim;
			if(getin())  continue;
			if(ndir == 1)  printf("%02d:%02d The elevator starts to move up from floor %d.\n", tim / 60, tim % 60, npos);
			if(ndir == -1)  printf("%02d:%02d The elevator starts to move down from floor %d.\n", tim / 60, tim % 60, npos);
			--tim, stp = 0; continue;
		}
		Go();
	}
	return 0;
}
