#include<bits/stdc++.h>
using namespace std;

bool f(int i,int j,string s,string p,vector<vector<int>>& dp){
    if(i==0 && j==0) return true;
    else if(i==0 && j!=0){
        for(int k=0;k<j;k++){
            if(p[k]!='*') return false;
        }
        return true;
    }
    else if(i!=0 && j==0) return false;
    if(dp[i][j]!=-1) return dp[i][j];
    if(p[j-1]=='*'){
        dp[i][j]=f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp);
    }
    else if(p[j-1]=='?') dp[i][j]=f(i-1,j-1,s,p,dp);
    else{
        if(s[i-1]==p[j-1]) dp[i][j]=f(i-1,j-1,s,p,dp);
        else dp[i][j]=false;
    }
    return dp[i][j];

}

bool isMatch(string s, string p) {
    int m=s.size(),n=p.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return f(m,n,s,p,dp);
}