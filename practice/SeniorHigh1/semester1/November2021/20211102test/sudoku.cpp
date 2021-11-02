#include<bits/stdc++.h>
using namespace std;
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

int t = 0;
int mmap[15][15][110] = { 0 };

struct Tpos{
	int x, y;
};
Tpos findNine(int x, int y){                                                    // 归到每个九宫格里 
	if((1 <= x and x <= 3) and (1 <= y and y <= 3)) return (Tpos){1, 1};
	if((1 <= x and x <= 3) and (4 <= y and y <= 6)) return (Tpos){1, 4};
	if((1 <= x and x <= 3) and (7 <= y and y <= 9)) return (Tpos){1, 7};
	
	if((4 <= x and x <= 6) and (1 <= y and y <= 3)) return (Tpos){4, 1};
	if((4 <= x and x <= 6) and (4 <= y and y <= 6)) return (Tpos){4, 4};
	if((4 <= x and x <= 6) and (7 <= y and y <= 9)) return (Tpos){4, 7};
	
	if((7 <= x and x <= 9) and (1 <= y and y <= 3)) return (Tpos){7, 1};
	if((7 <= x and x <= 9) and (4 <= y and y <= 6)) return (Tpos){7, 4};
	if((7 <= x and x <= 9) and (7 <= y and y <= 9)) return (Tpos){7, 7}; 
}

void Insert(int t, int x, int y, int k){
	if(mmap[x][y][t]){                                                  // 已经有数了 
		mmap[x][y][t+1] = mmap[x][y][t];
		printf("Error!\n");
	}
	else{                                                               // 还没数 
		bool is = false;                                                // 记录时是否冲突 
		for(int i = 1; i <= 9; i++){                                    // 判断行冲突 
			if(i != y)
				if(mmap[x][i][t] == k){
					is = true;
					mmap[x][y][t+1] = mmap[x][y][t];
					printf("Error:row!\n");
				}
		}
		for(int i = 1; i <= 9; i++){                                    // 判断列冲突 
			if(is) break;
			if(i != x)
				if(mmap[i][y][t] == k){
					is = true;
					mmap[x][t][t+1] = mmap[x][y][t];
					printf("Error:column!\n");	
				}
		}
		Tpos p = findNine(x, y); int a = p.x, b = p.y;
		for(int i = a; i <= a + 2; i++){                                // 判断九宫格冲突 
			if(is) break;
			for(int j = b; j <= b + 2; j++)
				if(!(i == x and j == y))
					if(mmap[i][j][t] == k){
						is = true;
						mmap[x][y][t+1] = mmap[x][y][t];
						printf("Error:square!\n");	
					}
		}
		if(!is) { mmap[x][y][t+1] = k; printf("OK!\n"); }               // 没有冲突 
	}
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
			if(!(i == x and j == y))
				mmap[i][j][t+1] = mmap[i][j][t];
}

void Delete(int t, int x, int y){
	if(!mmap[x][y][t]){                                                 // 没数 
		mmap[x][y][t+1] = mmap[x][y][t];
		printf("Error!\n");
	}
	else{                                                               // 有数 删了 
		mmap[x][y][t+1] = 0;
		printf("OK!\n");
	}
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++)
			if(!(i == x and j == y))
				mmap[i][j][t+1] = mmap[i][j][t];
	}
}

void Query(int t, int x, int y){
	map<int, int> s;                                                    // 记录每个数出现的次数 
	if(mmap[x][y][t]) printf("Error!\n");                               // 有数 
	else{                                                               // 没数 
		for(int i = 1; i <= 9; i++){                                    // 记录行上的数 
			s[mmap[x][i][t]]++;
		}
		for(int i = 1; i <= 9; i++){                                    // 记录列上的数 
			s[mmap[i][y][t]]++;
		}
		Tpos p = findNine(x, y); int a = p.x; int b = p.y;
		for(int i = a; i <= a + 2; i++){                                // 记录九宫格里的数 
			for(int j = b; j <= b + 2; j++)
				s[mmap[i][j][t]]++;
		}
		int cnt = 0;                                                    // 记录前面出现次数为 0 的数也就是可以填的数的数量 
		for(int i = 1; i <= 9; i++) if(!s[i]) cnt++;
		printf("%d\n", cnt);
		for(int i = 1; i <= 9; i++) if(!s[i]) printf("%d\n", i);        // 输出可以填的数 
	}
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++)
			mmap[i][j][t+1] = mmap[i][j][t];
	}
}

bool isCogTu(int t, int x, int y, int k){                               // 判断是否冲突 
	bool is = false;
	for(int i = 1; i <= 9; i++){                                        // 行上冲突 
		if(i != k)
			if(mmap[x][i][t+1] == k) is = true;
	}
	for(int i = 1; i <= 9; i++){                                        // 列上冲突 
		if(is) break;
		if(i != k)
			if(mmap[i][y][t+1] == k) is = true;	
	}
	Tpos p = findNine(x, y); int a = p.x, b = p.y;
	for(int i = a; i <= a + 2; i++){                                    // 九宫格冲突 
		if(is) break;
		for(int j = b; j <= b + 2; j++)
			if(!(i == x and j == y))
				if(mmap[i][j][t+1] == k) is = true;
	}
	return is;
}

void Merge(int t, int a, int b){
	a++; b++; int cnta = 0; int cntb = 0;
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if(mmap[i][j][a]){                                          // a 中有数 
				if(!isCogTu(t, i, j, mmap[i][j][a])){                   // a 不冲突
					mmap[i][j][t+1] = mmap[i][j][a]; cnta++;
				}
				else{                                                   // a 冲突 
					if(mmap[i][j][b]){                                  // b 有数 
						if(!isCogTu(t, i, j, mmap[i][j][b])){           // b 不冲突 
							mmap[i][j][t+1] = mmap[i][j][b]; cntb++;
						}
						else                                            // b 冲突 
							mmap[i][j][t+1] = 0;
					}
					else                                                // b 无数 
						mmap[i][j][t+1] = 0;	
				} 
			}
			else{                                                       // a 中无数 
				if(mmap[i][j][b]){                                      // b 有数 
					if(!isCogTu(t, i, j, mmap[i][j][b])){               // b 不冲突 
						mmap[i][j][t+1] = mmap[i][j][b]; cntb++;
					}
					else                                                // b 冲突 
						mmap[i][j][t+1] = 0;
				}
				else                                                    // b 无数 
					mmap[i][j][t+1] = 0;
			}
		}
	}
	printf("%d %d\n", cnta, cntb);
}

void Print(int t){
	for(int i = 1; i <= 9; i++){
		printf("+-");
	} printf("+\n");
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if(j == 1) printf("|");
			printf("%d|", mmap[i][j][t]);
		} puts("");
		for(int j = 1; j <= 9; j++){
			printf("+-");
		} printf("+\n"); 
	}
	
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++)
			mmap[i][j][t+1] = mmap[i][j][t]; 
	}
} 

int main(){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			mmap[i][j][1] = in;
		}
	}
	t = in;
	for(int i = 1; i <= t; i++){
		char op[10]; scanf("%s", op);
		if(op[0] == 'I'){
			int x = in, y = in, k = in;
			Insert(i, x, y, k);
		}	
		else if(op[0] == 'D'){
			int x = in, y = in;
			Delete(i, x, y);
		}
		else if(op[0] == 'Q'){
			int x = in, y = in;
			Query(i, x, y);
		}
		else if(op[0] == 'M'){
			int a = in, b = in;
			Merge(i, a, b);
		}
		else if(op[0] == 'P'){
			Print(i);
		}
	}
	return 0;
}
