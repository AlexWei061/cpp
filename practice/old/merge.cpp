#include<bits/stdc++.h>
using namespace std;

/*
问题描述
Rainie拥有很多宠物小精灵，现在她想把这些宠物小精灵进行合成，产生新的宠物小精灵，最终合成为
一只宠物小精灵，而每只宠物小精灵都有不同的能力值，同时合成也有其必须遵守的规则，具体规则如
下：
1、每次只能将能力值排第一的小精灵和能力值排行倒数第一的小精灵进行合成；
2、设能力值第一的小精灵为a，能力值倒数第一的小精灵为b,合成后的小精灵能力值为c=a/2+b；
3、(取整数，如果，则的结果为)
4、将合成后新的宠物重新加入
Rainie想你帮助她计算一下最终合成后的宠物能力值是多少。

输入格式
第一行包含一个整数 ，表示总共有多少只小精灵；
第二行包含个整数，表示小精灵的能力值。

输出格式
输出只有一行，包含一个整数，即最后合成的小精灵能力值
*/

long long NumOfBao = 0;
long long PowOfEachBao[100001] = { 0 };
//升序队列
priority_queue <long long, vector<long long>,greater<long long> > gq;
//降序队列
priority_queue <long long, vector<long long>,less<long long> > lq;

int main(){
    /*输入*/
    scanf("%lld", &NumOfBao);
    for(long long i = 0; i < NumOfBao; i++){
        scanf("%lld", &PowOfEachBao[i]);
        gq.push(PowOfEachBao[i]);
        lq.push(PowOfEachBao[i]);
    }
    /**/
    long long j = 0;
    while(1){                                            //for(long long i = 0; i < NumOfBao - 1; i++)
        long long temp = (lq.top() / 2) + gq.top();
        if(j == NumOfBao - 2){
        	printf("%lld", temp);
        	break;
		}
        gq.pop();
        lq.pop();
        gq.push(temp);
        lq.push(temp);
        j++;
    }
    return 0;
}
