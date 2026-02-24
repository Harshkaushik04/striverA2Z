#include<bits/stdc++.h>
using namespace std;

bool f(int i,int j,string& s,vector<vector<int>>& dp){
    if(i==j){
        dp[i][j]=1;
        return dp[i][j];
    }
    if(i+1==j){
        if(s[i]==s[j]){
            dp[i][j]=1;
            return dp[i][j];
        }
        else{
            dp[i][j]=0;
            return dp[i][j];
        }
    }
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=(s[i]==s[j]) && f(i+1,j-1,s,dp);
    return dp[i][j];
}

void f1(int i1,int i2,vector<vector<int>>& dp,vector<string>& curr,vector<vector<string>>& ans,string& s){
    if(i1==0){
        if(dp[i1][i2]==0) return;
        else{
            curr.emplace_back(s.substr(i1,i2-i1+1));
            ans.emplace_back(curr);
            curr.pop_back();
            return;
        }
    }
    if(dp[i1][i2]==0) f1(i1-1,i2,dp,curr,ans,s);
    else{
        f1(i1-1,i2,dp,curr,ans,s);
        curr.emplace_back(s.substr(i1,i2-i1+1));
        f1(i1-1,i1-1,dp,curr,ans,s);
        curr.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            f(i,j,s,dp);
        }
    }
    vector<string> curr;
    vector<vector<string>> ans;
    f1(n-1,n-1,dp,curr,ans,s);
    for(vector<string>& vec:ans) reverse(vec.begin(),vec.end());
    return ans;
}