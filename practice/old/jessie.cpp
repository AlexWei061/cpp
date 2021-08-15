#include<bitss/stdc++.h>
#include<windows.h>
using namespace std;

class InputOutput {                                                                              //class InputOutput
public:
	int inum;                                                                                    //定义integer num
	double dnum;                                                                                 //定义doubel num
	bool is;                                                                                     //定义bool 变量
	char c;                                                                                      //定义字符变量
	char str[1000];                                                                              //定义字符串变量
};

class Print : public InputOutput {                                                               //class Print继承于IO
public:
	void print() {}
	template<typename T, typename ...Types>
	inline void print(const T arg, const Types& ...args) {
		cout << arg << " ";
		print(args...);
	}
};

class Input : public InputOutput {                                                                //class Input继承于IO
public:
	inline int inputint() {                                                                       //输入一个整数
		cout << str;
		inum = 0;                                                                                 //存储这个数
		bool is_negative = false;                                                                 //是否为负数
		char c;                                                                                   //当前字符
		c = cin.get();
		while ((c < '0' or c > '9') and c != '-') {                                               //输入不需要的字符
			c = cin.get();
		}
		if (c == '-') {                                                                           //判断是否为负数
			is_negative = true;                                                                   //存储
		}
		else {
			inum += c - '0';                                                                      //若为正数或0 num += 要输入数字的第一位
		}
		c = cin.get();
		while (c >= '0' and c <= '9') {                                                           //输入剩下的位数
			inum = (inum * 10) + c - '0';                                                         //num = (num * 10) + c所代表的数字
			c = cin.get();                                                                        //更新c
		}
		if (is_negative == true) {                                                                //如果是负数
			inum *= -1;                                                                           //num *= -1
			return inum;
		}
		else {
			return inum;
		}
	}

	inline char inputchar(string str) {                                                           //输入字符
		cout << str;
		c = cin.get();
		return c;
	}

};

Input inputer;
Print printer;

void fs()
{
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */

	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
	/* 设置窗口信息 最大化 取消标题栏及边框 */
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

int main() {
	while (true) {
		fs();
		cout << "                                                                                  That day I met you" << endl;
		Sleep(1500);
		cout << "                                                                                  I sat next to you, didn't say anything" << endl;
		Sleep(1500);
		cout << "                                                                                  I saw the sun shineing in your eyes" << endl;
		Sleep(1500);
		cout << "                                                                                  you smiled with the starlight" << endl;
		Sleep(1500);
		cout << "                                                                                  That day I knew you felt in love with another girl" << endl;
		Sleep(1500);
		cout << "                                                                                  I never cried I said nothing I let you go" << endl;
		Sleep(1500);
		cout << "                                                                                  There's something wrong or nothing wrong" << endl;
		Sleep(1500);
		cout << "                                                                                  Just you and I got the end" << endl;
		Sleep(1500);
		cout << "                                                                                  There's nothing wrong or everything wrong" << endl;
		Sleep(1500);
		cout << "                                                                                  So you don't need to care me" << endl;
		Sleep(1500);
		cout << "                                                                                  That day you've gone. With everything" << endl;
		Sleep(1500);
		cout << "                                                                                  But the memory always with me" << endl;
		Sleep(1500);
		cout << "                                                                                  The sky rained loudly" << endl;
		Sleep(1500);
		cout << "                                                                                  But I didn't cry for anything" << endl;
		Sleep(1500);
		cout << "                                                                                  You said there will be a day I can forget" << endl;
		Sleep(1500);
		cout << "                                                                                  I said with a smile  That's true" << endl;
		Sleep(1500);
		cout << "                                                                                  But I kenw you didn't know" << endl;
		Sleep(1500);
		cout << "                                                                                  I'll remember forever" << endl;
		Sleep(1500);
		cout << "                                                                                  If there'll be a day I turn into the rain" << endl;
		Sleep(1500);
		cout << "                                                                                  The memory will be free" << endl;
		Sleep(1500);
		cout << "                                                                                  That day I can forget" << endl;
		Sleep(1500);
		cout << endl;
	}
	return 0;
}