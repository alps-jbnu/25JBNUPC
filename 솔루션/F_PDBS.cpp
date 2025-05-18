#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

int n,q;

template <typename T>
using pbds = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main(){
	cin >> n >> q;
	vector<pbds<int>> X(n + 1);
	for(int i = 1; i <= n; i++) X[i].insert(i);
	vector<int> p(n + 1);
	iota(p.begin(), p.end(), 0);
	auto Find = [&](int x, auto&& Find) -> int{ return x == p[x] ? x : p[x] = Find(p[x], Find); };
    auto Union = [&](int a, int b) -> bool{
		a = Find(a, Find), b = Find(b, Find);
		if(a == b) return 0;
		if(X[a].size() < X[b].size()) swap(a, b);
		for(const auto& i : X[b]){
			X[a].insert(i);
			p[i] = a;
		}
		return 1;
	};
	for(int i = 0; i < q; i++){
		int op; cin >> op;
		if(op == 1){
			int a,b; cin >> a >> b;
			Union(a, b);
		}
		else if(op == 2){
			int x,k; cin >> x >> k;
			auto f = Find(x, Find);
            if((int)X[f].size() < k) cout << -1 << "\n";
            else{
                --k;
                cout << (*X[f].find_by_order(k)) << "\n";
            }
		}
	}
	return 0;
}