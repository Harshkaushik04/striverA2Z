#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,1);
    int totalMax=1,maxi;
    for(int i=1;i<n;i++){
        maxi=dp[i];
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                if(dp[j]+dp[i]>maxi) maxi=dp[i]+dp[j];
            } 
        }
        dp[i]=maxi;
        if(dp[i]>totalMax) totalMax=dp[i];
    }
    return totalMax;
}