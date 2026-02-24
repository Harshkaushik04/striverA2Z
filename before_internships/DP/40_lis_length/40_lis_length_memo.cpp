#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> current(n+1,-1);
    for(int j=0;j<n;j++){
        if(nums[0]<nums[j]) current[j]=1;
        else current[j]=0;
    }
    current[n]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(nums[i]<nums[j]) current[j]=max(1+current[i],current[j]);
        }
        current[n]=max(1+current[i],current[n]);
    }
    return current[n];
}