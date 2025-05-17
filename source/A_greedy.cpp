#include <iostream>
#include <utility>
#include <tuple>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x.size())
#define fast_io() cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef long long ll;
typedef pair<ll, ll> pll;
 
int n, cnt, ans;
string s;
 
 
int main(){
    fast_io();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin >> n;// >> s;
    //s='*'+s;
    
    for(int i=1; i<=n; i++){
        int input;
        cin >> input;

        if(input==0) cnt++;
        else{
            ans+=max(min((cnt)*(cnt+1)/2, 5*cnt-10), 3*cnt)+3;
            cnt=0;
        }
    }
    if(cnt){
        ans+=max(min((cnt)*(cnt+1)/2, 5*cnt-10), 3*cnt);
        cnt=0;
    }
    
    cout << ans << '\n';
    return 0;
}
