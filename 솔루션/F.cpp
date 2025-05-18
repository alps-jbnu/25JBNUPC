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

int32_t main(){
	cin >> n >> q;
	vector<vector<int>> v(n + 1);
	vector<int> p(n + 1);
	iota(p.begin(), p.end(), 0);
	auto Find = [&](int x, auto&& Find) -> int{
		return x == p[x] ? x : p[x] = Find(p[x], Find);
	};
	auto Union = [&](int a, int b) -> bool{
		a = Find(a, Find), b = Find(b, Find);
		if(a == b) return 0;
		if(v[a].size() < v[b].size()) swap(a, b);
		for(const auto& c : v[b]){
			v[a].push_back(c);
		}
		p[b] = a;
		sort(v[a].rbegin(), v[a].rend());
		while((int)v[a].size() > 20) v[a].pop_back();
		return 1;
	};
	for(int i = 1; i <= n; i++) v[i].push_back(i);
	for(int i = 0; i < q; i++){
		int t,a,b; cin >> t >> a >> b;
		if(t == 1){ Union(a, b); }
		else if(t == 2){
			auto f = Find(a, Find);
			if(v[f].size() < b) cout << -1 << "\n";
			else{				
				cout << (v[f][b - 1]) << "\n";
			}
		}
	}
	return 0;
}