#include<bits/stdc++.h>
using namespace std;

bool f(int i,int j,string& s,vector<vector<int>>& dp){
    if(i==j) return true;
    if(j-i<=2 && s[i]==s[j]) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=(s[i]==s[j]) && f(i+1,j-1,s,dp);
    return dp[i][j];
}

int f1(int i,string& s,vector<int>& dp,vector<vector<int>>& computed_dp,int n){
    if(i==n) return 0;
    if(computed_dp[i][n-1]) return 0;
    if(dp[i]!=-1) return dp[i];
    int mini=INT32_MAX;
    for(int j=i;j<n;j++){
        if(computed_dp[i][j]){
            mini=min(mini,1+f1(j+1,s,dp,computed_dp,n));
        }
    } 
    dp[i]=mini;
    return dp[i];
}

int minCut(string s) {
    int n=s.size();
    vector<vector<int>> computed_dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            f(i,j,s,computed_dp);
       }
    }
    vector<int> dp(n,-1);
    return f1(0,s,dp,computed_dp,n);
}