#include<bits/stdc++.h>
#include <cstdint>
using namespace std;

int main(){
    return 0;
}

int f(int i,int target,vector<int>& dp,vector<int>& nums,int n){
    if(i==n-1) return 0;
    if(dp[i]!=-2) return dp[i];
    int maxi=INT32_MIN;
    for(int j=i+1;j<n;j++){
        if(abs(nums[j]-nums[i])<=target){
            int further=f(j,target,dp,nums,n);
            if(further==-1) continue;
            maxi=max(maxi,further+1);
        }
    }
    if(maxi==INT32_MIN) dp[i]=-1;
    else dp[i]=maxi;
    return dp[i];
}

int maximumJumps(vector<int>& nums, int target) {
    int n=nums.size();
    vector<int> dp(n,-2);
    return f(0,target,dp,nums,n);
}