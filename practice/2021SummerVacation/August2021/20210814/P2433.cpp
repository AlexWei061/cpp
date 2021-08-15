#include<bits/stdc++.h>
using namespace std;

int t = 0;

void solution(int t){
    if(t == 1){
        printf("I love Luogu!\n");
    }

    else if(t == 2){
        int totApples = 10;
        int A = 2;
        int Uim = 4;
        int baYong = totApples - (A + Uim);
        printf("%d %d\n", A + Uim, baYong);
    }

    else if(t == 3){
        int totApples = 14;
        int totStudents = 4;
        int avrageApples = totApples / totStudents;
        int apples = avrageApples * totStudents;
        int applesLeft = totApples - apples;
        printf("%d\n%d\n%d\n", avrageApples, apples, applesLeft); 
    }

    else if(t == 4){
        int drink = 500;
        double average = drink / 3.0;
        printf("%.3lf\n", average);
    }

    else if(t == 5){
        int alen = 260;
        int Va   = 12;
        int blen = 220;
        int Vb   = 20;
        int t = (alen + blen) / (Va + Vb); 
        printf("%d\n", t);
    }

    else if(t == 6){
        int a = 6;
        int b = 9;
        cout << sqrt(a*a + b*b);
    }

    else if(t == 7){
        int Uim  = 100;
        int add  = 10;
        int shop = 20;
        printf("%d\n%d\n%d\n", Uim + add, Uim + add - shop, 0);
    }

    else if(t == 8){
        int r = 5;
        const double pi = 3.141593;
        cout << 2 * r * pi << endl;     
        cout << pi * r * r << endl;
        cout << 1.0 * 4/3 * pi * r * r * r << endl;
    }

    else if(t == 9){
        int ans = (((((1 + 1) * 2) + 1) * 2) + 1) * 2;
        printf("%d\n", ans);
    }

    else if(t == 10){
        int ans = 9;    
        printf("%d\n", ans);
    }

    else if(t == 11){
        int Va = 5;
        int Vb = 8;
        int d = 100;
        cout << 1.0 * d / (Vb - Va) << endl;    
    }

    else if(t == 12){
        printf("%d\n", 'M'-'A'+1);
        printf("%c\n", (char)(18 + 'A' - 1));
    }

    else if(t == 13){
        double pi = 3.141593;
        cout<<(int)(pow(1.0 * 4 / 3 * pi * (4 * 4 * 4 + 10 * 10 * 10), 1.0 * 1 / 3));    
    }

    else if(t == 14){
        int ans = 50;
        printf("%d\n", ans);    
    }

}

int main(){
	scanf("%d", &t);

    solution(t);

	return 0;
}