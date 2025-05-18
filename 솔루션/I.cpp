#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int C = 1000000;

vector<int> prep1(const vector<int> &F) {
  // sparse table
  vector<vector<int>> table(21, vector<int>(size(F)));
  table[0] = F;

  for (int k = 1; k < size(table); k++) {
    for (int i = 0; i < size(table[k]); i++) {
      int x = table[k - 1][i];
      table[k][i] = table[k - 1][x];
    }
  }

  vector<int> ret;
  for (int i = 0; i < size(F); i++)
    ret.push_back(i);

  for (int k = 0; k < size(table); k++) {
    if ((C & (1 << k)) == 0)
      continue;

    for (int i = 0; i < size(table[k]); i++) {
      ret[i] = table[k][ret[i]];
    }
  }
  return ret;
}

vector<int> prep2(const vector<int> &F) {
  vector<vector<int>> inv(size(F));
  for (int i = 0; i < size(F); i++)
    inv[F[i]].push_back(i);

  vector<int> ret(size(F), -1);
  vector<int> cyclePos(size(F), -1);
  vector<bool> visited(size(F), false);

  for (int i = 0; i < size(F); ++i) {
    if (visited[i])
      continue;

    vector<int> path;
    int current = i;

    while (!visited[current]) {
      visited[current] = true;
      path.push_back(current);
      current = F[current];
    }

    int cycleStart = -1;
    vector<int> cycle;
    for (int j = 0; j < path.size(); ++j) {
      if (path[j] == current) {
        cycleStart = path[j];
        cycle = vector<int>(path.begin() + j, path.end());
        break;
      }
    }

    // BFS from cycle

    if (cycle.size() == 0)
      continue;

    queue<int> Q;
    Q.push(cycle.front());
    cyclePos[cycle.front()] = 0;
    ret[cycle.front()] = cycle[1000000 % size(cycle)];

    while (Q.size() > 0) {
      auto v = Q.front();
      Q.pop();

      for (auto next : inv[v]) {
        if (cyclePos[next] != -1)
          continue;
        cyclePos[next] = (cyclePos[v] + size(cycle) - 1) % size(cycle);
        ret[next] = cycle[(1000000 + cyclePos[next]) % size(cycle)];
        Q.push(next);
      }
    }
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;

  vector<ll> A(n);
  for (auto &Ai : A)
    cin >> Ai;
  vector<int> F(n);
  for (auto &Fi : F) {
    cin >> Fi;
    Fi--;
  }
  auto F1e6 = prep2(F);
  vector<ll> A1e6(n);
  for (int i = 0; i < n; i++) {
    A1e6[F1e6[i]] += A[i];
  }

  while (q--) {
    string query;
    cin >> query;

    if (query == "set") {
      int i;
      cin >> i;
      i--;

      ll last = A[i];
      cin >> A[i];

      A1e6[F1e6[i]] += A[i] - last;
    }

    if (query == "get") {
      int i;
      cin >> i;
      i--;
      cout << A1e6[i] << '\n';
    }
  }
}