#include<bits/stdc++.h>
using namespace std;

//ineffecient method
//memoization 
// int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
//     if(i==j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int mini=INT32_MAX;
//     for(int value:arr){
//         if(value>i && value<j){
//             mini=min(mini,f(i,value,arr,dp)+f(value,j,arr,dp)+j-i);
//         }
//     }
//     if(mini==INT32_MAX) dp[i][j]=0;
//     else dp[i][j]=mini;
//     return dp[i][j];
// }

// int minCost(int n, vector<int>& cuts) {
//     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//     return f(0,n,cuts,dp);
// }

//ineffecient method
//tabulation
// int minCost(int n, vector<int>& cuts) {
//     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//     for(int i=0;i<n+1;i++) dp[i][i]=0;
//     for(int i=n-1;i>=0;i--){
//         for(int j=i+1;j<=n;j++){
//             int mini=INT32_MAX;
//             for(int value:cuts){
//                 if(value>i && value<j) mini=min(mini,dp[i][value]+dp[value][j]+j-i);
//             }
//             if(mini==INT32_MAX) mini=0;
//             dp[i][j]=mini;
//         }
//     }
//     return dp[0][n];
// }

//memoization
// int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
//     if(i==j || i+1==j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int mini=INT32_MAX;
//     for(int k=i+1;k<=j-1;k++){
//         mini=min(mini,f(i,k,arr,dp)+f(k,j,arr,dp)+arr[j]-arr[i]);
//     }
//     if(mini==INT32_MAX) mini=0;
//     dp[i][j]=mini;
//     return dp[i][j];
// }

// int minCost(int n, vector<int>& cuts) {
//     int m=cuts.size();
//     sort(cuts.begin(),cuts.end());
//     vector<int> arr;
//     arr.emplace_back(0);
//     for(int val:cuts) arr.emplace_back(val);
//     arr.emplace_back(n);
//     vector<vector<int>> dp(m+2,vector<int>(m+2,-1));
//     return f(0,m+1,arr,dp);
// }

//tabulation
int minCost(int n, vector<int>& cuts){
    int m=cuts.size();
    sort(cuts.begin(),cuts.end());
    vector<int> arr;
    arr.emplace_back(0);
    for(int val:cuts) arr.emplace_back(val);
    arr.emplace_back(n);
    vector<vector<int>> dp(m+2,vector<int>(m+2,0));
    for(int i=m+1;i>=0;i--){
        for(int j=i+1;j<m+2;j++){
            int mini=INT32_MAX;
            for(int k=i+1;k<=j-1;k++){
                mini=min(mini,dp[i][k]+dp[k][j]+arr[j]-arr[i]);
            }
            if(mini!=INT32_MAX) dp[i][j]=mini;
        }
    }
    return dp[0][m+1];
}