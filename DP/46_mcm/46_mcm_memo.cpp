#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>>& dp,vector<int>& arr){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT32_MAX;
    for(int k=i;k<j;k++){
        mini=min(mini,arr[i-1]*arr[k]*arr[j]+f(i,k,dp,arr)+f(k+1,j,dp,arr));
    }
    dp[i][j]=mini;
    return dp[i][j];
}

int matrixMultiplication(vector<int> &arr) {
    // code here
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(1,n-1,dp,arr);
}