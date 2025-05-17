#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

int n;
string t;

int main(){
    cin >> n >> t;
    t=t;

    if(t.back()=='1'){
        cout << 0 << '\n';
        return 0;
    }

    ll ans=1;

    for(int i=0; i<n-1; i++){
        if(t[i]=='0') ans*=2;
        ans%=mod;
    }

    cout << ans << '\n';

    return 0;
}