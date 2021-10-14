#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  bool invalid = true;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
    if (board[i] != string(n, '.')) {
      invalid = false;
    }
  }
  if (invalid) {
    cout << -1 << "\n";
    return 0;
  }
  int bad = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[j][i] == '.') {
        ++bad;
        break;
      }
    }
  }
  int ans = n * 2;
  for (int i = 0; i < n; ++i) {
    if (board[i] != string(n, '.')) {
      int extra = 1;
      for (int j = 0; j < n; ++j) {
        if (board[j][i] == '#') {
          extra = 0;
          break;
        }
      }
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '.') {
          ++extra;
        }
      }
      ans = min(ans, bad + extra);
    }
  }
  cout << ans << "\n";
  return 0;
}
