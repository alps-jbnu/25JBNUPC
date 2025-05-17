#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

  const int n = 8;
  vector<vector<ll>> A(n, vector<ll>(n));

  for (auto &Ai : A)
    for (auto &Aij : Ai)
      cin >> Aij;

  string s = string(n - 1, '0') + string(n - 1, '1');
  ll ans = 0;
  do {
    int i = 0, j = 0;
    ans += A[0][0];
    for (auto &l : s) {
      if (l == '0')
        i += 1;
      else
        j += 1;
      ans += A[i][j];
    }

  } while (next_permutation(s.begin(), s.end()));
  cout << ans << '\n';
}