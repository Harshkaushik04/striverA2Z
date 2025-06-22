#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>>& dp,vector<int>& cuts){
    if(j-i<=1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT32_MAX;
    for(int k=i+1;k<j;k++){
        mini=min(mini,cuts[j]-cuts[i]+f(i,k,dp,cuts)+f(k,j,dp,cuts));
    }
    dp[i][j]=mini;
    return dp[i][j];
}

int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.emplace_back(n);
    int r=cuts.size();
    vector<vector<int>> dp(r,vector<int>(r,-1));
    return f(0,r-1,dp,cuts);
}
