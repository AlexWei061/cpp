#include<bits/stdc++.h>
using namespace std;

string ans=" yizhong";
char a[102][102];
bool book[102][102]={0};
int num;

int dfs(int n,int m,int no,int f){
	if(n < 1 or m < 1 or n > num or m > num){//如果越界则返回
        return 0;
    }
	if(a[n][m] == ans[no]){//如果是对应字母，则继续深搜
		if(no == 7){//如果搜到最后一个，则返回1，表示深搜成功
			book[n][m] = 1;
			return 1;
		}	
		else{
            //有选择性的搜索
			switch (f){
				case 1 :	if(dfs(n - 1, m - 1, no + 1, f)){ book[n][m] = 1; return 1; } else return 0;
				case 2 :	if(dfs(n - 1, m, no + 1, f)){ book[n][m] = 1; return 1;} else return 0;
				case 3 :	if(dfs(n - 1, m + 1, no + 1, f)){ book[n][m] = 1; return 1;}else return 0;
				case 4 :	if(dfs(n, m - 1, no + 1, f)){ book[n][m] = 1; return 1; } else return 0;
                /*case 5表示no==1，
                作为第一个字母，因此是个特例，要向所有方向搜索
                其余情况都只向一个特定方向搜索*/
				case 5 :
					if(dfs(n - 1, m - 1, no + 1, 1))
						book[n][m] = 1;
					if(dfs(n - 1, m, no + 1, 2)) 
						book[n][m] = 1;
					if(dfs(n - 1, m + 1, no + 1, 3)) 
						book[n][m] = 1;
					if(dfs(n, m - 1, no + 1, 4)) 
						book[n][m] = 1;
					if(dfs(n, m + 1, no + 1, 6)) 
						book[n][m] = 1;
					if(dfs(n + 1, m - 1, no + 1, 7)) 
						book[n][m] = 1;
					if(dfs(n + 1, m, no + 1, 8)) 
						book[n][m] = 1;
					if(dfs(n + 1, m + 1, no + 1, 9)) 
						book[n][m] = 1;
					break;
				case 6 : if(dfs(n, m + 1, no + 1, f)){ book[n][m] = 1; return 1; } else return 0;
				case 7 : if(dfs(n + 1, m - 1, no + 1, f)){ book[n][m] = 1; return 1;} else return 0;
				case 8 : if(dfs(n + 1, m, no + 1, f)){book[n][m] = 1; return 1;} else return 0;
				case 9 : if(dfs(n + 1, m + 1, no + 1, f)){book[n][m] = 1; return 1;} else return 0;
			}
				
		}
	}
	else//如果搜到最后一个，则返回1，表示深搜成功
		return 0;
}

int main()
{
	cin >> num;
	for(int i = 1; i <= num; i++)
		for(int j = 1; j <= num; j++)
			cin >> a[i][j];
	for(int i = 1; i <= num; i++)
		for(int j = 1; j <= num; j++)
			dfs(i, j, 1, 5);
	for(int i = 1; i <= num; i++){
		for(int j = 1; j <= num; j++){
			if(book[i][j])
				cout << a[i][j];
			else
				cout << "*";
		}
		cout << endl;
	}	
	return 0;
}

/*

给一 n × n 的字母方阵，内可能蕴含多个“yizhong”单词。单词在方阵中是沿着同一方向连续摆放的。摆放可沿着 8 个方向的任一方向，
同一单词摆放时不再改变方向，单词与单词之间可以交叉,因此有可能共用字母。输出时，将不是单词的字母用*代替，以突出显示单词。例如：
    输入:
    8                     输出：
    qyizhong              *yizhong
    gydthkjy              gy******
    nwidghji              n*i*****
    orbzsfgz              o**z****
    hhgrhwth              h***h***
    zzzzzozo              z****o**
    iwdfrgng              i*****n*
    yyyygggg              y******g

7 <= n <= 100

*/