#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll MOD=1e9+7;
    cin>>n;
    if(n==0) return 0;
    int m=max(n,6);
    vector<ll> dp(m+1,0);
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;
    dp[6]=32;
    for(int i=7;i<=n;i++){
        for(int j=1;j<=6;j++){
            dp[i]+=dp[i-j];
        }
        dp[i]%=MOD;
    } 
    cout<<dp[n]<<endl;
    return 0;
}

// int main(){
//     ll n;
//     ll MOD=1e9+7;
//     cin>>n;
//     ll ans=1;
//     for(int i=1;i<n;i++){
//         ans*=2;
//         ans%=MOD;
//     }
//     cout<<ans<<endl;
//     return 0;
// }