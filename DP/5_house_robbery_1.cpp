#include<bits/stdc++.h>
using namespace std;

//optimal solution
int rob(vector<int>& nums) {
    int n=nums.size();
    int take,not_take;
    int prev=nums[0],prev2=0;
    for(int i=1;i<n;i++){
        take=nums[i]+prev2;
        not_take=prev;
        prev=max(take,not_take);
        prev2=not_take;
    }
    return prev;
}

// int f(vector<int>& nums,vector<int>& dp,int index){
//     if(index==0) return dp[index];
//     if(index<0) return 0;
//     int pick,not_pick;
//     if(dp[index-2]!=-1) pick=nums[index]+dp[index-2];
//     else pick=nums[index]+f(index-2);
//     if(dp[index-1]!=-1) not_pick=f(index-1);
//     else not_pick=nums[index-1];
//     dp[index]=max(pick,not_pick);
//     return dp[index];
// }