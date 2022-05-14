#include<bits/stdc++.h>
using namespace std;

int n,q,l,r,x,a;
vector<int> pos[200005];

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);  
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
        scanf("%d",&a);
        pos[a].push_back(i);
    }
    scanf("%d",&q);
    while(q--)
	{
        scanf("%d%d%d",&l,&r,&x);
        int p1=lower_bound(pos[x].begin(),pos[x].end(),l)-pos[x].begin(); //在所有值为x的整数中二分查找编号大于等于l的第一个位置 
        int p2=upper_bound(pos[x].begin(),pos[x].end(),r)-pos[x].begin(); //在所有值为x的整数中二分查找编号大于r的第一个位置 
        printf("%d\n",p2-p1); //个数 
    }
    return 0;
}
