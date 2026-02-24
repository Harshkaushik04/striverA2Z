#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr) {
    // code here
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }
    int mini=INT32_MAX;
    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<n;j++){
            mini=INT32_MAX;
            for(int k=i;k<j;k++){
                mini=min(mini,dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}