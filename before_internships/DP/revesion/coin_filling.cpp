#include<bits/stdc++.h>
using namespace std;

/*
dp: n*amount
f(amount,i,n,coins,dp) -> outputs int:giving min number of coins to make up this amount after this index i
    if(amount==0) return 0;
    if(i>n) return INT32_MAX;
    take=INT32_MAX,not_take=INT32_MAX;
    if(amount>=coins[i]) take=f(amount-coins[i],i,coins,dp)+1;
    not_take=f(amount,i+1,coins,dp);
    dp[i][amount]=min(take,not_take);
    return dp[i][amount];
*/
int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<int> dp(amount+1,1e9);
    dp[0]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=amount;j++){
            int take=1e9;
            int not_take=1e9;
            if(j>=coins[i] && dp[j-coins[i]]!=1e9) take=dp[j-coins[i]]+1;
            not_take=dp[j];
            dp[j]=min(take,not_take);
        }
    }
    if(dp[amount]==1e9) return -1;
    return dp[amount];
}
