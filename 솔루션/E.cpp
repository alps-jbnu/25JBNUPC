#include <iostream>
#include <algorithm>
#include <vector>
#define fast_io() cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
 
int m;
vector<int> arr;
int vis[2'000'000], cnt, ans=-1, mm=0;
 
void dfs(int u){
    vis[u]=++cnt;

    if(vis[arr[u]]){
        if(vis[arr[u]]<mm) return;  
        ans=max(vis[u]-vis[arr[u]]+1, ans);
    }else dfs(arr[u]);
}
 
int main(){
    fast_io();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cin >> m;
    arr.resize(m);
    for(auto &a:arr) {cin >> a; a--;}
 
    for(int i=0; i<m; i++){
        if(vis[i]) continue;
        dfs(i);
        mm=cnt+1;
    }
 
    cout << ans << '\n';
 
    return 0;
}