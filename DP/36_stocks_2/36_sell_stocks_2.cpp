#include<bits/stdc++.h>
using namespace std;

int f(int i,int buy,vector<vector<int>>& dp,vector<int>& prices,int n){
    if(i>=n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy==0) dp[i][buy]=max(f(i+1,0,dp,prices,n),prices[i]+f(i+1,1,dp,prices,n));
    else dp[i][buy]=max(f(i+1,0,dp,prices,n)-prices[i],f(i+1,1,dp,prices,n));
    return dp[i][buy];
}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,dp,prices,n);
}