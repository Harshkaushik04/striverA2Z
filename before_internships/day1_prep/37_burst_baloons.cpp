#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums){
    int n=nums.size();
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    vector<int> arr;
    arr.emplace_back(1);
    for(int val:nums) arr.emplace_back(val);
    arr.emplace_back(1);
    for(int i=0;i<n+1;i++){
        dp[i][i]=0;
        dp[i][i+1]=0;
    }
    dp[n+1][n+1]=0;
    for(int i=n;i>=0;i--){
        for(int j=i;j<n+2;j++){
            int maxi=INT32_MIN;
            for(int k=i+1;k<=j-1;k++){
                maxi=max(maxi,dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k]);
            }
            if(maxi!=INT32_MIN) dp[i][j]=maxi;
        }
    }
    return dp[0][n+1];
}