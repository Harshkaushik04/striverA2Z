#include<bits/stdc++.h>
using namespace std;

//memoization
// int f(int i,int j,vector<vector<int>>& dp,vector<int>& arr){
//     if(i==j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int mini=INT32_MAX;
//     for(int k=i;k<j;k++){
//         int steps=f(i,k,dp,arr)+f(k+1,j,dp,arr)+arr[i]*arr[k+1]*arr[j+1];
//         mini=min(mini,steps);
//     }
//     dp[i][j]=mini;
//     return mini;
// }
// int matrixMultiplication(vector<int> &arr) {
//     // code here
//     int n=arr.size();
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     return f(0,n-2,dp,arr);
// }

//tabulation
int matrixMultiplication(vector<int> &arr) {
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n-1;j++){
            int mini=INT32_MAX;
            for(int k=i;k<j;k++){
                mini=min(mini,dp[i][k]+dp[k+1][j]+arr[i]*arr[j+1]*arr[k+1]);
            }
            dp[i][j]=mini;
        }
    }
    return dp[0][n-2];
}

