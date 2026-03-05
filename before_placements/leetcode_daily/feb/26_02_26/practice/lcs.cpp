#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
    if(i==-1 || j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        int take=1+f(i-1,j-1,s1,s2,dp);
        int not_take=max(f(i,j-1,s1,s2,dp),f(i-1,j,s1,s2,dp));
        dp[i][j]=max(take,not_take);
    }
    else{
        dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    return dp[i][j];
}

int lcs(string &s1, string &s2) {
    // code here
    vector<vector<int>> dp=vector<vector<int>>(s1.size(),vector<int>(s2.size(),-1));
    int i=s1.size();
    int j=s2.size();
    return f(i-1,j-1,s1,s2,dp);
}