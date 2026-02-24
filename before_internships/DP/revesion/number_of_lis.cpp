#include<bits/stdc++.h>
using namespace std;

// int length_lis(vector<int>& nums){
//     vector<int> vec={nums[0]};
//     int n=nums.size();
//     int len=1;
//     for(int i=1;i<n;i++){
//         if(nums[len-1]<nums[i]){
//             vec.emplace_back(nums[i]);
//             len++;
//         }
//         else{
//             int index=lower_bound(vec.begin(),vec.end(),nums[i])-vec.begin();
//             vec[index]=nums[i];
//         }
//     }
//     return len;
// }

// int f(int i,int prev_index,vector<vector<int>>& dp,vector<int>& nums,int maxi,vector<int>& count){
//     if(i==-1) return 0;
//     if(dp[i][prev_index]!=-1) return dp[i][prev_index];
//     if(nums[i]<nums[prev_index]){
//         int take=1+f(i-1,i,dp,nums,maxi,count);
//         int not_take=f(i-1,prev_index,dp,nums,maxi,count);
//         dp[i][prev_index]=max(take,not_take);
//     }
//     else dp[i][prev_index]=f(i-1,prev_index,dp,nums,maxi,count);
//     if(dp[i][prev_index]==maxi) count++;
//     return dp[i][prev_index];
// }

// int findNumberOfLIS(vector<int>& nums) {
//     int count=0;
//     int maxi=length_lis(nums);
//     int n=nums.size();
//     nums.emplace_back(INT32_MAX);
//     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//     f(n-1,n,dp,nums,maxi,count);
//     return count;
// }