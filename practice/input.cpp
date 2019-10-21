#include <iostream>
#include<String>
using namespace std;

class InputOutput {                                                                                       //class IO
public:
	int inum;                                                                                    //定义integer num
	double dnum;                                                                                 //定义doubel num
	bool is;                                                                                     //定义bool 变量
	char c;                                                                                      //定义字符变量
	char str[1000];                                                                              //定义字符串变量
};

class Print : public InputOutput {                                                                        //class Print继承于IO
public:
	void print() {}
	template<typename T, typename ...Types>
	inline void print(const T arg, const Types& ...args) {
		cout << arg << " ";
		print(args...);
	}
};

class Input : public InputOutput {                                                                         //class Input继承于IO
public:
	int inputint() {                                                                              //输入一个整数
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
			inum += c - '0';                                                                       //若为正数或0 num += 要输入数字的第一位
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

	char inputchar() {                                                                             //输入字符
		c = cin.get();                                                                       
		return c;
	}
	char* inputstring() {
		int c = cin.get();
		int i = 0;
		while (c >= 33 and c <= 125) {
			str[i] = c;
			c = cin.get();
		}
		return str;
	}
};

Input inputer;
Print printer;

int main()
{
	char c;
	int num = 0;
	num = inputer.inputint();
	c = inputer.inputchar();
	printer.print(num,c);
	return 0;
}
