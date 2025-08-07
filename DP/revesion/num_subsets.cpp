#include<bits/stdc++.h>
using namespace std;

int f(int i,int target,vector<vector<int>>& dp,vector<int>& arr){
    if(i==-1) return 0;
    if(target==0) return 1;
    if(target<0) return 0;
    if(dp[i][target]!=INT32_MIN) return dp[i][target];
    dp[i][target]=f(i-1,target,dp,arr)+f(i-1,target-arr[i],dp,arr);
    return dp[i][target];
}

int perfectSum(vector<int>& arr, int target) {
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,INT32_MIN));
    return f(n-1,target,dp,arr);
}