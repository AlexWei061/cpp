#include<bits/stdc++.h>
using namespace std;

int n = 0;
int binary[2020] = { 0 };

char work(char a, char b){
	if(a == 'F' or b == 'F'){
		return 'F';
	}
	if(a == 'B' and b == 'B'){
		return 'B';
	}
	if(a == 'I' and b == 'I'){
		return 'I';
	}
	if((a == 'I' and b == 'B') or (a == 'B' and b == 'I')){
		return 'F';
	}
}

// tree[node] = work(tree[node*2], tree[node*2+1])
char tree[10010];
void bulid(int n, int binary[]){
    //printf("in\n");
    //printf("%d\n", (1 << (n + 1)) - 1);
	for(int i = (1 << (n + 1)) - 1; i >= 1; i--){
        //printf("in\n");
		if((1 << n) <= i and i <= (1 << (n+1)) - 1){
			tree[i] = binary[i - (1 << n) + 1] ? 'I' : 'B';
		}
		else{
			tree[i] = work(tree[i * 2], tree[i * 2 + 1]);
		}
	}   
}

void postorder(int node, char* tree){
	if(tree[node*2] != '#'){
		postorder(node*2, tree);
	}
	if(tree[node*2+1] != '#'){
		postorder(node*2+1, tree);
	}
	printf("%c", tree[node]);
}

int main(){
	memset(tree, '#', sizeof(tree));
	scanf("%d", &n);
	int m = 1 << n;
    //printf("m = %d\n", m);
	for(int i = 1; i <= m; i++){
        char c;
        cin >> c;
        binary[i] = c - '0';
	}

    /*
	for(int i = 1; i <= m; i++){
        printf("%d", binary[i]);
	}
    puts("");
    */
	
    bulid(n, binary);

    /*
    for(int i = 1; i <= (1 << (n+1)) - 1; i++){
        printf("%c ", tree[i]);
    }
    puts("");
    */

	postorder(1, tree);
	puts("");

    return 0;
}

/*

我们可以把由 0 和 1 组成的字符串分为三类：全 0 串称为 B 串，全 1 串称为 I 串，既含 0 又含 1 的串则称为 F串。

FBI树是一棵二叉树，它的结点类型也包括F结点，B结点和 I结点三种。由一个长度为 2^N 的 01 串S可以构造出一棵 FBI树 T ，递归的构造方法如下：

(1) T的根结点为R，其类型与串S的类型相同；
(2) 若串S的长度大于1，可将串S从中间分开，分为等长的左右子串S_1, S_2

现在给定一个长度为2^N 的 01 串，请用上述构造方法构造出一棵 FBI树，并输出它的后序遍历序列。

*/