#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull l, r;

int main(){
    cin >> l >> r;
    if(l+1==r){
        cout << (l^r) << '\n';
        return 0;
    }

    ull ans=1;
    while(ans<=(r-l)) ans*=2;
    while(1){
        ans/=2;
        if((ans&l)==0) break;
        ull tmp=l+(ans-((ans-1)&l));
        if(ans<=r-tmp) break;
    }
    cout << ans;

    return 0;
}
