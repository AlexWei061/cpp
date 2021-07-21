#include<iostream>
#include <queue>
using namespace std;

/*
	[问题描述]
	Tom有一些学生成绩需要录入，在录入过程中，Tom有时想要知道已经录入的学生里分数从高到低的第k名是多少分

	[输入数据]
	每行两个数N,K。N为操作次数，K书询问的学生名次
	接下来N行，每行一个操作，有两种操作：
	I X：添加一个分数为X的学生，1 <= X <= 10^9；I后有空格
	Q：一次询问

	[输出数据]
	对于每个询问输出一行，为排名为第K学生的分数

	[输入样例]kth.in
	8 3
	I 1
	I 2
	I 3
	Q
	I 5
	Q
	I 4
	Q

	[输出样例]kth.out
	1
	2
	3
*/

char Op;
int n = 0;
int k = 0;
int x = 0;
priority_queue<int, vector<int>, greater<int> > num;           //创建优先队列

int main() {
	freopen("studycpp.in","r",stdin);
	freopen("studycp.out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		if (i < k) {
			cin >> Op >> x;
			num.push(x);
			continue;
		}
		cin >> Op;
		if (Op == 'Q') {
			printf("%d", num.top());
		}
		else {
			cin >> x;
			if (x > num.top()) {
				num.pop();
				num.push(x);
			}
		}
	}

	return 0;
}