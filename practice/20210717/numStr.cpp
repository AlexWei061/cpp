#include<bits/stdc++.h>
using namespace std;

int s = 0;
char c;

int main() {		
	c = getchar();                                         //标准输入输出中的写法 
	while(c != 10){
		s = s + (c - '0');
		c = getchar();
	}
	cout << s << endl;
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int s=0;
char c;

int main() 
{
	freopen("num.in","r",stdin);                           //文件输入输出中的写法 
	freopen("num.out","w",stdout); 
	while(cin>>c)                                          //直到EOF 
	{
		s=s+(c-'0');
	}
	cout<<s<<endl;
    return 0;
}
*/
