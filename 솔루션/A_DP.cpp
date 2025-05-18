#include <bits/stdc++.h>
using namespace std;
int n;
int dp[100001][7];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        if(i==0){
            if(a==0){
                dp[0][1]=1;
            }
            dp[0][0]=3;
            dp[0][6]=3;
            continue;
        }
        if(a==0){//sunny
            dp[i][0]=dp[i-1][6]+3;  
            for(int j=1;j<6;j++){
                if(!dp[i-1][j-1]) continue;
                dp[i][j]=dp[i-1][j-1]+j;
            }
            if(dp[i-1][5]){
                dp[i][5]=max(dp[i][5],dp[i-1][5]+5);
            }
        }
        else if(a==1){///rainy
            dp[i][0]=dp[i-1][6]+3;
        }
        dp[i][6]=*max_element(dp[i],dp[i]+7);
    }
    cout<<dp[n-1][6];

    return 0;
}