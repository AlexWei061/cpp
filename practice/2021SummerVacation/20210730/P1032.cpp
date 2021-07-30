#include<bits/stdc++.h>
using namespace std;

string a, b;
string sa[8], sb[8];
map<string, int> map1;

int l;
queue<string> q;
queue<int> bb;

int bfs(){
	int i, j, k, m, n;
	string s,ss;
	while (q.empty() == 0 and q.front() != b and bb.front() <= 10){
		if (map1[q.front()] == 1){
			q.pop();
			bb.pop();
			continue;
		}
		map1[q.front()] = 1;
		for (int i = 1; i <= l; i++){	
			s = q.front();
			while (1){	
				m = s.find(sa[i]);
				if (m == -1) break;
				ss = q.front();
				ss.replace(m, sa[i].size(), sb[i]);
				q.push(ss);
				bb.push(bb.front() + 1);
				s[m] = '~';
			}
		}
		q.pop();
		bb.pop();
	}
	if (q.empty() == 1 or bb.front() > 10){
        return -1;
    } 
	else{ 
        return bb.front();
    }
}


int main(){
	int i, j, k, m, n;
	cin >> a >> b;
	l = 1;
	while(cin >> sa[l] >> sb[l]){ 
        l++;
    }
	l--;
	if(l == 0 and a != b){
		cout << "NO ANSWER!";
		return 0;
	}
	q.push(a);
	bb.push(0);
	k = bfs();
	if(k == -1){
		cout << "NO ANSWER!";
		return 0;
	}
	cout << k;
}


/*

[题目描述]
已知有两个字串 A, B 及一组字串变换的规则（至多 6 个规则）:
A1 -> B1
A2 -> B2
规则的含义为：在 A 中的子串 A1 可以变换为 B1, A2 可以变换成 B2...
例如 : A = abcd B = xyz
变换规则为
abc->xu  ud->y  y->yz
则此时, A可以经过一系列变换成为 B, 其变换过程为 :
abcd -> xud -> xy -> xyz
进行了3次变换使得 A 变换为 B

[输入输出样例]
abcd xyz
abc xu
ud y
y yz

3

所有字符串长度的上限为 20。

*/