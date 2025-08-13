#include<bits/stdc++.h>
using namespace std;

//memoization
// int f(int i,int status,vector<vector<int>>& dp,vector<int>& prices){
//     if(i==0){
//         if(status==0 || status==2) return 0;
//         else return -prices[0];
//     }
//     if(dp[i][status]!=-1) return dp[i][status];
//     if(status==0) dp[i][status]=max(prices[i]+f(i-1,1,dp,prices),f(i-1,0,dp,prices));
//     else if(status==1) dp[i][status]=max(-prices[i]+f(i-1,2,dp,prices),f(i-1,1,dp,prices));
//     else dp[i][status]=f(i-1,0,dp,prices);
//     return dp[i][status];
// }

// int maxProfit(vector<int>& prices) {
//     int n=prices.size();
//     vector<vector<int>> dp(n,vector<int>(3,-1));
//     return f(n-1,0,dp,prices);
// }

//tabulation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int curr1=0,curr2=-prices[0],curr3=0;
    int temp1,temp2,temp3;
    for(int i=1;i<n;i++){
        temp1=max(prices[i]+curr2,curr1);
        temp2=max(-prices[i]+curr3,curr2);
        temp3=curr1;
        curr1=temp1;
        curr2=temp2;
        curr3=temp3;
    }
    return curr1;
}