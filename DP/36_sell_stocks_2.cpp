#include<bits/stdc++.h>
using namespace std;

int f(int i,int buy,vector<vector<int>>& dp,vector<int>& prices){
    if(i==0){
        if(buy==0) return 0;
        else if(buy==1) return -prices[0];
        else return INT32_MIN; //cannot sell
    }
    if(dp[i][buy]!=-1) return dp[i][buy];
    int temp1,temp2,temp3;
    temp1=max(f(i-1,0,dp,prices),f(i-1,1,dp,prices),f(i-1,2,dp,prices));
}

int maxProfit(vector<int>& prices) {
    //buy=0 =>nothing
    //buy=1 =>buy
    //buy=2 =>sell
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(3,-1));
    return max(f(n-1,0,dp,prices),f(n-1,1,dp,prices),f(n-1,2,dp,prices));
}