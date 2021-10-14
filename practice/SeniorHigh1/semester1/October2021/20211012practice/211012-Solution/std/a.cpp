#include <bits/stdc++.h>

using namespace std;

const int P = (int) 1e9 + 7;

int main() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(1, 1);
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] != b.back() + 1) {
      b.push_back(b.back() + 2);
    } else {
      ans = (long long) ans * (b.size() + 1) % P;
    }
  }
  for (int i = 0; i < (int) b.size(); ++i) {
    ans = (long long) ans * (i + 1) % P;
  }
  cout << ans << "\n";
  return 0;
}
