#include<bits/stdc++.h>
using namespace std;
//not done
int maxCoins(vector<int>& nums)  {
    int n=nums.size();
    if(n==1) return nums[0];
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int mini=INT32_MAX;
    for(int i=0;i<n;i++) dp[i][i]=nums[i];
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
           //
        }
    }
    return dp[0][n-1];
}
