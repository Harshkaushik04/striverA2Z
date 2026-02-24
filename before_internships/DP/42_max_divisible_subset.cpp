#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    pair<int,int> p=make_pair(1,-1); //length,backtracking_index
    vector<pair<int,int>> dp(n,p); 
    int totalMax=1,totalMaxIndex=0;
    int maxi=1,temp=0;
    for(int i=1;i<n;i++){
        maxi=1;
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && maxi<dp[j].first+1){
                maxi=dp[j].first+1;
                temp=j;
            }
        }
        if(maxi>1){
            dp[i].first=maxi;
            dp[i].second=temp;
        }
        if(totalMax<maxi){
            totalMax=maxi;
            totalMaxIndex=temp;
        }
    }       
    vector<int> ans;
    temp=totalMaxIndex;
    while(dp[temp].second!=-1){
        ans.emplace_back(nums[temp]);
        temp=dp[temp].second;
    }
    ans.emplace_back(nums[temp]);
    reverse(ans.begin(),ans.end());
    return ans;
}