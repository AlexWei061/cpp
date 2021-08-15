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

