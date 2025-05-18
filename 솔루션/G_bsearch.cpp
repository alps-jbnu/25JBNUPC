#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <memory.h>
#include <math.h>
#include <map>
#include <set>
#include <limits.h>
#include <tuple>
using namespace std;

#define X first
#define Y second
#define ll long long
#define ld long double
#define INF INT32_MAX
const int MAX = 2000005;

ll n, m, r, a, b, ans = 2, mx;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(a * a + b * b);
    }
    cin >> r;
    sort(v.begin(), v.end());

    ll pre = r * r;
    ll cur = pre * 2;
    for (int i = 2; i <= m; i++) {
        ll cnt = lower_bound(v.begin(), v.end(), cur) - lower_bound(v.begin(), v.end(), pre);

        if (cnt > mx) {
            mx = cnt;
            ans = i;
        }

        pre = cur;
        cur = pre + r * r;
    }

    cout << ans << '\n';

    return 0;
}