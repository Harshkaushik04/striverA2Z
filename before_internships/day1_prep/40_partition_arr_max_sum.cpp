#include<bits/stdc++.h>
using namespace std;

//O(n^3) method

//     int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
//     if(i==j) return arr[i];
//     if(i>j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int maxi=max(arr[i],arr[j]);
//     dp[i][j]=max(maxi,f(i+1,j-1,arr,dp));
//     return dp[i][j];
// }

// int f1(int i,int j,int k,vector<int>& arr,vector<vector<int>>& dp,vector<vector<int>>& computed_dp){
//     if(i>j) return 0;
//     if(i==j) return arr[i];
//     if(j-i+1<=k) return (j-i+1)*computed_dp[i][j];
//     if(dp[i][j]!=-1) return dp[i][j];
//     int maxi=0;
//     for(int m=i;m<j;m++){
//         maxi=max(maxi,f1(i,m,k,arr,dp,computed_dp)+f1(m+1,j,k,arr,dp,computed_dp));
//     }
//     dp[i][j]=maxi;
//     return dp[i][j];
// }

// int maxSumAfterPartitioning(vector<int>& arr, int k) {
//     int n=arr.size();
//     vector<vector<int>> computed_dp(n,vector<int>(n,-1));
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             f(i,j,arr,computed_dp);
//         }
//     }
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     return f1(0,n-1,k,arr,dp,computed_dp);
// }
int f(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
    if(i==j){
        dp[i][j]=arr[i];
        return dp[i][j];
    }
    if(i+1==j){
        dp[i][j]=max(arr[i],arr[j]);
        return dp[i][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi=max(arr[i],arr[j]);
    dp[i][j]=max(maxi,f(i+1,j-1,arr,dp));
    return dp[i][j];
}

int f1(int i,int k,vector<int>& arr,vector<int>& dp,vector<vector<int>>& computed_dp,int n){
    if(i==n) return 0;
    if(i==n-1) return arr[n-1];
    if(dp[i]!=-1) return dp[i];
    int maxi=0;
    for(int m=i;m<min(i+k,n);m++){
        maxi=max(maxi,(m-i+1)*computed_dp[i][m]+f1(m+1,k,arr,dp,computed_dp,n));
    }
    dp[i]=maxi;
    return dp[i];
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n=arr.size();
    vector<vector<int>> computed_dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            f(i,j,arr,computed_dp);
        }
    }
    vector<int> dp(n,-1);
    return f1(0,k,arr,dp,computed_dp,n);
}
