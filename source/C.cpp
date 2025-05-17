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
#define sz(x) (int)(x).size()
const int MAX = 100000005;

int n, m;
int ans, mn = MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = max(n,m); i >= min(n,m); i--) {
        int a = abs(i - n);
        int b = abs(i - m);
        int num = max(a * 3, b) + i - 1;
        if (mn > num) {
            ans = i;
            mn = num;
        }
    }

    cout << mn << '\n';

    return 0;
}