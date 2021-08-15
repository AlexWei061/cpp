#include<bits/stdc++.h>
using namespace std;

int s = 0;
int v = 0;

struct Stime{
    int h;
    int m;
};

Stime clac(int t){
    int h = floor(t / 60.0);
    int m = t - (h * 60);
    Stime ans = (Stime){h, m};
    return ans;
}

int main(){
    scanf("%d%d", &s, &v);

    int t = ceil(s / (v * 1.0));
    //printf("%d\n", t);

    Stime tt = clac(t);
    //printf("%d %d\n", tt.h, tt.m);

    tt.m += 10;
    if(tt.m >= 60){
        tt.m -= 60;
        tt.h++;
    }
    Stime line = (Stime){8, 0};
    Stime ans = (Stime){(line.h - tt.h), (60- tt.m)};

    if(ans.h < 0){
        ans.h = 24 + ans.h;
    }

    ans.h--;

    if(ans.h < 10){
        printf("%d%d:", 0, ans.h);
    }
    else{
        printf("%d:", ans.h);
    }

    if(ans.m < 10){
        printf("%d%d\n", 0, ans.m);
    }
    else{
        printf("%d\n", ans.m);
    }

    return 0;
}