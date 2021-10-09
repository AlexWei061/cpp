#include<bits/stdc++.h> 
#define ll long long 
using namespace std; 
 
const int MAXN = int(3e5 + 21);                              //3*N 
int getNum[MAXN];                                            //离散化数组，之所以是3*N的空间，是因为要存N朵花开放的起、始时间、查询时间 
int li[MAXN / 3], ri[MAXN / 3], c[MAXN];                     //花开的起始时间、结束时间、树状数组 
 
int lowbit(int x){      
    return x & -x; 
} 
 
void add(int x, int num, int len){                           //区间更新   
    for(int i=x;i<=len;i+=lowbit(i)) { 
        c[i] += num; 
    } 
} 
 
ll query(int x){                                             //单点查询   
    ll ans = 0; 
    for(int i = x; i > 0; i -=l owbit(i)){ 
        ans += c[i]; 
    } 
    return ans; 
} 
 
int bSerach(int num, int len){                               //在数组getNum中找出大于等于num的数，并返回其下标+1（则树状数组下标从1开始）   
    return lower_bound(getNum, getNum + len, num) - getNum + 1; 
}

int main() { 
    int t, n, m, cnt = 0; 
    cin >> t; 
    while(t--){ 
        memset(c, 0, sizeof(c)); 
        memset(getNum, 0, sizeof(getNum));    
        scanf("%d%d", &n, &m);         
        int cnt1 = 0;         
        for(int i = 0; i < n; ++i) { 
            scanf("%d%d", &li[i], &ri[i]); 
            getNum[cnt1++] = li[i];                          //将花开放范围出现的数据存入数组  
            getNum[cnt1++] = ri[i]; 
        } 
        int ques[MAXN / 3];                                  //存储查询时间 
        for(int i = 0; i < m; ++i){ 
            scanf("%d", &ques[i]);  
            getNum[cnt1++] = ques[i];                        //将查询出现的数据存入数组  
        }         
        sort(getNum, getNum + cnt1);                         //给所有出现的数排序 
 
        int cnt2 = 1; 
        for(int i = 1; i < cnt1; ++i){ 
            if(getNum[i] != getNum[i - 1])                   // getNum[0]～getNum[cnt2-1]存的是去重后的数  
                getNum[cnt2++] = getNum[i]; 
        }   
 
        for(int i = 0; i < n; ++i){                          //树状数组区间更新 
            add(bSerach(li[i], cnt2), 1, cnt2);              //位置bSerach(li[i],cnt2)～位置cnt2均增加1 
            add(bSerach(ri[i], cnt2) + 1, -1, cnt2);         //位置bSerach(lr[i]+1,cnt2)～位置cnt2均增加-1 
        }  
        printf("Case #%d:\n", ++cnt); 
        for(int i = 0; i < m; ++i){ 
            cout << query(bSerach(ques[i],cnt2)) << endl;    //树状数组单点查询  
        }                                                    //bSerach(ques[i],cnt2)是查找ques[i]在离散化数组中的位置 
    } 
    return 0; 
}
