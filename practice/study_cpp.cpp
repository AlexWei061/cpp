// study_cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define X 5 


template <class T>
void my_swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//add some comment to submit to github


template <typename T>
void my_swap_pointer(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}


int main(int argc, char** argv) {
	int N;
	int K = 5;
	struct trRace {
		string name;
		int time;
	};
	trRace tmp[X] = {
		{
			"xyz4", 4535
		},
		{
			"xyz5", 2
		},
		{
			"xyz2", 23
		},
		{
			"xyz1", 223
		},
		{
			"xyz3", 413435
		}
	};

	//cin>>N>>K;
	//for (int j = 0;j<X;j++){
	//	cin>>tmp[j].name>>tmp[j].time;
	//}
	for (int i = X - 1; i >= 1; i--) {
		for (int k = 0; k < i; k++) {
			if (tmp[k].time > tmp[k + 1].time) {
				my_swap(tmp[k],tmp[k+1]);
				//my_swap_pointer(&tmp[k], &tmp[k + 1]);
				//swap(tmp[k], tmp[k + 1]);

				/*
				trRace a = tmp[k];
				tmp[k] = tmp[k+1];
				tmp[k+1] = a;
				*/
				
			}
		}
	}
	for (int j = 0; j < X; j++) {
		cout << tmp[j].name << " " << tmp[j].time << endl;
	}

	cout << tmp[K - 1].name;
	return 0;
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
