#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return f(m-1,n-1,dp);
}

int f(int x,int y,vector<vector<int>>& dp){
    if(x==0 && y==0) return 1;
    int temp1=0,temp2=0;
    if(x-1>=0){
        if(dp[x-1][y]==-1) temp1=f(x-1,y,dp);
        else temp1=dp[x-1][y];
    }
    if(y-1>=0){
        if(dp[x][y-1]==-1) temp2=f(x,y-1,dp);
        else temp2=dp[x][y-1];
    }
    dp[x][y]=temp1+temp2;
    return dp[x][y];
}