#include <bits/stdc++.h>

using namespace std;

const int N = 123456;
const int B = 10007;
const int P = (int) 1e9 + 7;
const int Q = (int) 1e9 + 9;

int n, q, hp[N], hq[N];

struct node;
node* null;

struct node {
  node* l = null;
  node* r = null;
  pair<int, int> h = {0, 0};
};

node* root[N];

node* build(int l, int r) {
  node* v = new node();
  if (l != r) {
    int y = (l + r) >> 1;
    v->l = build(l, y);
    v->r = build(y + 1, r);
  }
  return v;
}

pair<node*, bool> modify(node* v, int l, int r, int p) {
  node* u = new node();
  u->l = v->l;
  u->r = v->r;
  u->h = v->h;
  if (l == r) {
    u->h.first ^= 1;
    u->h.second ^= 1;
    return {u, u->h.first};
  } else {
    int y = (l + r) >> 1;
    bool res;
    if (p <= y) {
      tie(u->l, res) = modify(u->l, l, y, p);
    } else {
      tie(u->r, res) = modify(u->r, y + 1, r, p);
    }
    u->h.first = ((long long) u->l->h.first * hp[r - y] + u->r->h.first) % P;
    u->h.second = ((long long) u->l->h.second * hq[r - y] + u->r->h.second) % Q;
    return {u, res};
  }
}

bool compare(node* v, node* u, int l, int r) {
  if (l == r) {
    return u->h.first;
  } else {
    int y = (l + r) >> 1;
    if (v->l->h != u->l->h) {
      return compare(v->l, u->l, l, y);
    } else {
      return compare(v->r, u->r, y + 1, r);
    }
  }
}

int lcp(node* v, node* u, int l, int r) {
  if (l == r) {
    return 0;
  } else {
    int y = (l + r) >> 1;
    if (v->l->h != u->l->h) {
      return lcp(v->l, u->l, l, y);
    } else {
      return (y - l + 1) + lcp(v->r, u->r, y + 1, r);
    }
  }
}

int lcp(node* v, node* u) {
  if (v->h == u->h) {
    return n;
  } else {
    return lcp(v, u, 1, n);
  }
}

void init() {
  null = new node();
  null->l = null->r = null;
  hp[0] = hq[0] = 1;
  for (int i = 1; i <= n; ++i) {
    hp[i] = (long long) hp[i - 1] * B % P;
    hq[i] = (long long) hq[i - 1] * B % Q;
  }
  root[0] = build(1, n);
}

struct comp {
  bool operator()(node* v, node* u) {
    if (v->h == u->h) {
      return false;
    } else {
      return compare(v, u, 1, n);
    }
  }
};

int main() {
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  init();
  set<node*, comp> st;
  long long ans = 1;
  for (int i = 1; i <= q; ++i) {
    int c;
    cin >> c;
    c = n - c;
    root[i] = root[i - 1];
    while (true) {
      bool res;
      tie(root[i], res) = modify(root[i], 1, n, c--);
      if (res || !c) {
        break;
      }
    }
    ans += n;
    if (st.find(root[i]) == st.end()) {
      auto it = st.insert(root[i]).first;
      if (it != st.begin()) {
        ans -= lcp(root[i], *prev(it));
      }
      if (it != --st.end()) {
        ans -= lcp(root[i], *next(it));
      }
      if (it != st.begin() && it != --st.end()) {
        ans += lcp(*prev(it), *next(it));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
