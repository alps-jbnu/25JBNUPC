#include <algorithm>
#include <bits/stdc++.h>
#include <ios>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;

  vector<ll> points;

  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    points.push_back(x * x + y * y);
  }
  sort(points.begin(), points.end());

  ll r0;
  cin >> r0;

  map<ll, int> M;
  M.insert({2, 0});
  ll k = 1;
  for (auto &p : points) {
    if (p < r0 * r0) {
      continue;
    }
    while (r0 * r0 * k <= p)
      k++;
    if (k > m)
      break;
    M[k]++;
  }
  pair<ll, int> ans = *M.begin();
  for (auto &m : M) {
    if (m.second > ans.second) {
      ans = m;
    }
  }
  cout << ans.first << endl;
}