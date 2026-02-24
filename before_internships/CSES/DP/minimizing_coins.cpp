#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n,-1);
    for(int i=0;i<n;i++) cin>>coins[i];
    vector<int> dp(x+1,INT32_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        int mini=INT32_MAX;
        for(int j:coins){
            if(i>=j && dp[i-j]!=INT32_MAX) mini=min(mini,dp[i-j]+1);
        }
        dp[i]=mini;
    }
    if(dp[x]==INT32_MAX) cout<<-1<<endl;
    else cout<<dp[x]<<endl;
    return 0;
}