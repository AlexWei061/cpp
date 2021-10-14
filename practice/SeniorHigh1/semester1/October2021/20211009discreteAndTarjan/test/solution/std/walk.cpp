# include <bits/stdc++.h>
using namespace std;
namespace Base{
    # define mr make_pair 
    typedef long long ll; 
    typedef double db;
    const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
    const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
    template<typename T> void read(T &x){
        x = 0; int fh = 1; double num = 1.0; char ch = getchar();
        while (!isdigit(ch)){ if (ch == '-') fh = -1; ch = getchar(); }
        while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
        if (ch == '.'){
            ch = getchar();
            while (isdigit(ch)){num /= 10; x = x + num * (ch - '0'); ch = getchar();}
        }
        x = x * fh;
    }
    template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
    template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;

const int T = 8, N = 510, M = 10010, Q = 1e6 + 10, P = 998244353;
int power(int x, int y){
    int i = x; x = 1;
    while (y > 0){
       if (y % 2 == 1) x = 1ll * i * x % P;
       i = 1ll * i * i % P;
       y /= 2; 
    }
    return x;
}
int A[N][N], w[N][N], mp[N][N], u[M], v[M], n, m, q, inv[N], deg[N], b[M], tag[Q], qu[Q], qv[Q], qb[Q], opt[Q], w0[N][N];
int prob[M], p[T + 1][N], vision;
map<pair<int, int>, int> mpi;

int remain(int a, int t){
    return a >> (t - 1);
}
int pdtime(int a, int b){
    int t = 0;
    while (a > b){
        t++;
        a = a >> 1;
    }
    return t;
}

int invv(int a){return power(a, P - 2);}
inline int mul(const int &a, const int &b){return 1ll * a * b % P;}
inline int dec(const int &a, const int &b){return (a - b < 0) ? (a - b + P) : (a - b);}
void gauss(int n){
    for (int i = 1; i <= n; ++i){
        if (A[i][i] == 0) {
            for (int j = i + 1; j <= n; ++j){
                if (A[j][i] != 0){
                    swap(A[i], A[j]);
                    swap(w[i], w[j]);
                    break; 
                }
            }
        }
        for (int j = 1; j <= n; ++j){
            if (i == j) continue;
            int tmp = mul(A[j][i], invv(A[i][i]));
            for (int k = 1; k <= n; ++k) A[j][k] = dec(A[j][k], mul(tmp, A[i][k]));
            for (int k = 1; k <= vision; ++k)  w[j][k] = dec(w[j][k], mul(tmp, w[i][k]));
            
        }
    }
    for (int i = 1; i <= n; ++i){
        if (A[i][i] == 0) {printf("No Solution\n"); return;}
        for (int j = 1; j <= vision; j++)
            w[i][j] = mul(w[i][j], invv(A[i][i]));
    }
}
int main(){
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    read(n); read(m); read(q);
    vision = 1;
    for (int i = 1; i < n; i++) read(w[i][vision]);
    for (int i = 1; i <= m; i++){
        read(u[i]); read(v[i]);
        if (v[i] > u[i]) swap(u[i], v[i]);
        mpi[mr(u[i], v[i])] = i;
        read(b[i]);
        mp[u[i]][v[i]] = true;
        mp[v[i]][u[i]] = true;
        deg[u[i]]++; deg[v[i]]++;
    }
    for (int i = 1; i <= n; i++) inv[i] = power(i, P - 2);
    for (int i = 1; i <= n; i++){
        A[i][i] = 1;
        for (int j = 1; j <= n; j++)
            if (mp[i][j]) A[j][i] = -inv[deg[i]] + P;
    }
    tag[0] = 1;
    for (int i = 1; i <= q; i++){
        read(opt[i]);
        if (opt[i] == 1){
            read(qu[i]); read(qv[i]);
            if (qv[i] > qu[i]) swap(qv[i], qu[i]);
            qu[i] = mpi[mr(qu[i], qv[i])];
            read(qb[i]); 
        }
        if (opt[i] == 2){
            vision++;
            read(qu[i]); read(qv[i]);
            for (int j = 1; j <= n; j++) w[j][vision] = w[j][vision - 1];
            w[qu[i]][vision] = qv[i];
        }
        tag[i] = vision;
    }
    for (int i = 1; i <= vision; i++){
        int num = 0;
        for (int j = 1; j <= n; j++) num = (num + w[j][i]) % P;
        num = power(num, P - 2);
        for (int j = 1; j <= n; j++) w[j][i] = 1ll * w[j][i] * num % P;
        for (int j = 1; j <= n; j++) w0[j][i] = w[j][i];
    }
    gauss(n - 1);
    vision = 0;
    int ans = 0;
    for (int t = 0; t <= q; t++){
        if (tag[t] != vision){
            vision = tag[t];
            ans = 0;
            for (int i = 1; i <= m; i++){
                prob[i] = (1ll * w[u[i]][vision] * inv[deg[u[i]]] + 1ll * w[v[i]][vision] * inv[deg[v[i]]]) % P;
                ans = (ans + 1ll * prob[i] * b[i]) % P;
            }
        }
        if (opt[t] == 1){
            int id = qu[t];
            ans = ((ans - 1ll * prob[id] * b[id]) % P + P) % P;
            b[id] = qb[t];
            ans = ((ans + 1ll * prob[id] * b[id]) % P + P) % P;
        }
        printf("%d\n", ans);
    }
    return 0;
}
