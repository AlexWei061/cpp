#include<bits/stdc++.h>
using namespace std;

int n = 0;
string str;

int main(){
    scanf("%d", &n);
    cin >> str;
    int x = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x == 1){
            string tempStr;
            cin  >> tempStr;
            str += tempStr;
            cout << str << endl;
        }
        else if(x == 2){
            int a = 0, b = 0;
            scanf("%d%d", &a, &b);
            str = str.substr(a, b);
            cout << str << endl;
        }
        else if(x == 3){
            int a = 0;
            string tempStr;
            scanf("%d", &a);
            cin >> tempStr;
            str.insert(a,tempStr);
            cout << str << endl;
        }
        else if(x == 4){
            string tempStr;
            cin >> tempStr;
            int ans = str.find(tempStr);
            if(ans > str.length()){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}