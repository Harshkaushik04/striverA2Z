#include<bits/stdc++.h>
using namespace std;

int f(int i,vector<int>& dp){
    if(i==0 || i==1) return 0;
    if(dp[i]!=-1) return dp[i];
    dp[i]=f(i/2,dp)+f(i-i/2,dp)+(i/2)*(i-i/2);
    return dp[i];
}

int minCost(int n) {
    vector<int> dp(n+1,-1);
    return f(n,dp);
}