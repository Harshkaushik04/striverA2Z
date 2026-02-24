#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i+1<m){
                if(dp[i+1][j]!=-1) dp[i+1][j]+=(dp[i][j]);
                else dp[i+1][j]=dp[i][j];
            }
            if(j+1<n){
                if(dp[i][j+1]!=-1) dp[i][j+1]+=(dp[i][j]);
                else dp[i][j+1]=dp[i][j];
            }
        }
    }
    return dp[m-1][n-1];
}
