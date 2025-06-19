#include<bits/stdc++.h>
using namespace std;

int f(int i,vector<int>& dp,vector<int>& prices,vector<int>& minList){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    dp[i]=min(f(i-1,dp,prices,minList),dp[i]-minList[i]);
    return dp[i];
}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> dp(n,-1);
    vector<int> minList(n,0);
    int mini=prices[0];
    minList[0]=mini;
    for(int i=1;i<n;i++){
        if(mini>prices[i]) mini=prices[i];
        minList[i]=mini;
    }
    return f(n-1,dp,prices,minList);
}