#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& nums, int goal) {
    vector<int> oddsArray;
    int j=0;
    int ans=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]%2==1) oddsArray.emplace_back(i);
        if(oddsArray.size()<goal) continue;
        else{
            j=oddsArray.size()-goal;
            ans+=(j+1);
        }
    } 
    return ans;  
}

int numberOfSubarrays(vector<int>& nums, int goal) {
    return f(nums,goal)-f(nums,goal+1);  
}