#include<bits/stdc++.h>
using namespace std;

// int f(int i,int bought,vector<int>& prices,vector<vector<int>>& dp,int n){
//     if(i==n-1){
//         if(bought==0) return 0;
//         else return prices[n-1];
//     }
//     if(dp[i][bought]!=-1) return dp[i][bought];
//     if(bought==0) dp[i][bought]=max(f(i+1,1,prices,dp,n)-prices[i],
//                                     f(i+1,0,prices,dp,n));
//     else dp[i][bought]=max(f(i+1,1,prices,dp,n),f(i+1,0,prices,dp,n)+prices[i]);
//     return dp[i][bought];
// }

// int maxProfit(vector<int>& prices) {
//     int n=prices.size();
//     vector<vector<int>> dp(n,vector<int>(2,-1));
//     return f(0,0,prices,dp,n);
// }

//optimized
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int current1,current2;
    current1=0;
    current2=prices[n-1];
    for(int i=n-2;i>=0;i--){
        current1=max(current2-prices[i],current1);
        current2=max(current2,current1+prices[i]);

    }
    return current1;
}