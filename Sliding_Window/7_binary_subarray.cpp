#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return greaterOrEqual(nums,goal)-greaterOrEqual(nums,goal+1);  
}

int greaterOrEqual(vector<int>& nums,int goal){
    vector<int> onesArray;
    int j=0;
    int ans=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==1) onesArray.emplace_back(i);
        if(onesArray.size()<goal) continue;
        else{
            j=onesArray.size()-goal;
            ans+=(onesArray[j]+1);
        }
    } 
    return ans;  
}